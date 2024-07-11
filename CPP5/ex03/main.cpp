#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <string>
#include <iostream>

int main()
{

    Bureaucrat Mid("Mid", 75);
    Bureaucrat High("High", 4);
    Bureaucrat Low("Low", 143);
    PresidentialPardonForm  fileA("Traitor");
    ShrubberyCreationForm   fileB("ASCII_tree");
    RobotomyRequestForm     fileC("Robotomy_test");
    Intern someRandomIntern;
    AForm* rrf;
    try
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        High.signForm(*rrf);
        High.executeForm(*rrf);
        for (int i = 0 ; i < 3 ; i++)
        {
            Low.lowerGrade();
            std::cout << "Grade for " << Low.getName() << " is " << Low.getGrade() << std::endl;
            std::cout << Low << std::endl;
        }
        for (int i = 0 ; i < 3 ; i++)
        {
            High.higherGrade();
            High.executeForm(fileA);
            High.signForm(fileA);
            High.executeForm(fileA);
            High.signForm(fileB);
            High.executeForm(fileB);
            High.signForm(fileC);
            High.executeForm(fileC);
            fileA.execute(High);
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