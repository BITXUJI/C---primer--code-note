#include <iterator>
// #include <numeric>
#include <algorithm>
#include <iostream>
int main(int argc, char const *argv[])
{
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)];
    auto ret = std::copy(std::begin(a1), std::end(a1), std::begin(a2));
    for (auto &item : a2)
        std::cout << item << std::endl;
    return 0;
}
