#include <iostream>
#include <cassert>
void f()
{
    std::cout << "void f()" << std::endl;
}
void f(int i)
{
    std::cout << "void f(int)" << std::endl;
}
void f(int i, int j)
{
    std::cout << "void f(int, int)" << std::endl;
}
void f(double i, double j = 3.14)
{
    std::cout << "void f(double,double=3.14)" << std::endl;
}
int main(int argc, char const *argv[])
{

    f(42);
    f(43, 0);
    f(2.56, 3.14);
    //error: call of overloaded 'f(double, int)' is ambiguous
    // f(2.56, 42);
    return 0;
}
