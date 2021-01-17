#include <string>
#include <vector>
#include <iostream>
/**
 * find_char: find a char 
 * s:string
 * c:char
 * occurs: times
 * */
std::string::size_type find_char(const std::string &s, char c, std::string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            // if (ret == s.size())
            //     ret = i;
            if (occurs == 0)
                ret = i;
            ++occurs;
        }
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    std::string s = "heeelleed";
    char c = 'l';
    std::string::size_type occurs = 0;
    auto i = find_char(s, c, occurs);
    std::cout << "in this string:" << s << " there is " << occurs << " " << c << " first time is " << i << std::endl;
    return 0;
}
