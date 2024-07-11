#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <unistd.h>

class Bureaucrat;

class Form
{
    private :
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExec;
        Form();

    public :
        Form(std::string name, int sign, int exec);
        Form(const Form &other);
        ~Form();
        Form & operator =(const Form &other);

        std::string const   getName() const;
        int                 getGrade() const;
        int                 getExec() const;

        // void                higherGrade();
        // void                lowerGrade();
        void                tryGrade(int grade);
        void                beSigned(Bureaucrat &check);
        void                beExec(Bureaucrat &check);


        class NotRightGradeToExecute : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return("Error : You can't access this form, you're fired\n");
                }
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return("Error : Form grade was too high\n");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return("Error : Form grade was too low\n");
                }
        };
};

std::ostream & operator <<(std::ostream & os, const Form & other);

#endif