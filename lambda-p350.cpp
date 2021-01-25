#include <iostream>
void fcn1()
{
    size_t v1 = 42;
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();
    std::cout << j << std::endl;
}

void fcn2()
{
    size_t v1 = 42;
    auto f = [&v1] { return v1; };
    v1 = 0;
    auto j = f();
    std::cout << j << std::endl;
}

void fcn3()
{
    size_t v1 = 42;
    auto f = [v1]() mutable { return ++v1; };
    v1 = 0;
    auto j = f();
    std::cout << j << std::endl;
}
void fcn4()
{
    size_t v1 = 42;
    auto f = [&v1] { return ++v1; };
    v1 = 0;
    auto j = f();
    std::cout << j << std::endl;
}
int main(int argc, char const *argv[])
{
    fcn1(); //42
    fcn2(); //0
    fcn3(); //43
    fcn4(); //1
    return 0;
}
