// example.h
#include <vector>
#include <iostream>
class Example
{
public:
    static double rate;
    static const int vecSize = 20;
    static std::vector<double> vec;
};

// example.C
//#include "example.h"
double Example::rate = 5.0;
std::vector<double> Example::vec(Example::vecSize, 1.1);
int main(int argc, char const *argv[])
{
    Example a;
    std::cout << a.rate << std::endl;
    std::cout << a.vecSize << std::endl;
    for (auto i : a.vec)
        std::cout << i << std::endl;
    return 0;
}
