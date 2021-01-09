#include <iostream>
#include <string>
#include <vector>
int main(int argc, const char **argv)
{
    std::vector<int> v2;
    for (auto i = 0; i < 100; i++)
        v2.push_back(i);
    for (auto i : v2)
        std::cout << i << std::endl;
    std::vector<std::string> v3;
    std::string word;
    while (std::cin >> word)
        v3.push_back(word);
    for (auto i : v3)
        std::cout << i << std::endl;
    for (auto i : word)
        std::cout << i << std::endl;
    for (auto i : {"aaa", "string"})
        std::cout << i << std::endl;
    return 0;
}