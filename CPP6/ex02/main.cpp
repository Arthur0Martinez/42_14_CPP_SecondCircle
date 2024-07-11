#include "Base.hpp"

int main()
{
    Base *random_child;
    
    random_child = generate();
    identify(random_child);
    identify(*random_child);
    random_child = generate();
    identify(random_child);
    identify(*random_child);
    delete random_child;
    return (0);
}