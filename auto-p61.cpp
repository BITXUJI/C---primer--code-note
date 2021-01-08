#include <iostream>
int main(int argc, const char **argv)
{

    auto i = 0, *p = &i;

    //error: inconsistent deduction for 'auto': 'int' and then 'double'
    // auto sz = 0, pi = 3.14;

    return 0;
}