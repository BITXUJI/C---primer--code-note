#include <vector>
#include "HasPtr.h"
#include <string>
#include <algorithm>
int main(int argc, char const *argv[])
{
    std::vector<HasPtr> hvec;
    HasPtr h1("hi");
    HasPtr h2("hello");
    hvec.push_back(h1);
    hvec.push_back(h2);
    std::cout << ((h1 < h2) ? "h1<h2" : "h1>h2") << std::endl;
    std::sort(hvec.begin(), hvec.end());
    for (const auto &item : hvec)
        item.show();
    return 0;
}
