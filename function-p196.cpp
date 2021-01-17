#include <iostream>

//const int ia[10]  :const int *ia;
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
    {
        std::cout << ia[i] << std::endl;
    }
    // error: no matching function for call to 'end(const int*&)'
    // std::cout << (std::end(ia) - std::begin(ia)) << std::endl;
}
void print(const int (&ia)[10])
{
    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << ia[i] << std::endl;
    }
    std::cout << (std::end(ia) - std::begin(ia)) << std::endl;
}

int main(int argc, char const *argv[])
{

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int b[2] = {1, 2};
    //error: invalid initialization of reference of type 'const int (&)[10]' from expression of type 'int [2]' (reference type)
    print(b);
    print(a);
    return 0;
}
