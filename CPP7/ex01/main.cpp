#include "iter.hpp"

void    every_element_int(int i)
{
    std::cout << "Before add 1 int: " << i << std::endl;
    i += 1;
    std::cout << "After add 1 int: " << i << std::endl;
}

void    every_element_char(char c)
{
    std::cout << "Before add 1 char: " << c << std::endl;
    c += 1;
    std::cout << "After add 1 char: " << c << std::endl;
}

int main()
{
    int i[3] = {4123, 13, 2};
    char tab[] = "aBcDe";

    iter<int>(i, 3, &every_element_int);
    iter<char>(tab, 5, &every_element_char);
}