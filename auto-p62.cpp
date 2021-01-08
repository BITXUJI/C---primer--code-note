#include <iostream>
/**
 * Summary:
 *  Auto ignore toplevel const and reserve lowlevel const.
 * 
 * */
int main(int argc, const char **argv)
{
    int i = 0, &r = i;
    auto a = r; // a: int
    const int ci = i, &cr = ci;
    auto b = ci;       //b: int
    auto c = cr;       //c:int
    auto d = &i;       //d:int *
    auto e = &ci;      //e:const int*
    const auto f = ci; //f:const int
    auto &g = ci;      //g:const int&

    //error: binding reference of type 'int&' to 'const int' discards qualifiers
    //int &k = ci;    //k: int&

    // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    // auto &h = 42;  //h:int&

    const auto &j = 42;     //j:const int&
    auto k = ci, &l = i;    //k:int l:const int&
    auto &m = ci, *p = &ci; //m:const int& p:const int*

    // error: inconsistent deduction for 'auto': 'int' and then 'const int'
    // auto &n = i, *p2 = &ci; //n: int  p2: const int *

    a = 42; //a :int
    b = 42; //b:int
    c = 42; //c:int

    // error: invalid conversion from 'int' to 'int*' [-fpermissive]
    // d = 42;//d:int*

    //error: invalid conversion from 'int' to 'const int*' [-fpermissive]
    // e = 42; //e:const int*

    // error: assignment of read-only reference 'g'
    // g = 42; //g:const int&

    return 0;
}