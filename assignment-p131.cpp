#include <string>
#include <vector>
#include <iostream>
int main(int argc, const char **argv)
{
    int i;
    double d;
    d = i = 3.5;
    std::cout << i << " " << d << std::endl;
    i = d = 3.5;
    std::cout << i << " " << d << std::endl;

    //error: lvalue required as left operand of assignment
    // if (42 = i)
    // std::cout << i << std::endl;

    if (i = 42)
        std::cout << i << std::endl;

    double dval;
    int ival;
    int *pi;

    //error: invalid conversion from 'int*' to 'int' [-fpermissive]
    // dval = ival = pi = 0;
    int *p;
    int *getPtr();
    //error: cannot convert 'bool' to 'int*' in assignment
    // if (p = getPtr() != 0)
    if ((p = getPtr()) != 0)
        std::cout << *p << std::endl;
    if (i = 1024)
        std::cout << i << std::endl;

    return 0;
}

int *getPtr()
{
    return 0;
}