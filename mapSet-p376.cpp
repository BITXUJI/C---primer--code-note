#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <functional>
int main(int argc, char const *argv[])
{
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        // if (word[word.size() - 1] == ',' || word[word.size() - 1] == '.')
        //     word = word.substr(0, word.size() - 1);
        // error: no matching function for call to 'remove_if(std::__cxx11::basic_string<char>::iterator, std::__cxx11::basic_string<char>::iterator, <unresolved overloaded function type>)'
        // word.erase(std::remove_if(word.begin(), word.end(), std::ispunct), //why not std::ispunct
        word.erase(std::remove_if(word.begin(), word.end(), ispunct),
                   word.end());
        for (auto &item : word)
            item = tolower(item); //why not std::tolower
        ++word_count[word];
    }
    for (const auto &w : word_count)
    {
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
    }
    return 0;
}
