#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 137, 145), _name("SF"), _signed(false), _gradeSign(145), _gradeExec(137)
{
    return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 137, 145), _name("SF"), _signed(false), _gradeSign(145), _gradeExec(137), _target(target)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 137, 145), _name(other.getName()), _gradeSign(145), _gradeExec(137), _target(other.getTarget())
{
    this->_signed = other._signed; 
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
        return *this;
    }
    return *this;
}

std::string   ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

void    ShrubberyCreationForm::beSigned(Bureaucrat const &check)
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

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{

    if (this->_gradeExec >= executor.getGrade())
    {
        if (this->_signed != true)
        {
            std::cout << executor.getName() << " couldn't execute " << this->getName() << " because it wasn't signed." << std::endl;
        }
        else
        {
            this->executeShrubberyCreationForm();
            std::cout << "File created and accesible on this" << this->getTarget() << " path." << std::endl;        
        }
    }
    else
    {
        std::cout << executor.getName() << " couldn't execute " << this->getName() << " because " << "his grade was too low." << std::endl; 
        throw AForm::NotRightGradeToExecute();
    }
}

void    ShrubberyCreationForm::executeShrubberyCreationForm() const
{
    std::string     str = this->getTarget() + "_shrubbery";
    std::ofstream   outputFile(str.c_str());
    std::string     littleTree = "     *     \n    ***    \n   *****   \n ******** \n****||****\n    ||    \n    ||    \n";

    if (!outputFile)
    {
        std::cerr << "Error : Could not open and write on file" << std::endl;
        return ;
    }
    outputFile << littleTree << std::endl;
    outputFile.close();
}