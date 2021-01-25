#include <iostream>
#include <vector>
#include <algorithm>
int main(int argc, char const *argv[])
{
    std::vector<int> ivec = {1, 2, 3, -4, 5, 6};
    std::vector<int> ivec1(10, 0);
    std::transform(ivec.cbegin(), ivec.cend(), ivec1.begin(), [](int i) { return (i > 0) ? i : -i; });
    for (const auto &item : ivec1)
        std::cout << item << " ";
    std::cout << std::endl;
    std::transform(ivec.begin(), ivec.end(), ivec.begin(),
                   [](int i) -> int {if(i>0)return i;else return -i; });
    for (const auto &item : ivec)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
