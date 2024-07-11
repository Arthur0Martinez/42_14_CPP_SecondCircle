#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

int main()
{

    Bureaucrat Mid("Mid", 75);
    Bureaucrat High("High", 4);
    Bureaucrat Low("Low", 145);
    
    try
    {
        for (int i = 0 ; i < 3 ; i++)
        {
            Low.lowerGrade();
            std::cout << "Grade for " << Low.getName() << " is " << Low.getGrade() << std::endl;
            std::cout << Low << std::endl;
        }
        for (int i = 0 ; i < 3 ; i++)
        {
            High.higherGrade();
            std::cout << "Grade for " << High.getName() << " is " << High.getGrade() << std::endl;
            std::cout << High << std::endl;
        }
        for (int i = 0 ; i < 100 ; i++)
        {
            if (i % 3 == 0)
                Mid.higherGrade();
            else
                Mid.lowerGrade();
        }
        std::cout << "Grade for " << Mid.getName() << " is " << Mid.getGrade() << std::endl;
        std::cout << Mid << std::endl;

        Bureaucrat Out("Out", 253);
        Out.lowerGrade();
    }   
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "End of main function" << std::endl;
    return (0);
}