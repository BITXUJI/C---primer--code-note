#include <map>
#include <set>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::multimap<std::string, std::string> authors;
    authors.insert({"simon", "cook"});
    authors.insert({"gallagher", "book"});
    authors.insert({"simon", "you"});
    authors.insert({"simon", "birthday"});
    std::string search_item("simon");
    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);
    while (entries)
    {
        std::cout << iter->second << std::endl;
        --entries;
        ++iter;
    }

    for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item); beg != end; ++beg)
    {
        std::cout << beg->second << std::endl;
    }
    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
    {
        std::cout << pos.first->second << std::endl;
    }

    return 0;
}
