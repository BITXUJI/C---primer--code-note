#include <string>
#include <iostream>
void replaceString(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    auto oldValSize = oldVal.size();
    auto iter = s.begin();
    while (iter != s.end() - oldValSize)
    {
        if (std::string(iter, iter + oldValSize) == oldVal)
        {

            iter = s.erase(iter, iter + oldValSize);
            iter = s.insert(iter, newVal.cbegin(), newVal.cend());
            iter += newVal.size();
        }
        else
            ++iter;
    }
}

int main(int argc, char const *argv[])
{
    std::string s = "this is a test: tho i am i tho o";
    replaceString(s, "tho", "though");
    std::cout << s << std::endl;
    return 0;
}
