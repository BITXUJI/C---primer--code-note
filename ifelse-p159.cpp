#include <string>
#include <iostream>
#include <vector>
int main(int argc, char const *argv[])
{
    int ival1 = 1, ival2 = 2;
    if (ival1 != ival2)
        ival1 = ival2;
    else
        ival1 = ival2 = 0;

    int ival = 0, minval = 1, occurs;
    if (ival < minval)
    {
        minval = ival;
        occurs = 1;
    }
    int get_values();
    int ival3;
    if (ival3 = get_values())
    {
        std::cout << "ival3= " << ival3 << std::endl;
    }
    if (!ival3)
    {
        std::cout << "ival3 =0\n";
    }
    if (ival == 0)
        ival = get_values();
    return 0;
}

int get_values()
{
    return 5;
}