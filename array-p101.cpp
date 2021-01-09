#include <iostream>
#include <string>
#include <vector>

main()
{
    unsigned cnt = 42;
    constexpr unsigned sz = 42;
    int arr[10];
    int *parr[sz];
    std::string bad[cnt]; //output: OK

    //error: 'bad1' declared as array of 'auto'
    // auto bad1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    const unsigned sz1 = 3;
    int ia1[sz1] = {0, 1, 2};
    int a2[] = {0, 1, 2};
    int a3[5] = {0, 1, 2};
    std::string a4[3] = {"hi", "bye"};

    for (auto i : a3)
        std::cout << i << std::endl;
    int a11[10];
    for (auto i : a11)
        std::cout << i << std::endl; //output: random
    int a12[10] = {};
    for (auto i : a12)
        std::cout << i << std::endl; //output: 0

    // error: too many initializers for 'int [2]'
    // int a5[2] = {0, 1, 2};

    char a5[] = {'c', '+', '+'};
    char a6[] = {'c', '+', '+', '\0'};
    char a7[] = "c++";

    //  error: initializer-string for array of chars is too long [-fpermissive]
    // char a8[3] = "c++";

    int a9[] = {0, 1, 2};

    //error: initializer fails to determine size of 'a10'
    //int a10[] = a9;

    //error: array must be initialized with a brace-enclosed initializer
    // int a10[10] = a9;

    //error: incompatible types in assignment of 'int [3]' to 'int [10]
    // a10 = a9;
}