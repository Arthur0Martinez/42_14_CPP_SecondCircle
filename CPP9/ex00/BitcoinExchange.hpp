#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <stdexcept>
# include <algorithm>
# include <sstream>
# include <iomanip>


class BitcoinExchange
{
    private:
        std::string                   _fileName;
        std::multimap<std::string, float>  _dataMap;
        std::multimap<std::string, float>  _inputData;

    public:
        BitcoinExchange();
        BitcoinExchange(std::string file);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange operator=(const BitcoinExchange &other);
        
        
        std::string getFileName() const;
        // std::multimap    getDataMap();
        // std::multimap    getInputData();
        int             getDataMap(bool a, char *str);
        std::string*     compareMap(int a);
        int            checkError(std::multimap<std::string, float>::const_iterator temp);
        std::string     getError(int error, std::string date);
};

#endif