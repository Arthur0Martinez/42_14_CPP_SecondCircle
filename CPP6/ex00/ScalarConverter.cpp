#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    return ;
}

bool ScalarConverter::get_char(std::string str)
{
    if (str.length() != 1)
        return (false);
    else if (str[0] > std::numeric_limits<char>::max() || str[0] < std::numeric_limits<char>::min() || isdigit(str[0]))
        return (false);
    else
        return (true);
}

bool ScalarConverter::get_int(std::string str)
{
    int i = 0;
    if (str[i] == '-' && str[i + 1])
        i++;
    while(str[i])
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool ScalarConverter::get_float(std::string str)
{
	unsigned long int 	i = 0;
	bool				pointFound = false;

    if (str.length() < 2)
		return (false);
	if (str[str.length() - 1] != 'f')
		return (false);
	if (str[i] == '-' && str[i + 1])
		i++;
	while (i < str.length() - 1)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.' && pointFound == false)
				pointFound = true;
			else
				return (false);
		}
		i++;
	}
	if (pointFound == false || str[str.length() - 2] == '.')
		return (false);
	return (true);
}

bool ScalarConverter::get_double(std::string str)
{
	unsigned long int 	i = 0;
	bool				pointFound = false;
	if (str.length() < 2)
		return (false);
	if (str[str.length() - 1] == 'f')
		return (false);
	if (str[i] == '-' && str[i + 1])
		i++;
	while (i < str.length())
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.' && pointFound == false)
				pointFound = true;
			else
				return (false);
		}
		i++;
	}
	if (pointFound == false || str[str.length() - 1] == '.')
		return (false);
	return (true);
}

bool ScalarConverter::get_special(std::string str)
{
	return ((str == "-inf") || (str == "+inf") || (str == "nan") ||
		    (str == "-inff") || (str == "+inff") || (str == "nanf"));
}

int ScalarConverter::get_type(std::string str)
{
    if (get_char(str))
        return(0);
    if (get_int(str) || get_float(str) || get_double(str))
        return(1);  
    if (get_special(str))
        return(2);
    return (-1);
}

double ScalarConverter::convertToDouble(std::string str)
{
	double newDouble;
	std::istringstream iss(str);
	iss >> newDouble;
	return (newDouble);
}

void	ScalarConverter::handleChar(double litteralDouble)
{
	if (litteralDouble > 31 && litteralDouble < 127)
		std::cout << "char : " << static_cast<char>(litteralDouble) << std::endl;
	else if  (litteralDouble < 0 || litteralDouble > 128)
		std::cout << "char : " << "Impossible" << std::endl;
	else
		std::cout << "char : " << "Non displayable" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    int type = get_type(str);
    double convert = convertToDouble(str);
    switch(type)
{
        case(0):
            std::cout << "char: " << str[0] << std::endl;
            std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
            std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
            std::cout << "double : " << static_cast<double>(str[0]) << std::endl;
            break ;
        case(1):
            handleChar(convert);
            std::cout << "int: " << static_cast<int>(convert) << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(convert) << "f" << std::endl;
            std::cout << "double : " << std::fixed << std::setprecision(1) << convert << std::endl;
            break ;
        case(2):
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << static_cast<float>(convert) << std::endl;
            std::cout << "double : " << str << std::endl;
            break ;
        default:
            std::cout << "Couldn't handle string typed" << std::endl;
            break ;
}
}
