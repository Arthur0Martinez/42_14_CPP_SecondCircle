#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 5, 25), _name("PF"), _signed(false), _gradeSign(25), _gradeExec(5)
{
    return ;
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 5, 25), _name("PF"), _signed(false), _gradeSign(25), _gradeExec(5), _target(target)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PresidentialPardonForm", 5, 25), _name(other.getName()), _gradeSign(25), _gradeExec(5), _target(other.getTarget())
{
    this->_signed = other._signed; 
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
        return *this;
    }
    return *this;
}

std::string   PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

void    PresidentialPardonForm::beSigned(Bureaucrat const &check)
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

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{

    if (this->_gradeExec >= executor.getGrade())
    {
        if (this->_signed != true)
        {
            std::cout << executor.getName() << " couldn't execute " << this->getName() << " because" << " it wasn't signed." << std::endl;
        }
        else
        {
            std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;        
        }
    }
    else
    {
        std::cout << executor.getName() << " couldn't execute " << this->getName() << " because " << "his grade was too low." << std::endl; 
        throw AForm::NotRightGradeToExecute();
    }
}