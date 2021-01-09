#include <vector>
#include <string>
#include <iostream>
int main(int argc, const char **argv)
{
    std::vector<std::string> v;
    v.push_back("hello");
    v.push_back("world");
    v.push_back("!!!");
    v.push_back("I");
    for (auto i = v.begin(); i != v.end(); i++)
        std::cout << *i << std::endl;
    return 0;
}