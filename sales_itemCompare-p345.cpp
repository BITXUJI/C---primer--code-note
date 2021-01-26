#include "Sales_item.h"
#include <vector>
#include <iostream>
#include <algorithm>

bool isGreater(const Sales_item &s1, const Sales_item &s2)
{
    return s1.isbn < s2.isbn;
}

int main(int argc, char const *argv[])
{
    std::vector<Sales_item> svec;
    svec.emplace_back("111");
    svec.emplace_back("222");
    svec.emplace_back("11");
    std::sort(svec.begin(), svec.end(), isGreater);
    for (const auto &item : svec)
        std::cout << item << " " << std::endl;
    return 0;
}
