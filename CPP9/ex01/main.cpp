#include "RPN.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
            throw std::invalid_argument("No arguments in parameter");
        RPN calc(argv[1]);
        calc.calculation();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}