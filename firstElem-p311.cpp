#include <vector>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::vector<int> v = {1, 2};
    auto a = v[0];
    auto b = v.at(0);
    auto c = *v.begin();
    auto d = v.front();
    auto e = v.back();
    auto f = v.end();
    auto g = *(--f);
    std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;
    return 0;
}
