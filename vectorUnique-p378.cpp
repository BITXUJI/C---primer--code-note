#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::vector<std::string> svec;
    std::string word;
    while (std::cin >> word)
    {
        if (std::find(svec.cbegin(), svec.cend(), word) == svec.cend())
            svec.push_back(word);
    }
    for (const auto &item : svec)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
