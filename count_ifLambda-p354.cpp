#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<std::string> svec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto sz = std::count_if(svec.cbegin(), svec.cend(),
                            [](const std::string &s) { return s.size() > 5; });
    std::cout << sz << std::endl;
    return 0;
}
