#include <string>
#include <iostream>
#include <vector>
int main(int argc, char const *argv[])
{
    std::vector<std::string> vec = {"10", "12", "5"};
    int sum = 0;
    for (const auto &str : vec)
        sum += std::stoi(str.substr(str.find_first_of("+-.0123456789")));
    std::cout << sum << std::endl;
    return 0;
}
