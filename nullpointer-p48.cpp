#include <iostream>
#include <cstdlib>
int main(int argc, const char **argv)
{
    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;

    //error: invalid conversion from 'int' to 'int*' [-fpermissive]
    //int *p4 = 1;

    int val;
    int *p4 = &val;
    p4 = 0;
    // error: invalid conversion from 'int' to 'int*' [-fpermissive]
    //int zero = 0;
    //p4 = zero;

    //  error: invalid conversion from 'int' to 'int*' [-fpermissive]
    //int *p5 = &val;
    //p5 = 1;

    return 0;
}
