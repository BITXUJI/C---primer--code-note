#include <iostream>
int main(int argc, const char **argv)
{
    int a = 3, b = 4;                                                //a:int b:int
    decltype(a) c = a;                                               //c:int
    decltype((b)) d = a;                                             //d: int&
    ++c;                                                             //c =4
    ++d;                                                             //d =4 a=4
    std::cout << a << " " << b << " " << c << " " << d << std::endl; // output: 4 4 4 4
    decltype(a = b + 1) e = a;                                       // e :int &
    std::cout << e << std::endl;                                     //output:4
    return 0;
}