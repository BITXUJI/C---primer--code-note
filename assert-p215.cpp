// #define NDEBUG
#include <iostream>
#include <cassert>
void print(const int ia[], size_t size)
{
#ifndef NDEBUG
    std::cerr << __func__ << ":array size is " << size << std::endl
              << "          at file named :" << __FILE__ << std::endl
              << "          at line " << __LINE__ << std::endl
              << "  Compile on " << __DATE__ << std::endl
              << "          at " << __TIME__ << std::endl
              << std::endl;
#endif // !NDEBUG
}
int main(int argc, char const *argv[])
{
    int ia[2] = {1, 2};
    print(ia, 2);
    assert(1 == 2);
    assert(2 == 2);
    std::cout << "hello world" << std::endl;
    return 0;
}
