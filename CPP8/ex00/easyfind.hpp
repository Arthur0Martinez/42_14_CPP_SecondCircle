#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <list>
# include <vector>
# include <iostream>
# include <algorithm>

template <typename T>
int    easyfind(T &a, int b)
{
    typename    T::const_iterator it = std::find(a.begin(), a.end(), b);

    if (it != a.end())
    {
        std::cout << "First occurence of " << b << " exist" << std::endl;
        return (0);
    }
    else
    {
        std::cout << "First occurence of " << b << " wasn't find" <<std::endl;
        return (-1);
    }
}

#endif
