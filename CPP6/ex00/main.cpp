# include "ScalarConverter.hpp"

int main()
{
    try
    {
        std::cout << std::endl;
        std::cout << "32" << std::endl << std::endl;
        ScalarConverter::convert("32");
        std::cout << std::endl;
        std::cout << "c" << std::endl << std::endl;
        ScalarConverter::convert("c");
        std::cout << std::endl;
        std::cout << "test" << std::endl << std::endl;
        ScalarConverter::convert("test");
        std::cout << std::endl;
        std::cout << "-2147483648" << std::endl << std::endl;
        ScalarConverter::convert("-2147483648");
        std::cout << std::endl;
        std::cout << "2147483647" << std::endl << std::endl;
        ScalarConverter::convert("2147483647");
        std::cout << std::endl;
        std::cout << "-1" << std::endl << std::endl;
        ScalarConverter::convert("-1");
        std::cout << std::endl;
        std::cout << "0" << std::endl << std::endl;
        ScalarConverter::convert("0");
        std::cout << std::endl;
        std::cout << "-inf" << std::endl << std::endl;
        ScalarConverter::convert("-inf");
        std::cout << std::endl;
        std::cout << "-999999999999999999999999999999999999999" << std::endl << std::endl;
        ScalarConverter::convert("-999999999999999999999999999999999999999");
        std::cout << std::endl;
        std::cout << "124" << std::endl << std::endl;
        ScalarConverter::convert("124");
        std::cout << std::endl;
        std::cout << "45" << std::endl << std::endl;
        ScalarConverter::convert("45");
        std::cout << std::endl;
        std::cout << "21.1" << std::endl << std::endl;
        ScalarConverter::convert("21.1");
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}