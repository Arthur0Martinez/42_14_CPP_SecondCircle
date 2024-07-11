#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>()
        {
            return ;
        }

        MutantStack(const MutantStack &other) : std::stack<T>(other)
        {
            return ;
        }

        ~MutantStack() 
        {
            return ; 
        }

        MutantStack &operator=(const MutantStack &other) 
        {
            std::stack<T>::operator=(other);
            return(*this);
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return(std::stack<T>::c.begin());
        }
        iterator end()
        {
            return(std::stack<T>::c.end());
        }
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        iterator begin() const
        {
            return(std::stack<T>::c.begin());
        }
        iterator end() const
        {
            return(std::stack<T>::c.end());
        }
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        iterator rbegin()
        {
            return(std::stack<T>::c.rbegin());
        }
        iterator rend()
        {
            return(std::stack<T>::c.rend());
        }
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        iterator rbegin() const
        {
            return(std::stack<T>::c.rbegin());
        }
        iterator rend() const
        {
            return(std::stack<T>::c.rend());
        }
};

#endif