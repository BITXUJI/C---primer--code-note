#include <iostream>
#include <vector>
#include <string>
void reset(int &i)
{
    i = 0;
}
bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}
int main(int argc, char const *argv[])
{
    int j = 42;
    reset(j);
    std::cout << "j=" << j << std::endl;

    return 0;
}
