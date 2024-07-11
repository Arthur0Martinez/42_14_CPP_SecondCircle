#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <climits>
# include <limits>
# include <string>
# include <sstream>
# include <iomanip>
# include <fstream>

class ScalarConverter
{
    private:
        ScalarConverter();
        virtual ~ScalarConverter() = 0;
    public:
        static bool        get_char(std::string str);
        static bool        get_int(std::string str);
        static bool        get_float(std::string str);
        static bool        get_double(std::string str);
        static bool        get_special(std::string str);
        static void        handleChar(double litteralDouble);

        static int      get_type(std::string str);
        static double   convertToDouble(std::string nbr);
        static void     convert(std::string str);

    class ScalarConverterException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return("Error : A convertion has failed\n");
            }
    };
};

#endif