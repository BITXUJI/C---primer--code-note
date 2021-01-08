#include <iostream>

int main()
{
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;

    int i = 42;
    int *p;
    int *&r = p;
    r = &i;
    *r = 0;
    std::cout << *r << " " << *p << " " << std::endl; //output 0  0

    int i1 = 45;
    int &r1 = i1;
    int *p1 = &r1;
    r1 = 5;
    std::cout << r1 << " " << *p1 << " " << std::endl;

    // error: invalid conversion from 'int*' to 'int' [-fpermissive]
    //error: cannot bind rvalue '(int)p1' to 'int&'
    //int &r2 = p1;

    // error: cannot bind non-const lvalue reference of type 'double&' to an rvalue of type 'double'
    //double &r3 = i1;

    int &r4 = i1;
    p1 = 0;                       //p1 =nullptr p1 doesn't point to any object
    int &r5 = *p1;                // *p1 is an object
    std::cout << r5 << std::endl; // NO ERROR but output: Segmentation fault
    int *p2;
    int &r6 = *p2;
    std::cout << r6 << std::endl; //NO ERROR but output:Segmentation fault
    return 0;
}