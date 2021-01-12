#include <string>
#include <vector>
#include <iostream>
int main(int argc, char const *argv[])
{
    int val[] = {5, 6, 7, 8, 9};
    int *ptr = val;
    std::vector<int> vec{1, 2, 3, 4};
    int ival = 0;
    if (ptr != 0 && *ptr++)
    {
        std::cout << *ptr << std::endl;
    }
    if (ival++ || ival)
    {
        std::cout << ival << std::endl;
    }
    if (vec[ival++] <= vec[ival])
    {
        std::cout << vec[ival] << std::endl;
    }

    return 0;
}
