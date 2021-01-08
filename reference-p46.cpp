#include <iostream>
/**
 * When variable declared as reference, it must be initialized and bind to the object of the same type.
 *  If the object is not the same type ,then it will be converted to an Rvalue of the same tpye,then raise an error.
 * After variable declared as reference, you can do anything to it just as you do that to the orignal object which it binds.
 * 
 * */

int main(int argc, const char **argv)
{
    int ival = 1.01;
    //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //int &rval1 = 1.01;
    int &rval2 = ival;
    // error: 'rval3' declared as reference but not initialized
    //int &rval3;

    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    //error: cannot bind non-const lvalue reference of type 'double&' to an rvalue of type 'double'
    //double &r3 = i;
    /**
     * All bellow are OK implies that:
     * Reference declaration and initialization is the most important thing.
     * Assignment operations after initialization are not feasible to faults.
     * */
    r2 = 3.141592653; // OK
    r2 = r1;          //OK
    i = r2;           // OK
    r1 = d;           // OK

    int i1, &ri1 = i1;
    i1 = 5;
    ri1 = 10;
    std::cout << i1 << " " << ri1 << std::endl; //10 10
    return 0;
}