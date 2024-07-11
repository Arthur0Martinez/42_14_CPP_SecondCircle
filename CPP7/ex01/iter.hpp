#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void    iter(T *arr, int length, void(*f)(T))
{
    int i = 0;
    while (i < length)
    {
        f(arr[i]);
        i++;
    }
    return ;
}

#endif