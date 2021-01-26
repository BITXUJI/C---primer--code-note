#include <set>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
int main(int argc, char const *argv[])
{
    std::vector<int> ivec = {2, 4, 6, 8, 2, 4, 6, 8};
    std::set<int> set2;
    set2.insert(ivec.cbegin(), ivec.cend());
    set2.insert({1, 3, 5, 6, 7, 9});
    for (const auto &item : set2)
        std::cout << item << std::endl;
    std::set<int>::iterator set_it = set2.begin();
    while (set_it != set2.end())
        std::cout << *set_it++ << std::endl;
    std::map<std::string, std::size_t> word_count;
    std::string word = "aa";
    word_count.insert({word, 1});
    word_count.insert(std::make_pair(word, 2));
    word_count.insert(std::pair<std::string, std::size_t>(word, 3));
    word_count.insert(std::map<std::string, std::size_t>::value_type(word, 4));
    return 0;
}
