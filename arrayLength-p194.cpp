#include <vector>
#include <iostream>
#include <string>
void print(const char *cp)
{
    if (cp)
    {
        while (*cp)
            std::cout << *cp++;
    }
    std::cout << std::endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        std::cout << *beg++ << std::endl;
    }
}
//const int ia[]  = const int *ia;
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << ia[i] << std::endl;
    }
}
// arr size must be 10 exactly
void print(int (&arr)[10])
{
    for (auto elem : arr)
        std::cout << elem << std::endl;
}
int main(int argc, char const *argv[])
{
    const char *c = "hello world";

    print(c);
    int j[3] = {1, 2, 3};
    print(std::begin(j), std::end(j));

    print(j, std::end(j) - std::begin(j));

    int i = 80;
    int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // error: no matching function for call to 'print(int*)'
    // print(&i);

    //error: no matching function for call to 'print(int [3])'
    //print(j);

    print(k);
    return 0;
}
