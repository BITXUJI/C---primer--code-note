#include <iostream>

main()
{
    bool b = 42;
    std::cout << "bool b = 42 b:" << b << std::endl;
    int i = b;
    std::cout << "int i =b i:" << i << std::endl;
    i = 3.14;
    std::cout << "i =3.14 i:" << i << std::endl;
    double pi = i;
    std::cout << "double pi =i  pi:" << (double)pi << std::endl;
    /**
     * When a number over a unsigned type range 
     *  :number mod rang_max
     * When a number over a signed type range 
     *  :undefined (you don't know what will happen)
     * */
    unsigned char c = 10000;
    std::cout << "u_char c =10000 c:" << (int)c << std::endl;
    signed char c2 = 10000;
    std::cout << "u_char c2=10000 c2:" << (int)c2 << std::endl;
}