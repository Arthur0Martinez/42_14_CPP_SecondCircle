#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <list>
# include <ctime>
# include <algorithm>

class PmergeMe
{
    private:
        std::list<int>      _myList;
        std::vector<int>    _myVector;
        PmergeMe();

    public:
        PmergeMe(char **str);
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe operator=(const PmergeMe &other);

        std::list<int>  getMyList() const;
        std::vector<int>  getMyVector() const;

        void    calculation_l();
        void    calculation_v();
};


template<class InputIt>
InputIt copy_next(InputIt it, typename std::iterator_traits<InputIt>::difference_type n = 1)
{
    std::advance(it, n);
    return it;
}

#endif