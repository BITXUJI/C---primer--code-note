#include "Quote.h"
#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    Quote q1("111", 5);
    print_total(std::cout, q1, 5);
    Bulk_quote q2("111", 5, 3, 0.5);
    print_total(std::cout, q2, 5);
    Quote &q3 = q2;
    q3.debug(std::cout);
    return 0;
}
