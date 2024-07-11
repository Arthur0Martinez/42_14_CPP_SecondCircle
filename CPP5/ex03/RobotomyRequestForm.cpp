#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 5, 25), _name("RF"), _signed(false), _gradeSign(25), _gradeExec(5)
{
    return ;
}


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 5, 25), _name("RF"), _signed(false), _gradeSign(25), _gradeExec(5), _target(target)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 5, 25), _name(other.getName()), _gradeSign(25), _gradeExec(5), _target(other.getTarget())
{
    this->_signed = other._signed; 
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
        return *this;
    }
    return *this;
}

std::string   RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

void    RobotomyRequestForm::beSigned(Bureaucrat const &check)
{
    if (this->_gradeSign > check.getGrade())
    {
        if (this->_signed == true)
            std::cout << check.getName() << " couldn't sign " << this->getName() << " because " << " it was already signed." << std::endl;
        else
        {
            this->_signed = true;
            std::cout << check.getName() << " signed " << this->getName() << "." << std::endl;        
        }
    }
    else
    {
        std::cout << check.getName() << " couldn't sign " << this->getName() << " because " << "is grade was too low." << std::endl; 
        throw AForm::NotRightGradeToExecute();
    }
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    std::srand(std::time(0));
    int random = std::rand() % 2;

    if (this->_gradeExec >= executor.getGrade())
    {
        if (this->_signed != true)
        {
            std::cout << executor.getName() << " couldn't execute " << this->getName() << " because it wasn't signed." << std::endl;
        }
        else
        {
            if (random == 0)
            {
                std::cout << "Yes ! " << this->getTarget() << " has been robotomized." << std::endl;
            }
            else
            {
                std::cout << "No ! " << this->getTarget() << " has not been robotomized." << std::endl;
            }   
        }
    }
    else
    {
        std::cout << executor.getName() << " couldn't execute " << this->getName() << " because " << "his grade was too low." << std::endl; 
        throw AForm::NotRightGradeToExecute();
    }
}