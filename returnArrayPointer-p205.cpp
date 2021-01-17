#include <vector>
#include <iostream>
#include <string>

// typedef in arrT[5];
using arrT = int[5];
arrT *func(int i, int (&arr1)[5], int (&arr2)[5])
{
    return (i % 2) ? &arr1 : &arr2;
}

auto func1(int i, int (&arr1)[5], int (&arr2)[5]) -> int (*)[5]
{
    return (i % 2) ? &arr1 : &arr2;
}

int a[5];
decltype(a) *func2(int i, int (&arr1)[5], int (&arr2)[5])
{
    return (i % 2) ? &arr1 : &arr2;
}

int (*func3(int i, int (&arr1)[5], int (&arr2)[5]))[5]
{
    return (i % 2) ? &arr1 : &arr2;
}

arrT &func4(int i, int (&arr1)[5], int (&arr2)[5])
{
    return (i % 2) ? arr1 : arr2;
}
auto func5(int i, int (&arr1)[5], int (&arr2)[5]) -> int (&)[5]
{
    return (i % 2) ? arr1 : arr2;
}

decltype(a) &func6(int i, int (&arr1)[5], int (&arr2)[5])
{
    return (i % 2) ? arr1 : arr2;
}
int (&func7(int i, int (&arr1)[5], int (&arr2)[5]))[5]
{
    return (i % 2) ? arr1 : arr2;
}
int main(int argc, char const *argv[])
{
    int odd[] = {1, 3, 5, 7, 9};
    int even[] = {0, 2, 4, 6, 8};
    //func3(int i, int(&arr1)[5] = odd, int(&arr2)[5] = even);
    // auto p = func3(4);
    int(*p)[5] = func3(5, odd, even);
    for (auto i : *p)
    {
        std::cout << i << std::endl;
    }
    //auto p1 = func4(2, odd, even);
    int(&p1)[5] = func4(2, odd, even);
    for (auto i : p1)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
