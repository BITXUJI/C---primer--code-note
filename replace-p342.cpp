#include <algorithm>
#include <list>
#include <iostream>
#include <vector>
#include <iterator>
int main(int argc, char const *argv[])
{
    std::list<int> ilst = {1, 23, 4, 5, 6, 7, 8, 9, 90, 0, 2, 1, 0};
    std::replace(ilst.begin(), ilst.end(), 0, 111);
    for (const auto &item : ilst)
        std::cout << item << " ";
    std::cout << std::endl;
    std::vector<int> ivec;
    std::replace_copy(ilst.cbegin(), ilst.cend(), std::back_inserter(ivec), 1, 112);
    for (const auto &item : ivec)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
