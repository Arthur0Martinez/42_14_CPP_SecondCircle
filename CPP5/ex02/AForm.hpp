#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <unistd.h>

class Bureaucrat;

class AForm
{
    private :
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExec;
        AForm();

    public :
        AForm(std::string name, int sign, int exec);
        AForm(const AForm &other);
        virtual ~AForm();
        AForm & operator =(const AForm &other);

        std::string const       getName() const;
        int                     getGrade() const;
        int                     getExec() const;
        bool                    getSigned() const;

        // void                higherGrade();
        // void                lowerGrade();
        void                    tryGrade(int grade);
        virtual void            beSigned(Bureaucrat const &check) = 0;
        virtual void            execute(Bureaucrat const &executor) const = 0;


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

std::ostream & operator <<(std::ostream & os, const AForm & other);

#endif