#include <iostream>
#include <string>
#include <vector>
// using F = int(int *, int);
// using PF = int (*)(int *, int);

using F = std::string::size_type(const std::string &, const std::string &);
using PF = std::string::size_type (*)(const std::string &, const std::string &);

std::string::size_type sumLength(const std::string &s1, const std::string &s2)
{
    return s1.size() + s2.size();
}
std::string::size_type largerLength(const std::string &s1, const std::string &s2)
{
    return s1.size() > s2.size() ? s1.size() : s2.size();
}

decltype(sumLength) *getFcn(const std::string &s)
{

    PF func;
    if (s == "largerLength")
    {
        func = largerLength;
        return func;
    }
    else if (s == "sumLength")
    {
        func = sumLength;
        return func;
    }
}

int main(int argc, char const *argv[])
{
    PF f1(int);

    //error: 'f2' declared as function returning a function
    // F f2(int);

    F *f3(int);

    int (*f4(int))(int *, int);
    auto f5(int)->int (*)(int *, int);

    auto f6 = getFcn("sumLength");
    std::cout << f6("hello", "world6") << std::endl;

    auto f7 = getFcn("largerLength");
    std::cout << f7("hello", "world6") << std::endl;
    return 0;
}
