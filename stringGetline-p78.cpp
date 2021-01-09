#include <iostream>
#include <string>
int main(int argc, const char **argv)
{
    std::string line;
    while (getline(std::cin, line))
    {
        std::cout << line << std::endl;
    }
    return 0;
}