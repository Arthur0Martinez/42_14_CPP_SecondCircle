#include "Intern.hpp"
#include "Bureaucrat.hpp"

Intern::Intern()
{
    return ;
}

Intern::Intern(const Intern &other)
{
    (void) other;
    return ;
}

Intern &Intern::operator=(const Intern &other)
{
    (void) other;
    return *this;
}

Intern::~Intern()
{
    return ;
}

AForm*   Intern::makeRobotomy(std::string targetName)
{
    return (new RobotomyRequestForm(targetName));
}

AForm*   Intern::makePresidential(std::string targetName)
{
    return (new PresidentialPardonForm(targetName));
}

AForm*   Intern::makeShrubbery(std::string targetName)
{
    return (new ShrubberyCreationForm(targetName));
}

AForm*   Intern::makeForm(std::string formName, std::string targetName)
{
    // int levelIndex = -1;
    // std::string R[] = {"RobotomyRequest", "Robotomy Request", "robotomyrequest", "robotomy request", "Robotomy", "robotomy", "Request", "request"};
    // std::string P[] = {"PresidentialPardon", "Presidential Pardon", "presidentialpardon", "presidential pardon", "Presidential", "presidential", "Pardon", "pardon"};
    // std::string S[] = {"ShrubberyCreation", "Shrubbery Creation", "shrubberycreation", "shrubbery creation", "Shrubbery", "shrubbery", "Creation", "creation"};

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         if (formName == R[j])
    //         {
    //             levelIndex = 0;
    //             break ;
    //         }
    //         else if(formName == P[j])
    //         {
    //             levelIndex = 1;
    //             break ;
    //         }
    //         else if(formName == S[j])
    //         {
    //             levelIndex = 2;
    //             break ;
    //         }
    //     }
    // }

    int levelIndex = -1;
    AForm* (Intern::*allMake[])(std::string) = {&Intern::makeRobotomy, &Intern::makePresidential, &Intern::makeShrubbery};
    std::string levels[] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    for (int i = 0; i < 3; i++)
    {
        if (formName == levels[i])
        {
            levelIndex = i;
            break ;
        }
    }

    switch(levelIndex)
    {
        case 0:
            std::cout << "Intern creates RobotomyRequestForm named " << targetName << std::endl;
            return ((this->*allMake[0])(targetName));
        case 1:
            std::cout << "Intern creates PresidentialPardonForm named " << targetName << std::endl;
            return ((this->*allMake[1])(targetName));
        case 2:
            std::cout << "Intern creates ShrubberyCreationForm named " << targetName << std::endl;
            return ((this->*allMake[2])(targetName));
        default:
            throw UnknownForm();
            break ;
    }
}