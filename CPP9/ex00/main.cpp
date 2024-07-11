#include "BitcoinExchange.hpp"

// map

void file_exist(int argc, char **argv)
{
    std::string str = argv[1];
    if(argc != 2)
        throw std::runtime_error("Error : Not the right number of files.");
    FILE *file = fopen(str.c_str(), "r");
    if (file)
        fclose(file);
    else
        throw std::runtime_error("Error : File does not exist.");
}

int main(int argc, char **argv)
{
    char str[] = "data.csv";
    int a;
    try
    {
        file_exist(argc, argv);
        BitcoinExchange bte(argv[1]);
        a = bte.getDataMap(0, str);
        a = bte.getDataMap(1, argv[1]);
        std::string *final_print = bte.compareMap(a);
        for (int i = 0; i < a; ++i) 
            std::cout << final_print[i] << std::endl;
        delete[] final_print;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return(0);
}