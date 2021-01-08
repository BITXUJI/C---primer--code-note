#include <iostream>

int main(int argc, const char **argv)
{
    int ival = 1024;
    int &refVal = ival;
    //error: 'refVal2' declared as reference but not initialized
    //int &refVal2;
    refVal = 2;
    int ii = refVal;
    int &refVal3 = refVal;
    int i = refVal;
    // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //int &refVal4 = 10;
    double dval = 3.14;
    // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //int &refVal5 = dval;
    return 0;
}