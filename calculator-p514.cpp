#include <functional>
#include <iostream>
#include <map>
#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    std::map<std::string, std::function<int(int, int)>> oprtr = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"/", [](int a, int b) { return a / b; }},
        {"%", [](int a, int b) { return a % b; }}};

    std::string lhs, op, rhs;
    std::cin >> lhs >> op >> rhs;
    std::cout << oprtr[op](std::stoi(lhs), std::stoi(rhs)) << std::endl;
    return 0;
}
