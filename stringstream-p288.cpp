#include <sstream>
#include <iostream>
#include <vector>
#include <string>
struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

int main(int argc, char const *argv[])
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while (getline(std::cin, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    for (auto &i : people)
    {
        std::cout << i.name << " ";
        for (auto &j : i.phones)
            std::cout << j << " ";
        std::cout << std::endl;
    }

    return 0;
}
