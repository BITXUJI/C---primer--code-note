#include <iostream>
#include <string>
int text_size()
{
    return 1;
}
std::string sa[10];
int id[10];
main()
{
    unsigned buf_size = 1024;
    int ia[buf_size];
    int ib[4 * 7 - 14];
    int ic[text_size()];

    // error: initializer-string for array of chars is too long [-fpermissive]
    // char st[11] = "fundamental";

    std::string sa2[10];
    int ia2[10];
    for (auto i : sa)
        std::cout << i << std::endl; // output: ""
    for (auto i : id)
        std::cout << i << std::endl; // output :0
    for (auto i : ia2)
        std::cout << i << std::endl; //output: random
    for (auto i : sa2)
        std::cout << i << std::endl; // output: ""
}