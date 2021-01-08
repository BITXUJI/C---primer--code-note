#include <iostream>
int main(int argc, const char **argv)
{
    /**
     * List initialization {}
     * 
     * */
    int units_sold = 0;
    std::cout << units_sold << std::endl;
    int units_sold1 = {1};
    std::cout << units_sold1 << std::endl;
    int units_sold2{2};
    std::cout << units_sold2 << std::endl;
    int units_sold3(3);
    std::cout << units_sold3 << std::endl;
    long double ld = 3.14159265352;
    int a{ld}, b = {ld};
    int c(ld), d = ld;
    std::cout << " a:" << a << " b:" << b << " c:" << c << " d:" << d << std::endl;

    /**
     * test
     * */

    std::cin >> int inpu_value; // expected primary-expression before 'int'
    // int i = {3.14}; //narrowing conversion of '3.1400000000000001e+0' from 'double' to 'int' [-Wnarrowing]
    double salary = wage = 9999.99; //'wage' was not declared in this scoped
    int j = 3.14;

    return 0;
}