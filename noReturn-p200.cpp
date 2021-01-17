#include <iostream>
void swap(int &v1, int &v2)
{
    if (v1 == v2)
        return;
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
    return;
}
int main(int argc, char const *argv[])
{
    int a = 5, b = 3;
    swap(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}
