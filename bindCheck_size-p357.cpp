#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
bool check_size(std::string::size_type a, const std::string &s)
{
    return a > s.size();
}
int main(int argc, char const *argv[])
{
    std::string s = "hello";
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto iter = std::find_if(ivec.cbegin(), ivec.cend(), std::bind(check_size, std::placeholders::_1, ref(s)));
    if (iter != ivec.end())
        std::cout << *iter << std::endl;
    return 0;
}
