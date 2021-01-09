#include <iostream>
#include <vector>
main()
{
    int a[10] = {};



    int count = 0;
    for (auto &i : a)
        i = count++;
    for (auto i : a)
        std::cout << i << std::endl;
    std::vector<int> v;
    for (auto i : a)
        v.push_back(i);
    for (auto i : v)
        std::cout << i << std::endl;
}