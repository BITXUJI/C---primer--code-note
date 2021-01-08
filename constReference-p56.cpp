#include <iostream>
main()
{
    int i = 42;
    int &r1 = i;
    const int &r2 = i; // r2 value can't be changed
    r1 = 0;
    //error: assignment of read-only reference 'r2'
    //r2 = 0;
    std::cout << r1 << " " << r2 << " " << i << std::endl;
}