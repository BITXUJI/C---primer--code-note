#include <string>
#include <vector>
#include <iostream>
//undefined reference to `print(int const*)'
void print(const int *);
void print(const int[]);
void print(const int[10]);
int main(int argc, char const *argv[])
{
    int i = 0, j[2] = {1, 2};
    print(&i);
    print(j);
    return 0;
}

void print(const int *i)
{
    std::cout << "const int * i:" << *i << std::endl;
}

// error: redefinition of 'void print(const int*)'
//void print(const int a[])

//error: expected ',' or '...' before 'a'
//error: redefinition of 'void print(const int*)'
// void print(const int[] a)
// {
//     std::cout << "const in[]a" << *a << std::endl;
// }

// error: redefinition of 'void print(const int*)'
//void print(const int a[10])

//error: expected ',' or '...' before 'a'
// error: redefinition of 'void print(const int*)'
//
