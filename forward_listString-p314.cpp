#include <forward_list>
#include <string>
#include <iostream>

void insertString(std::forward_list<std::string> &strfl, const std::string &s1, const std::string &s2)
{
    auto prev = strfl.before_begin();
    auto curr = strfl.begin();
    while (curr != strfl.end())
    {
        if (*curr == s1)
        {
            strfl.insert_after(curr, s2);
            return;
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }
    if (curr == strfl.end())
    {
        strfl.insert_after(prev, s2);
        return;
    }
}

int main(int argc, char const *argv[])
{
    std::string s1 = "hello";
    std::string s2 = "world";
    std::forward_list<std::string> fl = {"yes", "no"};
    for (const auto &i : fl)
        std::cout << i << " ";
    std::cout << std::endl;
    insertString(fl, s1, s2);
    for (const auto &i : fl)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
