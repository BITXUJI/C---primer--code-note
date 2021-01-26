#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
int main(int argc, char const *argv[])
{
    std::vector<int> ivec;
    auto iter = std::back_inserter(ivec);
    // *iter = 54;
    std::fill_n(iter, 10, 12);
    for (const auto &item : ivec)
        std::cout << item << std::endl;
    return 0;
}
