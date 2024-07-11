#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::invalid_argument("No arguments in parameter");
        PmergeMe calc(argv); // Faire dans constructeur 2 container avec les valeurs de argv
        
        std::list<int> temp = calc.getMyList();
        std::cout << "Before : ";
        for(std::list<int>::iterator it = temp.begin(); it != temp.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        clock_t Start = clock();
        calc.calculation_l();
        clock_t End = clock();

        clock_t Start2 = clock();
        calc.calculation_v();
        clock_t End2 = clock();

        std::cout << "After : ";
        std::list<int> temp2 = calc.getMyList();
        for(std::list<int>::iterator it = temp2.begin(); it != temp2.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "Time to process a range of " << argc - 1 << " elements with std::lst : " << End - Start << " us" << std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << End2 - Start2 << " us" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}