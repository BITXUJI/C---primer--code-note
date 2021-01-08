#include <iostream>
main()
{
    //Excise 2.21
    int i = 0;

    // error: cannot convert 'int*' to 'double*' in initialization
    //double *dp = &i;

    // error: invalid conversion from 'int' to 'int*' [-fpermissive]
    //int *ip = i;

    int *p = &i; // OK

    //Excise 2.24
    int i2 = 42;

    // error: invalid conversion from 'int*' to 'long int*' [-fpermissive]
    // long *lp = &i2;

    void *p2 = &i2;

    //  error: invalid conversion from 'void*' to 'int*' [-fpermissive]
    //int *p3 = p2;

    // error: invalid conversion from 'int' to 'int*' [-fpermissive]
    // int *p3 = (int)p2;

    int *p3 = (int *)p2; // equals int *p3 =(int *)&i2;

    long long *llp = (long long *)p2; // equals long long *llp =(long long*)&i2;

    double *dp = (double *)p2;                                         // equals double *dp =(double*)&i2;
    std::cout << *p3 << " " << *llp << " " << *dp << " " << std::endl; // output :42 42 2.07508e-322
}