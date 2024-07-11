#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include <unistd.h>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

// class PresidentialPardonForm : virtual public AForm
class PresidentialPardonForm : public AForm
{
    private :
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExec;
        std::string         _target;
        PresidentialPardonForm();
    
    public :
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
        PresidentialPardonForm & operator =(const PresidentialPardonForm &other);

        std::string         getTarget() const;
        void                beSigned(Bureaucrat const &check);
        void                execute(const Bureaucrat &executor) const;
};

#endif