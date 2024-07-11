#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Base"), _gradeSign(1), _gradeExec(1) 
{
    return ;
}

Form::Form(std::string name, int sign, int exec) : _name(name), _gradeSign(sign), _gradeExec(exec) 
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

Form::Form(const Form &other) : _name(other.getName()), _gradeSign(other.getGrade()), _gradeExec(other.getExec())
{
    this->_signed = other._signed; 
    return ;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
        return *this;
    }
    return *this;
}

Form::~Form()
{
    return ;
}

const std::string Form::getName() const
{
    return this->_name;
}

int Form::getGrade() const
{
    return this->_gradeSign;
}

int Form::getExec() const
{
    return this->_gradeExec;
}

// void Form::higherGrade()
// {
//     if ((this->_gradeSign - 1) < 1)
//         throw GradeTooHighException();
//     else
//         this->_gradeSign -= 1;
// }

// void Form::lowerGrade()
// {
//     if ((this->_gradeSign + 1) > 150)
//         throw GradeTooLowException();
//     else
//         this->_gradeSign += 1;
// }

std::ostream &operator<<(std::ostream & os, const Form & other)
{
    os << "Name " << other.getName() << ", Form grade is " << other.getGrade();
    return (os);
}

void Form::tryGrade(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        return ;
}

void    Form::beSigned(Bureaucrat &check)
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
        throw Form::GradeTooLowException();
    }
}

void    Form::beExec(Bureaucrat &check)
{
    if (this->_gradeSign > check.getGrade())
    {
        if (this->_signed != true)
        {
            std::cout << check.getName() << " couldn't execute " << this->getName() << " because " << " it wasn't signed." << std::endl;
            std::cout << "Trying to sign..." << std::endl;
            sleep(3);
            this->beSigned(check);
        }
        else
        {
            std::cout << check.getName() << " excuted " << this->getName() << "." << std::endl;        
        }
    }
    else
    {
        std::cout << check.getName() << " couldn't execute " << this->getName() << " because " << "his grade was too low." << std::endl; 
        throw Form::NotRightGradeToExecute();
    }
}