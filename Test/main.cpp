#include "test.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    Top<int8_t> *a = new Top<int8_t>();
    std::string str = std::string(argv[1]);
    if (!str.compare("int8"))
    {
        Ibase * test = a->CreateType(0);
        std::cout << "Create1?";
        std::cout << test->getType();
    }
    else
    {
        Ibase * test = a->CreateType(1);
        std::cout << "Create2?";
        std::cout << test->getType();
    }
    return (0);
}