#include <string>
#include <iostream>
std::string prefixforefix(std::string s, const std::string &prefix, const std::string &forefix)
{
    s.insert(s.begin(), prefix.cbegin(), prefix.cend());
    s.append(forefix.cbegin(), forefix.cend());
    return s;
}
// string add_pre_and_suffix(string name, string const &pre, string const &su)
// {
//     name.insert(name.begin(), pre.cbegin(), pre.cend());
//     return name.append(su);
// }

int main(int argc, char const *argv[])
{
    std::string name = " Smith ";
    std::cout << prefixforefix(name, "Mr.", "Jr.") << std::endl;

    return 0;
}
