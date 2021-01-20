#include "person.h"
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    Person ps1("Simon", "beijing", 5);
    std::cout << ps1.getName() << std::endl;
    Person ps2;
    //read(std::cin, ps2);
    //print(std::cout, ps2) << std::endl;

    Person ps3(std::cin);
    print(std::cout, ps3);
    return 0;
}
