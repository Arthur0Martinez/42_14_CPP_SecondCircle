#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <string>
# include <iostream>

class Bureaucrat
{
    private :
        const std::string    _name;
        int                 _grade;
        Bureaucrat();

    public :
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat();
        Bureaucrat & operator =(const Bureaucrat &other);

        std::string const   getName() const;
        int                 getGrade() const;

        void                higherGrade();
        void                lowerGrade();
        void                tryGrade(int grade);
        void                signForm(Form &form);
        void                execForm(Form &form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return("Error : Grade was too high\n");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return("Error : Grade was too low\n");
                }
        };
};

std::ostream & operator <<(std::ostream & os, const Bureaucrat & other);

#endif