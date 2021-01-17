#include <iostream>
#include <string>
#include <vector>
bool lengthCompare(const std::string &s1, const std::string &s2)
{
    return s1.size() > s2.size();
}

typedef bool Func(const std::string &, const std::string &);
typedef decltype(lengthCompare) Func2;

typedef bool (*FuncP)(const std::string &, const std::string &);
typedef decltype(lengthCompare) *FuncP2;

void useBigger(const std::string &s1, const std::string &s2, Func func1)
{
    //error: expression list treated as compound expression in functional cast [-fpermissive]
    std::cout << "Is the length of s1 greater than s2? The result is " << func1(s1, s2) << std::endl;
}
// void useBigger(const std::string &s1, const std::string &s2, bool pf(const std::string &, const std::string &))
// {
//     std::cout << "Is the length of s1 greater than s2? The result is " << pf(s1, s2) << std::endl;
// }
//void useBigger(const std::string &s1, const std::string &s2, bool (*pf)(const std::string &, const std::string &));
int main(int argc, char const *argv[])
{
    useBigger("hello", "world", lengthCompare);
    return 0;
}
