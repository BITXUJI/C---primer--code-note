#include <iostream>
int main(int argc, const char **argv)
{
    int *ip1, *ip2;
    double dp, *dp2;
    int ival = 42;
    int *p = &ival;
    std::cout << ival << " " << *p << " " << p << " " << std::endl;

    //error: invalid conversion from 'int' to 'int*' [-fpermissive]
    //int *p1 = ival;

    //error: invalid conversion from 'int' to 'int*' [-fpermissive]
    //int *p1 = 5;

    double dval;
    double *pd3 = &dval;
    double *pd4 = pd3;

    *pd3 = 5;
    double &r3 = *pd3;
    double dval2;

    //error: invalid initialization of reference of type 'double&' from expression of type 'double*'
    //double &r4 = pd4;

    //error: cannot convert 'double*' to 'double' in assignment
    //*pd3 = &dval2;

    pd3 = &dval2;
    double dval3 = 2;
    *pd3 = dval3; //or *pd3 =2; is ok
    double dval4 = 15;
    r3 = dval4; // or r3 =15; is ok
    // 15 15 15 15
    std::cout << dval << " " << *pd3 << " " << *pd4 << " " << r3 << " " << std::endl;

    //error: cannot convert 'double*' to 'int*' in initialization
    //int *pi = pd3;

    //error: cannot convert 'double*' to 'int*' in assignmen
    //pi = &dval;

    //error: cannot convert 'int*' to 'double*' in initialization
    //double *pd5 = p;

    //error: cannot convert 'int*' to 'double*' in assignmen
    //pd5 = &ival;

    return 0;
}