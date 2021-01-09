#include <iostream>
#include <vector>
#include <string>
main()
{
    std::string nums[] = {"one", "two", "three"};
    std::string *p = &nums[0];
    std::string *p2 = nums; //std::string *p2 =&nums[0];
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto ia2(ia); //auto ia2(&ia[0]);

    //error: invalid conversion from 'int' to 'int*' [-fpermissive]
    // ia2 = 42;

    decltype(ia) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //error: incompatible types in assignment of 'std::string*' {aka 'std::__cxx11::basic_string<char>*'} to 'int [10]'
    // ia3 = p;
    int i = 4;
    ia3[4] = i;

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p1 = arr;
    ++p;
    int *e = &arr[10];
    for (auto b = arr; b != e; ++b)
        std::cout << *b << std::endl;
}