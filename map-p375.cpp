#include <map>
#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        ++word_count[word];
    }
    for (const auto &item : word_count)
    {
        std::cout << item.first << " occurs " << item.second << ((item.second > 1) ? " times" : " time") << std::endl;
    }
    return 0;
}
