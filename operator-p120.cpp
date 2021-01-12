#include <iostream>
#include <string>
#include <vector>
#include <iterator>
int main(int argc, char const *argv[])
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    auto beg = *vec.begin(); //auto beg =*(vec.begin());
    std::cout << beg << std::endl;
    auto beg1 = *vec.begin() + 1; //auto beg1 =*(vec.begin())+1;
    std::cout << beg1 << std::endl;

    int ia[] = {0, 2, 4, 6, 8};
    int last = *(ia + 4);
    last = *std::begin(ia);
    return 0;
}
