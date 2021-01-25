#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
bool check_size(const std::string &s, const std::string::size_type sz)
{
    return s.size() <= sz;
}

std::ostream &print(std::ostream &os, const std::string &s, char c)
{
    return os << s << c;
}
int main(int argc, char const *argv[])
{
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    auto wc = std::count_if(words.cbegin(), words.cend(), std::bind(check_size, std::placeholders::_1, 6));
    std::for_each(words.cbegin(), words.cend(), std::bind(print, ref(std::cout), std::placeholders::_1, ' '));
    std::cout << std::endl;
    std::cout << wc << std::endl;
    return 0;
}
