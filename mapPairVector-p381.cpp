#include <utility>
#include <map>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::map<std::string, std::vector<std::pair<std::string, std::size_t>>> family;
    std::string last_name = "Gallagher";
    std::string first_name = "Simon";
    std::size_t age = 20;
    family[last_name].push_back(std::make_pair(first_name, age));
    for (const auto &item : family)
        std::cout << "the last name : " << item.first << " the first name is : " << item.second.back().first << " the age is : " << item.second.back().second << std::endl;
    return 0;
}
