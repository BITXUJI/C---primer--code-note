#include <iostream>

int main(int argc, const char **argv)
{
    int i = 42;
    const int &r1 = i;
    const int &r2 = 42; // It is OK here for reference initialization
    const int &r3 = r1 * 2;

    //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //int &r4 = r1 * 2;

    double dval = 3.14;

    /* * 
     * const int temp =dval;
     * const int &ri =temp;
     * == const int &ri =dval;
     * */

    const int &ri = dval;

    return 0;
}