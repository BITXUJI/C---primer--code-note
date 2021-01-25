#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> svec = {"aa", "abc", "deee", "a", "sbs"};
    std::sort(svec.begin(), svec.end(), isShorter);
    for (const auto &item : svec)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
