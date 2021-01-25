#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::vector<int> ivec = {1, 1, 2, 4, 3, 2, 4, 54, 5, 4, 5, 22, 3};
    std::list<int> ilst;
    std::sort(ivec.begin(), ivec.end());
    std::unique_copy(ivec.cbegin(), ivec.cend(), std::inserter(ilst, ilst.begin()));
    // std::unique_copy(ivec.cbegin(), ivec.cend(), std::back_inserter(ilst));
    for (const auto &item : ilst)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
