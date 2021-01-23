#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::string words = "ab2c3d7R4E6";
    std::string numbers = "0123456789";
    std::string::size_type pos = 0;
    while ((pos = words.find_first_of(numbers, pos)) != std::string::npos)
    {
        std::cout << "found number at index: " << pos << " element is " << words[pos] << std::endl;
        ++pos;
    }
    pos = 0;
    while ((pos = words.find_first_not_of(numbers, pos)) != std::string::npos)
    {
        std::cout << " found letter at index: " << pos << " element is " << words[pos] << std::endl;
        ++pos;
    }
    return 0;
}
