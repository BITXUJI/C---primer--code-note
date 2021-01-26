#include <utility>
#include <vector>
#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::string word;
    int number;
    std::vector<std::pair<std::string, int>> pvec;
    while (std::cin >> word >> number)
    {
        // pvec.push_back({word, number});
        // pvec.emplace_back(word, number);
        // pvec.push_back(make_pair(word, number));
        // pvec.push_back(std::make_pair(word, number));
        pvec.push_back(std::pair<std::string, int>(word, number));
    }
    for (const auto &item : pvec)
        std::cout << item.first << " " << item.second << std::endl;
    return 0;
}
