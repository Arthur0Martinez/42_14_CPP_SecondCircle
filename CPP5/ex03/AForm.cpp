#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Base"), _gradeSign(0), _gradeExec(0) 
{
    return ;
}

AForm::AForm(std::string name, int sign, int exec) : _name(name), _gradeSign(sign), _gradeExec(exec) 
{
    try
    {
        tryGrade(sign);
        tryGrade(exec);
        this->_signed = false;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

AForm::AForm(const AForm &other) : _name(other.getName()), _gradeSign(other.getGrade()), _gradeExec(other.getExec())
{
    this->_signed = other._signed; 
    return ;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
        return *this;
    }
    return *this;
}

AForm::~AForm()
{
    return ;
}

const std::string AForm::getName() const
{
    return this->_name;
}

int AForm::getGrade() const
{
    return this->_gradeSign;
}

int AForm::getExec() const
{
    return this->_gradeExec;
}

bool AForm::getSigned() const
{
    return this->_signed;
}

// void AForm::higherGrade()
// {
//     if ((this->_gradeSign - 1) < 1)
//         throw GradeTooHighException();
//     else
//         this->_gradeSign -= 1;
// }

// void AForm::lowerGrade()
// {
//     if ((this->_gradeSign + 1) > 150)
//         throw GradeTooLowException();
//     else
//         this->_gradeSign += 1;
// }

std::ostream &operator<<(std::ostream & os, const AForm & other)
{
    os << "Name " << other.getName() << ", AForm grade is " << other.getGrade();
    return (os);
}

void AForm::tryGrade(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        return ;
}

