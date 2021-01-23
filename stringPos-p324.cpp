#include <string>
#include <iostream>
void stringReplace(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    auto oldValSize = oldVal.size();
    for (std::string::size_type i = 0; i < s.size() - oldValSize;)
    {
        if (s.substr(i, oldValSize) == oldVal)
        {
            s.replace(i, oldValSize, newVal);
            i += newVal.size();
        }
        else
        {
            ++i;
        }
    }
}
int main(int argc, char const *argv[])
{
    std::string s = "this is a test: tho i am i tho o";
    stringReplace(s, "tho", "though");
    std::cout << s << std::endl;
    return 0;
}
