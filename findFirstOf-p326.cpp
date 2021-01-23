#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string::size_type pos;
    std::string numbers = "0123456789";
    std::string name = "h8ee2ik3kkke32ff";
    while ((pos = name.find_first_of(numbers, pos)) != std::string::npos)
    {
        std::cout << "found number at index: " << pos << " element is " << name[pos] << std::endl;
        ++pos;
    }
    return 0;
}
