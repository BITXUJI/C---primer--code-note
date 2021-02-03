#include <iostream>
#include <random>
#include <cstdlib>
class numbered
{
public:
    numbered() : mysn(std::rand()) {}
    numbered(const numbered &s) : mysn(std::rand()) {}
    numbered &operator=(const numbered &s)
    {
        mysn = std::rand();
        return *this;
    }
    int mysn;
};

void f(const numbered &s) { std::cout << s.mysn << std::endl; }
int main(int argc, char const *argv[])
{
    // numbered a, b = a, c = b;
    numbered a, b, c;
    b = a;
    c = a;
    std::cout << a.mysn << " " << b.mysn << " " << c.mysn << std::endl;
    f(a);
    f(b);
    f(c);
    return 0;
}
