#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
    std::cout << "Base class is called" << std::endl;
}

Base::~Base()
{
    return ;
}

Base * generate(void)
{

    srand(time(NULL));
    int randNum = (rand() % 3) + 1;
    switch(randNum)
    {
        case(1):
            return(new A());
        case(2):
            return(new B());
        case(3):
            return(new C());
        default:
            break ;
    }
    return(new A());
}

void identify(Base* p)
{
    if (A* a = dynamic_cast<A*>(p))
        std::cout << "Adress of Base is identified as A" << std::endl;
    else if (B* b = dynamic_cast<B*>(p))
        std::cout << "Adress of Base is identified as B" << std::endl;
    else if (C* c = dynamic_cast<C*>(p))
        std::cout << "Adress of Base is identified as C" << std::endl;
    else
        std::cout << "Not a known type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Reference of Base is identified as A" << std::endl;
        return ;
    }
    catch(...)
    {

    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Reference of Base is identified as B" << std::endl;
        return ;
    }
    catch(...)
    {
        
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Reference of Base is identified as C" << std::endl;
        return ;
    }
    catch(...)
    {
        
    }
}
