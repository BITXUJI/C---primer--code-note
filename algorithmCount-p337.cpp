#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
int main(int argc, char const *argv[])
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 7, 8, 8, 9, 1};
    int val = 7;
    auto intcount = std::count(vec.cbegin(), vec.cend(), val);
    std::cout
        << intcount << std::endl;
    std::list<std::string> li = {"hello", "world", "hello", "people", "hello"};
    std::string sval = "hello";
    auto scount = std::count(li.cbegin(), li.cend(), sval);
    std::cout << scount << std::endl;
    return 0;
}
