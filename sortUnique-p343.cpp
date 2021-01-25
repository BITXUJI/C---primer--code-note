#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}
void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    for (const auto &item : words)
        std::cout << item << " ";
    std::cout << std::endl;
    auto end_unique = std::unique(words.begin(), words.end());
    for (const auto &item : words)
        std::cout << item << " ";
    std::cout << std::endl;
    words.erase(end_unique, words.end());
    for (const auto &item : words)
        std::cout << item << " ";
    std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
    std::vector<std::string> s = {"aa", "b", "d", "bd", "c", "dcd", "aa", "b", "f"};
    elimDups(s);
    std::stable_sort(s.begin(), s.end(), isShorter);
    for (const auto &item : s)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
