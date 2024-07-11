#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Base_init")
{
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    try
    {
        tryGrade(grade);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
    this->_grade = other.getGrade(); 
    return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other.getGrade();
        return *this;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    return ;
}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::higherGrade()
{
    if ((this->_grade - 1) < 1)
        throw GradeTooHighException();
    else
        this->_grade -= 1;
}

void Bureaucrat::lowerGrade()
{
    if ((this->_grade + 1) > 150)
        throw GradeTooLowException();
    else
        this->_grade += 1;
}

std::ostream &operator<<(std::ostream & os, const Bureaucrat & other)
{
    os << "Name " << other.getName() << ", bureaucrat grade is " << other.getGrade();
    return (os);
}

void Bureaucrat::tryGrade(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        this->_grade = grade;
}

void    Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}

void    Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}