#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char **argv)
{
    int grade;
    std::cin >> grade;
    std::string finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
    std::cout << finalgrade << std::endl;

    std::cout << ((grade < 60) ? "fail" : "pass") << std::endl;
    // std::cout << (grade < 60) ? "fail" : "pass";
    //std::cout << grade < 60 ? "fail" : "pass";

    std::string s = "word";

    //no match for 'operator==' (operand types are 'std::__cxx11::basic_string<char>' and 'char')
    // std::string pl = s + s[s.size() - 1] == 's' ? "" : "s";

    std::string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
    std::cout << pl << std::endl;
    return 0;
}