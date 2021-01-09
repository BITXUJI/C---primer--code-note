#include <iostream>
#include <string>
#include <cctype>

int main(int argc, const char **argv)
{
    std::string s("Hello World!!!");
    for (auto &c : s)
    {
        c = toupper(c);
    }
    std::cout << s << std::endl;

    std::string s1("some string");
    if (!s1.empty())
    {
        s1[0] = toupper(s1[0]); //s1[0] is the reference to the first char of string s1;
    }
    std::cout << s1 << std::endl;

    for (decltype(s1.size()) index = 0; index != s1.size() && !std::isspace(s1[index]); index++)
    {
        s1[index] = toupper(s1[index]);
    }
    std::cout << s1 << std::endl;
    return 0;
}