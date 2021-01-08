#include <iostream>
int i = 42;
int main(int argc, const char **argv)
{
    int i = 100;
    int j = i;
    std::cout << "j:" << j << std::endl;
    std::cout << "i:" << i << " global i:" << ::i << std::endl;

    int m = 100, sum = 0;
    for (int m = 0; m != 10; m++)
    {
        sum += m;
    }
    std::cout << m << " " << sum << std::endl;
    return 0;
}