#include <iostream>
#include <limits.h>
int main(int argc, const char **argv)
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl; //output 32
    std::cout << u - u2 << std::endl; // output 4294967264
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; // output 32
    std::cout << i - i2 << std::endl; // output -32
    std::cout << i - u << std::endl;  // output 0
    std::cout << u - i << std::endl;  // output 0
    return 0;
}