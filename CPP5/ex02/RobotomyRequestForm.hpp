#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

// class RobotomyRequestForm : virtual public AForm
class RobotomyRequestForm : public AForm
{
    private :
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExec;
        std::string         _target;
    
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm & operator =(const RobotomyRequestForm &other);

        std::string         getTarget() const;
        void                beSigned(Bureaucrat const &check);
        void                execute(const Bureaucrat &executor) const;
};

#endif