#include <map>
#include <set>
#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::set<std::string>::key_type v1;
    std::set<std::string>::value_type v2;
    std::map<std::string, int>::value_type V3;
    std::map<std::string, int>::key_type v4;
    std::map<std::string, int>::mapped_type v5;

    std::map<std::string, int> word_count = {{"hello", 2}, {"world", 3}};
    // auto map_it = word_count.begin();
    std::map<std::string, int>::iterator map_it = word_count.begin();
    std::cout << map_it->first;
    std::cout << " " << map_it->second << std::endl;
    //error: passing 'const std::__cxx11::basic_string<char>' as 'this' argument discards qualifiers [-fpermissive]
    // map_it->first = "worddd";
    map_it->second = 5;
    std::cout << map_it->first << " " << map_it->second << std::endl;
    while (map_it != word_count.end())
    {
        std::cout << map_it->first << " occurs " << map_it->second << " times" << std::endl;
        ++map_it;
    }

    return 0;
}
