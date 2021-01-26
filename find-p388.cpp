#include <map>
#include <set>
#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::set<int> iset = {9, 8, 10, 1, 2, 3, 4, 5, 6, 7};
    auto iter1 = iset.find(1);
    auto iter2 = iset.find(19);
    auto iter3 = iset.count(5);
    auto iter4 = iset.count(17);
    for (const auto &item : iset)
        std::cout << item << " ";
    std::cout << std::endl;
    for (auto item = iset.cbegin(); item != iset.cend(); ++item)
        std::cout << *item << " ";
    std::cout << std::endl;
    // error: operands to ?: have different types 'const char*' and 'int'
    std::cout << *iter1 << std::endl;
    std::cout << ((iter2 == iset.end()) ? "Not found" : "found") << std::endl;
    std::cout << iter3 << " " << iter4 << std::endl;
    return 0;
}
