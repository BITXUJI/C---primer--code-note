#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::ifstream is("aaa");
    std::vector<std::string> vec;
    std::string line;
    while (getline(is, line))
    {
        vec.push_back(line);
    }
    for (const auto &i : vec)
    {
        std::string word;
        std::istringstream is(i);
        while (is >> word)
            std::cout << word << " " << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
