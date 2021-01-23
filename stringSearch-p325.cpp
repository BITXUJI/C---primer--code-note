#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    std::string name("AnnaBelle");
    auto pos1 = name.find("Anna");
    std::string numbers = "0123456789";
    std::string word = "d2a4";
    auto pos2 = word.find_first_not_of(numbers);
    std::cout << pos1 << " " << pos2 << std::endl;
    return 0;
}
