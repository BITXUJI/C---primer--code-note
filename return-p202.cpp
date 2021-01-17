#include <iostream>
#include <string>
#include <vector>
char &get_val(std::string &str, std::string::size_type ix)
{
    return str[ix];
}

char get_val1(std::string &str, std::string::size_type ix)
{
    return str[ix];
}

int main(int argc, char const *argv[])
{
    std::string s("a value");
    std::cout << s << std::endl;
    get_val(s, 0) = 'A';
    std::cout << s << std::endl;

    // error: lvalue required as left operand of assignment
    // get_val1(s, 0) = 'B';

    std::cout << get_val1(s, 0) << std::endl;
    return 0;
}
