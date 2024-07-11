#include "easyfind.hpp"

int main()
{
    std::list<int>      lst;
    std::vector<int>    vcr;

    lst.push_back(4);
    lst.push_back(532);
    lst.push_back(1);
    lst.push_back(78);
    lst.push_back(0);

    vcr.push_back(4);
    vcr.push_back(532);
    vcr.push_back(1);
    vcr.push_back(78);
    vcr.push_back(0);

    easyfind(lst, 1);
    easyfind(vcr, 532);
    easyfind(lst, 25);

    return(0);
}