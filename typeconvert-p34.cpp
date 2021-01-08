#include <iostream>
#include <limits.h>
int main()
{
    unsigned int u = 10;
    /**
     *  int i = -42;
     *  When i converted to unsigned int type, the value is the same as:
     *  unsigned int i = UINT_MAX + 1 - 42;
     *  unsigned int i = -42;
     * */
    int i = -42; // The same as unsigned int i = -42;  i =-42 +max(int)
    unsigned char un = -10;
    std::cout << UINT_MAX << std::endl;
    std::cout << un + un << std::endl; //output 492
    std::cout << i + i << std::endl;   // output -84
    /**
     * type unsigned int + type int : type int have to convert to unsigned int
     * */
    std::cout << i + u << std::endl;       // output 429467264
    std::cout << (unsigned)i << std::endl; // output 4294967254
    unsigned u1 = 42, u2 = 10;
    std::cout << u1 - u2 << std::endl; //output 32
    /**
     * u2 -u1 is negative :convert to positive :
     * negative+1+MAX_UINT  (-32+1+4294967295)
     * MAX_UINT:4294967295
     * */
    std::cout << u2 - u1 << std::endl; //output 4294967264

    return 0;
}