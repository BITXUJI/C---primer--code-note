#include <iostream>
#include <string>
#include <vector>
int main(int argc, const char **argv)
{
    int i = 0, j = 0, k = 0;
    const int ci = i;

    int i1(1.1);

    // error: narrowing conversion of '1.1000000000000001e+0' from 'double' to 'int' [-Wnarrowing]
    // int i2{1.1};

    int i3 = 1.1;

    // error: narrowing conversion of '1.1000000000000001e+0' from 'double' to 'int' [-Wnarrowing]
    // int i4 = {1.1};

    //error: lvalue required as left operand of assignment
    // 1024 = k;

    // error: lvalue required as left operand of assignment
    // i + j = k;

    //  error: assignment of read-only variable 'ci'
    //ci = k;

    k = 0;
    k = 3.1415;

    //error: narrowing conversion of '3.1400000000000001e+0' from 'double' to 'int' [-Wnarrowing]
    // k = {3.14};

    std::vector<int> vi(11, 1);
    vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // vi is replaced to this
    for (const auto &i : vi)
        std::cout << i << std::endl; // output: 1~9
    return 0;
}