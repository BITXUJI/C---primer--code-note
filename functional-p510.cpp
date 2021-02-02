#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>
int main(int argc, char const *argv[])
{
    // std::vector<int> ivec = {2, 4, 6, 8};
    // auto pos = std::find_if(ivec.cbegin(), ivec.cend(), std::bind(std::modulus<int>(), std::placeholders::_1, 2));
    // if (pos == ivec.cend())
    //     std::cout << "true" << std::endl;
    // else
    // {
    //     std::cout << "false" << std::endl;
    // }
    auto data = {2, 3, 4, 5};
    int input;
    std::cin >> input;
    std::modulus<int> mod;
    auto predicator = [&](int i) { return 0 == mod(input, i); };
    auto is_divisible = std::any_of(data.begin(), data.end(), predicator);
    std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;

    return 0;
    return 0;
}
