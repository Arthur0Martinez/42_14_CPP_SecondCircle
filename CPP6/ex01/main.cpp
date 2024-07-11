#include "Serializer.hpp"

int main()
{
    Data data;
    uintptr_t i;

    data.data1 = 5;
    std::cout << &data << std::endl;
    std::cout << data.data1 << std::endl;
    i = Serializer::serialize(&data);
    std::cout << i << std::endl;
    std::cout << Serializer::deserialize(i) << std::endl;
    std::cout << data.data1 << std::endl;
}