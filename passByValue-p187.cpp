#include <iostream>
#include <string>
#include <vector>
void reset(int *ip)
{
    *ip = 0;
    ip = 0;
}

void swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
int main(int argc, char const *argv[])
{
    int i = 43;
    reset(&i);
    std::cout << i << std::endl;
    int v1 = 32;
    int v2 = 10;
    swap(&v1, &v2);
    std::cout << v1 << " " << v2 << std::endl;
    return 0;
}
