#include <iostream>
#include <vector>
#include <string>
std::vector<std::string> process()
{
    std::string expected = "hello";
    std::string actual = "hello";
    if (expected.empty())
        return {};
    else if (expected == actual)
    {
        return {"functionX", "okey"};
    }
    else
    {
        return {"functionX", expected, actual};
    }
}
int main(int argc, char const *argv[])
{
    std::vector<std::string> s1;
    s1 = process();
    for (auto c : s1)
        std::cout << c << std::endl;

    return 0;
}
