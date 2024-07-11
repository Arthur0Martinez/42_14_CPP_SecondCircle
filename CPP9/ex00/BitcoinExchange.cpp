#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _fileName("base.txt") {}

BitcoinExchange::BitcoinExchange(std::string file) : _fileName(file) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _fileName(other._fileName) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange &other)
{
    this->_fileName = other.getFileName();
    return *this;
}

char    getSplitter(std::string line)
{
    char c;
    size_t pos;
    std::string str = line;
    remove(str.begin(), str.end(), ' ');
    pos = str.find("date");
    c = str[pos + 4];
    return (c);
}

int    BitcoinExchange::getDataMap(bool a, char *str)
{
    std::ifstream file(str);
    std::string line;
    std::multimap<std::string, float> map;
    size_t count_line = 0;
    char spliter;
    if (file.is_open())
    {
        while(std::getline(file, line))
        {
            count_line++;
            remove(line.begin(), line.end(), ' ');
            if (count_line == 1)
                spliter = getSplitter(line);
            size_t pos = line.find(spliter);
            std::string key = line.substr(0, pos);
            std::string valueStr = line.substr(pos + 1);
            float value = std::atof(valueStr.c_str());
            map.insert(std::pair<std::string, float>(key, value));
        }
        file.close();
    }
    else
        throw std::runtime_error("Error : Couldn't open file.");
    if (a == 0)
        this->_dataMap = map;
    else
        this->_inputData = map;
    return(count_line);
}

std::string*    BitcoinExchange::compareMap(int a)
{
    std::string *str = new std::string[a];
    int b = 0;
    std::multimap<std::string, float>::iterator it;
    std::multimap<std::string, float>::iterator itData = this->_inputData.end();
    itData--;
    for (it = this->_inputData.begin(); it != itData; ++it)
    {
        std::ostringstream oss;
        std::multimap<std::string, float>::const_iterator temp;
        temp = this->_dataMap.upper_bound(it->first);

        if (temp != _dataMap.begin())
        {
            --temp;
            if (checkError(it) != 0)
                oss << getError(checkError(it), it->first);
            else
                oss << it->first << " => " << it->second << " = " << (temp->second * it->second);
            str[b] = oss.str();
        }
        else
        {
            oss << "Error : Bad input => " << it->first;
            str[b] = oss.str();
        }
        b++;
    }
    return (str);
}

bool  checkDateError(std::string date)
{
    std::istringstream iss(date);
    std::string tokens[3];
    std::string token;
    int nbr = 0; 

    while (std::getline(iss, token, '-') && nbr < 3)
    {
        tokens[nbr] = token;
        nbr++;
    }
    if (!(atoi(tokens[0].c_str()) >= 2008 && atoi(tokens[0].c_str()) <= 2024))
        return(false);
    if (!(atoi(tokens[1].c_str()) >= 1 && atoi(tokens[1].c_str()) <= 12))
        return(false);
    if (!(atoi(tokens[2].c_str()) >= 1 && atoi(tokens[2].c_str()) <= 31))
        return(false);
    return(true);
}

int    BitcoinExchange::checkError(std::multimap<std::string, float>::const_iterator temp)
{
    if (temp->second < 0)
        return (1);
    if (temp->second > 1000)
        return (2);
    if (!(checkDateError(temp->first)))
        return (3);
    return (0);
}

std::string    BitcoinExchange::getError(int error, std::string date)
{
    switch(error)
    {
        case 1:
            return("Error : Not a positive number.");
            break ;
        case 2:
            return("Error : Too large a number.");
            break ;
        case 3:
            std::ostringstream errorstr;
            errorstr << "Error : Bad input => " << date;
            return(errorstr.str());
            break ;
    }
    return("Error : Undefined error.");

}

std::string BitcoinExchange::getFileName() const
{
    return (this->_fileName);
}
