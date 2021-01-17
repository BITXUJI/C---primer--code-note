#include <initializer_list>
#include <iostream>
void print(std::initializer_list<int> li)
{
    for (auto i = li.begin(); i != li.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
}
void printsum(std::initializer_list<int> il)
{
    int sum = 0;
    // for (auto i = il.begin(); i != il.end(); ++i)
    // {
    //     sum += *i;
    // }
    for (const auto &i : il)
        sum += i;
    std::cout << sum << std::endl;
}
int main(int argc, char const *argv[])
{
    int a = 5;
    int b[2] = {3, 4};
    //print({a, *b, *(b + 1), *(b + 2), *(b + 3), *(b + 4), *(b + 5), *(b + 6), *(b + 7), *(b + 8), *(b + 9)});
    printsum({a, *b});
    return 0;
}
