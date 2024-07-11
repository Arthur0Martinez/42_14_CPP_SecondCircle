#include "Span.hpp"

Span::Span() : _size(0)
{
    return ;
}

Span::Span(std::size_t a) : _size(a)
{
    return ;
}

Span::Span(const Span &other)
{
    *this = other;
    return ;
}
    
Span & Span::operator=(const Span & other)
{
    this->_size = other.getSize();
    _list = other.getList();
    return *this;
}

Span::~Span()
{
    return ;
}

void    Span::addNumber(size_t nbr)
{
    if (this->_list.size() < this->_size)
    {
        this->_list.push_back(nbr);
    }
    else
        throw std::runtime_error("Size is too big");
}

std::size_t    Span::shortestSpan()
{
    if (this->_size <= 1)
        throw std::runtime_error("Not enough number in list");

    int  res = 2147483647;
    std::sort(_list.begin(), _list.end());
    std::vector<int>::iterator    it;
    std::vector<int>::iterator    nextIt = this->_list.begin();

    nextIt++;
    for (it = this->_list.begin(); nextIt != this->_list.end(); ++it)
    {
        if ((*nextIt - *it) < res)
            res = *nextIt - *it;
        nextIt++;
    }
    return (res);
}
    
std::size_t    Span::longestSpan()
{
    if (this->_size <= 1)
        throw std::runtime_error("Not enough number in list");

    std::size_t res;
    std::sort(_list.begin(), _list.end());
    res = this->_list.back() - this->_list.front();
    return (res);
}

std::vector<int>  Span::getList() const
{
    std::vector<int> copy (this->_list.begin(), this->_list.end());
    return(copy);
}

std::size_t          Span::getSize() const
{
    return(this->_size);
}

void          Span::createList(std::size_t i)
{
    if (this->_size < i)
        throw std::runtime_error("List not big enough");

    // int N = 100;
    srand(time(0));

    std::vector<int> copy(i);
    std::vector<int>::iterator it;

    for (it = copy.begin(); it != copy.end(); ++it)
    {
        *it = rand() % 100;
    }
    this->_list = copy;
}