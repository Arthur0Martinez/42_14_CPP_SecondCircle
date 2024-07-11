#ifndef BASE_CPP
# define BASE_CPP

# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{
    private:

    public:
        Base();
        virtual ~Base() = 0;
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif