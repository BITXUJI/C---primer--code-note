// example.h
#include <vector>
class Example
{
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static std::vector<double> vec;
};

// example.C
//#include "example.h"
constexpr double Example::rate;
std::vector<double> Example::vec(Example::vecSize);