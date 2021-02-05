#include "Sales_item.h"
#include <iostream>
template <typename T>
int compare(const T &lhs, const T &rhs)
{
    if (lhs < rhs)
        return 1;
    if (rhs < lhs)
        return -1;
    return 0;
}

template <typename Iterator, typename Value>
Iterator find(Iterator first, Iterator last, const Value &v)
{
    for (; first != last && *first != v; ++first)
        ;
    return first;
}
template <typename Array>
void print(const Array &arr)
{
    for (const auto &elem : arr)
        std::cout << elem << std::endl;
}
template <typename T, unsigned N>
T *begin(const T (&arr)[N])
{
    return arr;
}
template <typename T, unsigned N>
T *end(const T (&arr)[N])
{
    return arr + N;
}
template <typename T, unsigned N>
constexpr unsigned size(const T (&arr)[N])
{
    return N;
}
int main(int argc, char const *argv[])
{
    Sales_item s1("111");
    Sales_item s2("222");
    std::cout << compare(s1, s2) << std::endl;
    return 0;
}
