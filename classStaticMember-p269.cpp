#include "Account.h"
#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    Account a;
    std::string b;
    double c;
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(c) << std::endl;

    double r;

    r = Account::rate();
    std::cout << r << std::endl;
    Account ac1;
    Account *ac2 = &ac1;
    r = ac1.rate();
    std::cout << r << std::endl;
    r = ac2->rate();
    std::cout << r << std::endl;
    return 0;
}
