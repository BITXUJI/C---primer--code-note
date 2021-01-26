#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
bool str5(const std::string &s)
{
    return s.size() >= 5;
}
int main(int argc, char const *argv[])
{
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto iter = std::partition(words.begin(), words.end(), str5);
    for (auto i = words.begin(); i != iter; ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    return 0;
}
