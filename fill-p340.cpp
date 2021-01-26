#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> vec(10);
    std::fill(vec.begin(), vec.begin() + vec.size() / 2, 10);
    std::fill_n(vec.begin(), vec.size(), 5);
    for (const auto &item : vec)
        std::cout << item << std::endl;
    return 0;
}
