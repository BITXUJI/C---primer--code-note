#include <map>
#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        //++word_count[word];//
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }
    for (const auto &w : word_count)
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;

    return 0;
}
