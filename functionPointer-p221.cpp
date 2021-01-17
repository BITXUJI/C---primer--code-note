#include <iostream>
#include <string>
#include <vector>
bool lengthCompare(const std::string &str1, const std::string &str2)
{
    return str1.size() == str2.size();
}
std::string::size_type sumLength(const std::string &, const std::string &);
bool cstringCompare(const char *, const char *);

void ff(int *);
void ff(unsigned int);

int main(int argc, char const *argv[])
{

    // bool (*pf)(const std::string &str1, const std::string &str2)
    // {
    //     return str1.size() == str2.size();
    // }

    auto pf = lengthCompare;
    pf = &lengthCompare;
    bool b1 = pf("hello", "world");
    bool b2 = (*pf)("hello", "world");
    bool b3 = lengthCompare("hello", "world");
    pf = 0;

    // error: invalid conversion from 'std::__cxx11::basic_string<char>::size_type (*)(const string&, const string&)'
    //{aka 'unsigned int (*)(const std::__cxx11::basic_string<char>&, const std::__cxx11::basic_string<char>&)'}
    //to 'bool (*)(const std::__cxx11::basic_string<char>&, const std::__cxx11::basic_string<char>&)' [-fpermissive]
    // pf = sumLength;

    //  error: invalid conversion from 'bool (*)(const char*, const char*)' to 'bool (*)(const std::__cxx11::basic_string<char>&, const std::__cxx11::basic_string<char>&)' [-fpermissive]
    // pf = cstringCompare;

    pf = lengthCompare;

    void (*pf1)(unsigned int) = ff;

    // error: no matches converting function 'ff' to type 'void (*)(int)'
    // void (*pf2)(int) = ff;

    void (*pf3)(int *) = ff;

    return 0;
}
