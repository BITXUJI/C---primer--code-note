#include <Vector>
#include <algorithm>
#include <iostream>
#include <string>
template <typename T>
std::size_t countValue(const std::vector<T> &vec, T vl)
{
    auto number = std::count(vec.cbegin(), vec.cend(), vl);
    return number;
}

template <>
std::size_t countValue(const std::vector<const char *> &vec, const char *vl)
{
    auto number = std::count(vec.cbegin(), vec.cend(), vl);
    return number;
}

int main(int argc, char const *argv[])
{
    std::vector<double> dvec = {1.0, 2.2, 4.5, 2.2, 3.2};
    double d = 2.2;
    std::cout << countValue(dvec, d) << std::endl;
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int i = 9;
    std::cout << countValue(ivec, i) << std::endl;
    std::vector<std::string> svec = {"111", "222", "111"};
    std::string str = "111";
    std::cout << countValue(svec, str) << std::endl;
    std::vector<const char *> ccvec = {"111", "222", "111"};
    const char *cc = "111";
    std::cout << countValue(ccvec, cc) << std::endl;
    return 0;
}
