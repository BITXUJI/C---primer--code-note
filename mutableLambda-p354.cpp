#include <iostream>
int main(int argc, char const *argv[])
{
    int a = 0;
    auto f = [a]() mutable -> bool {if(a){--a;return false;}else return true; };
    std::cout << f() << std::endl;
    //...
    int i = 10;
    auto f1 = [&i]() -> bool { return (i == 0 ? true : !(i--)); };
    while (!f1())
        cout << i << endl;
    return 0;
}
