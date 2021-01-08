#include <iostream>

int main()
{
    const double pi = 3.14;

    //error: invalid conversion from 'const double*' to 'double*' [-fpermissive]
    // double *ptr = &pi;

    const double *cptr = &pi;

    //error: assignment of read-only location '* cptr'
    // *cptr = 42;

    double dval = 3.14;
    const double *cptr1 = &dval;

    int errNumb = 0;
    int *const curErr = &errNumb;
    const double pi1 = 3.14159;
    const double *const pip = &pi1;
    *curErr = 10;

    //error: assignment of read-only variable 'curErr'
    // curErr = 0;
    return 0;
}