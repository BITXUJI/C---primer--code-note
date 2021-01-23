#include <string>
#include <vector>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::vector<char> vc = {'a', 'b', 'c'};
    std::string st(vc.cbegin(), vc.cend());
    std::cout << st << std::endl;
    return 0;
}
