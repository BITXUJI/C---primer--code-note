#include <string>
#include <iostream>
std::string prefixAndForefix(std::string s, const std::string &prefix, const std::string &forefix)
{

    s.insert(0, prefix);
    s.insert(s.size(), forefix);
    return s;
}
int main(int argc, char const *argv[])
{
    std::string name = " Smith ";
    std::cout << prefixAndForefix(name, "Mr.", "Jr.") << std::endl;
    return 0;
}
