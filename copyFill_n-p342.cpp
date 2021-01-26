#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
int main(int argc, char const *argv[])
{
    std::vector<int> vec;
    std::list<int> lst;
    int i;
    std::ifstream numbers("numbers");
    while (numbers >> i)
        lst.push_back(i);
    vec.resize(lst.size());
    std::copy(lst.cbegin(), lst.cend(), vec.begin());
    for (const auto &item : vec)
        std::cout << item << " ";
    std::cout << std::endl;

    std::vector<int> vec1;
    vec1.reserve(10);
    vec1.resize(10);
    std::fill_n(vec1.begin(), 10, 1);
    for (const auto &item : vec1)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
