#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

class OutOfScope : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return("Error : Array is out of scope\n");
        }
};

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _n;
    public:
        Array() : _array(new T[0]), _n(1)
        {
            return ;
        }

        ~Array()
        {
            delete[] this->_array ;
        }

        Array(unsigned int n) : _array(new T[n]), _n(n)
        {
            return ;
        }

        Array(Array<T> const &other)
        {
            for(unsigned long i = 0; i < other.size(); i++)
            {
                this->_array[i] = other._array[i];
            }
        }

        Array<T>    &operator=(Array &other)
        {
            delete[] _array;
            _array = new T[other.size()];
            for (unsigned long i = 0; i < other.size(); i++)
                this->_array[i] = other._array[i];
            return (*this);
        }

        T    &operator[](size_t index)
        {
            if (index >= this->_n)
                throw(OutOfScope());
            return(_array[index]);
        }

        unsigned int size()
        {
            return (this->_n);
        }

        T* getArray()
        {
            return(this->_array);
        }
};

#endif