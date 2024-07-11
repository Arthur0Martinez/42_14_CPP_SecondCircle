#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>

struct Data
{
    int data1;
    std::string dataStr;
    int data2;
};


class Serializer
{
    private:
        int i;
        Serializer();
        Serializer(const Serializer &other);
        Serializer & operator =(const Serializer &other);
        ~Serializer();

    public:
        static  uintptr_t serialize(Data* ptr);
        static  Data* deserialize(uintptr_t raw);
};

#endif