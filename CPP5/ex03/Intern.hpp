#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include <vector>
# include <unistd.h>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    private :
        AForm*   makeRobotomy(std::string targetName);
        AForm*   makePresidential(std::string targetName);
        AForm*   makeShrubbery(std::string targetName);

    public :
        Intern();
        Intern(const Intern &other);
        ~Intern();

        Intern & operator =(const Intern &other);

        AForm*   makeForm(std::string formName, std::string targetName);
        class UnknownForm : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return("Error : Form doesn't exist\n");
                }
        };
};


#endif