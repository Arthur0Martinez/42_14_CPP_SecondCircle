#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        
        Span sp2 = Span(5);
        sp2.createList(5);
        std::cout << "\nsp\n" << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;

        Span sp3 = Span(8);
        sp3.createList(5);
        std::cout << "\nsp\n" << sp3.shortestSpan() << std::endl;
        std::cout << sp3.longestSpan() << std::endl;

        Span sp4 = Span(6);
        sp4.createList(6);
        std::cout << "\nsp\n" << sp4.shortestSpan() << std::endl;
        std::cout << sp4.longestSpan() << std::endl;

        Span sp5 = Span(99999);
        sp5.createList(90000);
        std::cout << "\nsp\n" << sp5.shortestSpan() << std::endl;
        std::cout << sp5.longestSpan() << std::endl;
    }
    catch(std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}