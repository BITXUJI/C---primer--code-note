#include <numeric>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <deque>
int main(int argc, char const *argv[])
{
    std::vector<std::string> svec = {"hello", "world", "yes"};
    std::list<const char *> cli = {"hello", "world", "yes", "ma"};
    std::deque<const char *> cde = {"hello", "world", "yes", "ma"};
    auto result = std::equal(svec.cbegin(), svec.cend(), cli.cbegin());
    auto result1 = std::equal(cli.cbegin(), cli.cend(), cde.cbegin());
    std::cout << ((result == 0) ? "false" : "true") << std::endl;
    std::cout << ((result1 == 0) ? "false" : "true") << std::endl;
    return 0;
}
