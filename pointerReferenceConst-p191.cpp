#include <iostream>
#include <string>
#include <vector>
void reset(int *ip)
{
    *ip = 0;
    ip = 0;
}
void reset(int &i)
{
    i = 0;
}

void f1(const int &i)
{
    std::cout << i << std::endl;
}
void f2(int i)
{
    std::cout << i << std::endl;
}

void f3(int &i)
{
    std::cout << i << std::endl;
}
int main(int argc, char const *argv[])
{
    int i = 0;
    const int ci = i;
    std::string::size_type ctr = 0;
    reset(&i);

    //error: no matching function for call to 'reset(const int*)'
    //error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
    //error: invalid conversion from 'const int*' to 'int' [-fpermissive]
    // reset(&ci);

    reset(i);

    //error: cannot bind rvalue '(int)(& ci)' to 'int&'
    // error: binding reference of type 'int&' to 'const int' discards qualifiers
    //reset(ci);

    //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    // reset(43);

    //error: no matching function for call to 'reset(std::__cxx11::basic_string<char>::size_type&)'
    //error: invalid conversion from 'std::__cxx11::basic_string<char>::size_type' {aka 'unsigned int'} to 'int*' [-fpermissive]
    //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //reset(ctr);
    const int i1 = 5;
    double j = 5.4;
    const double k = 6.7;
    f1(1);  //1
    f1(i1); //5
    f1(j);  //5
    f1(k);  //6
    f2(1);  //1
    f2(i1); //5
    f2(j);  //5
    f2(k);  //6

    // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    // f3(1);

    //error: binding reference of type 'int&' to 'const int' discards qualifiers
    // f3(i1);

    //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    // f3(j);

    //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    // f3(k);

    return 0;
}
