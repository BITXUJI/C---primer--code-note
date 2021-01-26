#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
bool compareSize(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}
int main(int argc, char const *argv[])
{
    std::map<std::string, int> word_count = {{"hello", 2}, {"world", 3}};
    std::map<std::string, int>::iterator map_it = word_count.begin();
    map_it->second = 10;
    std::multiset<std::string, decltype(compareSize) *> str(compareSize);
    using pfunc = bool (*)(const std::string &, const std::string &);
    std::multiset<std::string, pfunc> str1(compareSize);
    std::multiset<std::string, pfunc>::iterator set_it = str.begin();
    return 0;
}
