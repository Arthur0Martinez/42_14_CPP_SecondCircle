#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

int main()
{

    Bureaucrat Mid("Mid", 75);
    Bureaucrat High("High", 4);
    Bureaucrat Low("Low", 145);
    Form fileA("fileA", 140, 140);
    
    try
    {
        for (int i = 0 ; i < 3 ; i++)
        {
            Low.lowerGrade();
            //Low.signForm(fileA);
            std::cout << "Grade for " << Low.getName() << " is " << Low.getGrade() << std::endl;
            std::cout << Low << std::endl;
        }
        for (int i = 0 ; i < 3 ; i++)
        {
            High.higherGrade();
            High.signForm(fileA);
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
        Mid.signForm(fileA);
        Mid.execForm(fileA);
        Low.execForm(fileA);
        Low.signForm(fileA);

        Bureaucrat Out("Out", 253);
        std::cout << "Does it goes here ?" << std::endl;
    }   
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "End of main function" << std::endl;
    return (0);
}