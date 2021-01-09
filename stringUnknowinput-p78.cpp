#include <iostream>
#include <string>
int main(int argc, const char **argv)
{
    std::string word;
    while (std::cin >> word)
    {
        std::cout << word << std::endl;
    }
    return 0;
}