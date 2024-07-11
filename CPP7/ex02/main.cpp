#include "Array.hpp"

int main()
{
    Array<int> a(5);
    Array<int> b(3);

    for(unsigned long i = 0; i < 5; i++)
    {
        a[i] = i;
        std::cout << "Values of array a are " << a[i] << std::endl;
    }
    std::cout << "Size of array a is " << a.size() << std::endl;


    for(unsigned long i = 0; i < 3; i++)
    {
        b[i] = i + 325;
        std::cout << "Values of array b are " << b[i] << std::endl;
    }
    std::cout << "Size of array b is " << b.size() << std::endl;

    a = b;

    std::cout << "Values of array a are " << a[0] << std::endl;
    std::cout << "Values of array b are " << b[0] << std::endl;

    Array<float> c;

    std::cout << "Values of array c are " << c[0] << std::endl;


    Array<std::string> str(2);
    Array<std::string> strCopy(3);

    str[0] = "str 0";
    str[1] = "str 1";

    std::cout << "Size of array str is " << str.size() << std::endl;
    std::cout << "Values of array str0 are " << str[0] << std::endl;
    std::cout << "Values of array str1 are " << str[1] << std::endl;

    strCopy[0] = "strCopy 0";
    strCopy[1] = "strCopy 1";
    strCopy[2] = "strCopy 2";

    std::cout << "Size of array strCopy is " << strCopy.size() << std::endl;
    std::cout << "Values of array strCopy0 are " << str[0] << std::endl;
    std::cout << "Values of array strCopy1 are " << str[1] << std::endl;
    std::cout << "Values of array strCopy2 are " << str[0] << std::endl;

    strCopy = str;

    std::cout << "Values of array str0 are " << str[0] << std::endl;
    std::cout << "Values of array strCopy0 are " << strCopy[0] << std::endl;

    std::cout << "Size of array str are " << str.size() << std::endl;
    std::cout << "Size of array strCopy are " << strCopy.size() << std::endl;

    Array<std::string> strOut(1);

    try
    {
        strOut[0] = "Correct";
        std::cout << "Does it goes there ?" << std::endl;
        strOut[1] = "Incorrect";
        std::cout << "Does it goes there ?" << std::endl;
        strOut[2] = "Incorrect";
        std::cout << "Does it goes there ?" << std::endl;
    }   
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "End of main function" << std::endl;
}