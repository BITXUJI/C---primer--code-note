#include <map>
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }
    std::map<std::string, std::size_t>::iterator map_it = word_count.begin();
    while (map_it != word_count.end())
    {
        std::cout << map_it->first << " " << map_it->second << std::endl;
        ++map_it;
    }
    for (const auto &item : word_count)
    {
        std::cout << item.first << " " << item.second << std::endl;
    }

    std::multimap<std::string, std::string> authors;
    authors.insert({"Barth,John", "Sot_Weed Factor"});

    return 0;
}
