#include <iostream>

main()
{
    int i = 0;
    int *const p1 = &i;
    const int ci = 42;
    const int *p2 = &ci;
    const int *const p3 = p2;
    const int &r = ci;
    i = ci;
    p2 = p3;

    // error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
    // int *p = p3;

    p2 = p3;
    p2 = &i;

    //rror: binding reference of type 'int&' to 'const int' discards qualifiers
    //int &r1 = ci;

    const int &r2 = i;
    constexpr int mf = 20;
}