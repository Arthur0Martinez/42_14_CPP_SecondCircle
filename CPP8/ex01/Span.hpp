#ifndef SPAN_HPP
# define SPAN_HPP

# include <limits>
# include <vector>
# include <iostream>
# include <algorithm>
# include <unistd.h>

class Span
{
    private:
        std::vector<int>  _list;
        std::size_t    _size;

    public:
        Span();
        Span(std::size_t a);
        Span(const Span &other);
        Span & operator=(const Span & other);
        ~Span();        

        std::vector<int>      getList() const;
        std::size_t          getSize() const;
        void            addNumber(size_t nbr);
        std::size_t    shortestSpan();
        std::size_t    longestSpan();

        void            createList(std::size_t i);
};

#endif