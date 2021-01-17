#include <iostream>
#include <string>
#include <vector>
bool str_subrange(const std::string &str1, const std::string &str2)
{
    if (str1.size() == str2.size())
        return str1 == str2;
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
            //error: return-statement with no value, in function returning 'bool' [-fpermissive]
            // return;
            return false;
    }
}

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
    return (ctr > 1) ? ‘
}

const std::string &shorterString(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size() ? s1 : s2;
}

const std::string &manip()
{
    std::string ret = " hello world";
    if (!ret.empty())
        return ret;
    else
        return "Empty";
}
int main(int argc, char const *argv[])
{
    std::cout << str_subrange("hello", "he") << std::endl;
    std::cout << make_plural(2, "hello", "s").size() << std::endl; //output:6
    std::cout << shorterString("hee", "hello") << std::endl;
    std::cout << shorterString("Hebe", "wonder").size() << std::endl; //output: 4
    std::cout << manip() << std::endl;                                // output: Segmentation fault
    return 0;
}
