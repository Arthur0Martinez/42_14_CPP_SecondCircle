#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    this->_myList.push_back(1);
    this->_myVector.push_back(1);
}

PmergeMe::PmergeMe(char **str)
{
    for(int i = 1; str[i] != NULL; i++)
    {
        this->_myList.push_back(atoi(str[i]));
        this->_myVector.push_back(atoi(str[i]));
    }
}

PmergeMe::PmergeMe(const PmergeMe &other) : _myList(other.getMyList()), _myVector(other.getMyVector()) {}

PmergeMe::~PmergeMe() {}

PmergeMe PmergeMe::operator=(const PmergeMe &other)
{
    this->_myList = other.getMyList();
    this->_myVector = other.getMyVector();
    return (*this);
}

std::list<int>  PmergeMe::getMyList() const
{
    return (this->_myList);
}

std::vector<int>  PmergeMe::getMyVector() const
{
    return (this->_myVector);
}

void    swap_l_v(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void    insertionSort_l(std::list<int> &arr)
{
	for (std::list<int>::iterator it = copy_next(arr.begin()) ; it != arr.end(); ++it)
	{
		int key = *it;
		std::list<int>::iterator jt = it;
		--jt;
		while (jt != arr.begin() && *jt > key)
		{
			swap_l_v(*copy_next(jt),(*jt));
			--jt;
		}
		if (*jt > key)
			swap_l_v(*copy_next(jt),(*jt));
	}
}

void    insertionSort_v(std::vector<int> &arr)
{
	for (std::vector<int>::iterator it = copy_next(arr.begin()) ; it != arr.end(); ++it)
	{
		int key = *it;
		std::vector<int>::iterator jt = it;
		--jt;
		while (jt != arr.begin() && *jt > key)
		{
			swap_l_v(*copy_next(jt),(*jt));
			--jt;
		}
		if (*jt > key)
			swap_l_v(*copy_next(jt),(*jt));
	}
}

void    mergeInsertionSort_l(std::list<int> &arr)
{
    if (arr.size() <= 1)
        return ;
    if (arr.size() <= 2)
    {
        insertionSort_l(arr);
        return ;
    }

    std::list<int> left(arr.begin(), copy_next(arr.begin(), arr.size() / 2));
    std::list<int> right(copy_next(arr.begin(), arr.size() / 2), arr.end());

    mergeInsertionSort_l(left);
    mergeInsertionSort_l(right);

    arr.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(arr));
}

void    mergeInsertionSort_v(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return ;
    if (arr.size() <= 2)
    {
        insertionSort_v(arr);
        return ;
    }

    std::vector<int> left(arr.begin(), copy_next(arr.begin(), arr.size() / 2));
    std::vector<int> right(copy_next(arr.begin(), arr.size() / 2), arr.end());

    mergeInsertionSort_v(left);
    mergeInsertionSort_v(right);

    arr.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(arr));
}

void    PmergeMe::calculation_l()
{
    mergeInsertionSort_l(this->_myList);
}

void    PmergeMe::calculation_v()
{
    mergeInsertionSort_v(this->_myVector);
}