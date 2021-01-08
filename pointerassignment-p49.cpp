#include <iostream>
int main(int argc, const char **argv)
{
    int i = 42;
    int *pi = 0;   //int &ri = 0 ; is error
    int *pi2 = &i; //int &ri2 = i; is ok
    int *pi3;      // int &ri3; is error
    pi3 = pi2;
    pi2 = 0;

    int ival;
    pi = &ival;
    *pi = 0;
    std::cout << ival << " " << *pi << std::endl;
    pi = 0;
    if (!pi)
    {
        std::cout << "Pointer pi is nullptr" << std::endl;
    }

    return 0;
}