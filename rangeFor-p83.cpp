#include <iostream>
#include <string>
#include <cctype>
int main(int argc, const char **argv)
{
    std::string s1("Hello World!!!");
    decltype(s1.size()) punct_cnt = 0;
    for (auto c : s1)
    {
        if (std::ispunct(c))
        {
            ++punct_cnt;
        }
    }
    std::cout << punct_cnt
              << " punctuation character in " << s1 << std::endl;
    return 0;
}