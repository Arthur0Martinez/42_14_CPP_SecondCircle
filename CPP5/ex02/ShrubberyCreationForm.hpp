#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include <unistd.h>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

// class ShrubberyCreationForm : virtual public AForm
class ShrubberyCreationForm : public AForm
{
    private :
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExec;
        std::string         _target;
    
    public :
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm & operator =(const ShrubberyCreationForm &other);

        std::string         getTarget() const;
        void                beSigned(Bureaucrat const &check);
        void                execute(const Bureaucrat &executor) const;
        void                executeShrubberyCreationForm() const;
};

#endif