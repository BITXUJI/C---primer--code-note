#include <iostream>

main()
{
    const int ci = 1024;
    const int &r1 = ci;

    //  error: assignment of read-only reference 'r1'
    //r1 = 42;

    //error: binding reference of type 'int&' to 'const int' discards qualifiers
    //int &r2 = ci;

    // error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
    //int *pi = &ci;

    const int *pi2 = &ci;

    // error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
    //int *const pi3 = &ci;
}