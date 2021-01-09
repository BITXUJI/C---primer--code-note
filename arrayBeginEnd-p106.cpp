#include <iostream>
#include <string>
#include <iterator>
#include <vector>

int main(int argc, const char **argv)
{
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *beg = std::begin(ia);
    int *last = std::end(ia);

    constexpr size_t sz = 5;
    int arr[sz] = {1, 2, 3, 4, 5};
    int *ip = arr;
    int *ip2 = ip + 4;

    int *p = arr + sz;
    int *p2 = arr + 10;                       // NO error during compile
    auto n = std::end(arr) - std::begin(arr); //n :ptrdiff_t
    int *b = arr, *e = arr + sz;
    while (b < e)
        b++;
    int i = 0;
    int sz1 = 42;
    int *p1 = &i, *e1 = &sz1;
    while (p1 < e1) //No error but undefined
    {
        p1++;
    }

    int last1 = *(ia + 4);
    int i1 = ia[2];
    int *p4 = ia;
    i1 = *(p4 + 2);

    int *p3 = &ia[2];
    int j = p[1];
    int k = p[-2];

    int *pp1 = ia;
    int *pp2 = &ia[2];
    pp1 += pp2 - pp1;

    std::vector<int> ivec(ia, &ia[5]);
    for (auto i : ivec)
        std::cout << i << std::endl;

    std::vector<int> ivec1(std::begin(ia), std::end(ia));

    return 0;
}