#include "Vec.h"
#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
    Vec<std::string> strvec;
    strvec.push_back("hello");
    std::cout << strvec.size() << " " << strvec.capacity() << std::endl;
    strvec.push_back("world");
    std::cout << strvec.size() << " " << strvec.capacity() << std::endl;
    for (const auto &item : strvec)
        std::cout << item << std::endl;
    return 0;
}
