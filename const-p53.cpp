#include <iostream>

main()
{
    int i = 42;
    const int &ri = i;

    //error: uninitialized const 'k' [-fpermissive]
    // const int k;

    // error: increment of read-only reference 'ri'
    // ri++;

    i = 54;
    std::cout << ri << " " << i << std::endl;

    const int *pi = &i;
    i = 44;
    pi = 0;

    //  error: assignment of read-only location '* pi'
    // *pi = 5;

    int const *pi2 = &i;
    i = 34;
    pi2 = 0;

    //  error: assignment of read-only location '* pi2'
    // *pi2 = 4;

    int *const pi3 = &i;

    // error: assignment of read-only variable 'pi3'
    //pi3 = 0;

    i = 6;
}