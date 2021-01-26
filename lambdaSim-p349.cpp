#include <iostream>
int example(int sz)
{

    return [sz](int a) { return a + sz; }(10);
}
int main(int argc, char const *argv[])
{
    auto f = [](int a, int b) { return a + b; };
    std::cout << f(1, 2) << std::endl;
    std::cout << [](int a, int b) { return a + b; }(3, 5) << std::endl;
    std::cout << example(3) << std::endl;
    return 0;
}
