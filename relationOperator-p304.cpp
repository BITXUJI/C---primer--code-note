#include <vector>
#include <iostream>
#include "Sales_item.h"
#include <list>
int main(int argc, char const *argv[])
{
    std::vector<int> v1 = {1, 3, 5, 7, 9, 12};
    std::vector<int> v2 = {1, 3, 9};
    std::vector<int> v3 = {1, 3, 5, 7};
    std::vector<int> v4 = {1, 3, 5, 7, 9, 12};
    std::cout << (v1 < v2) << std::endl;
    std::cout << (v1 < v3) << std::endl;
    std::cout << (v1 == v4) << std::endl;
    std::cout << (v1 == v2) << std::endl;
    std::vector<Sales_item> storeA, storeB;
    //error: no match for 'operator<' (operand types are 'const Sales_item' and 'const Sales_item')
    //    if (storeA < storeB)
    //  ;
    std::list<int> ilist1 = {1, 3, 4};
    std::vector<int> ivec1 = {1, 3, 4};
    std::vector<int> tempilist1(ilist1.begin(), ilist1.end());
    std::cout << (tempilist1 == ivec1) << std::endl;

    std::list<int> li{1, 2, 3, 4, 5};
    std::vector<int> vec2{1, 2, 3, 4, 5};
    std::vector<int> vec3{1, 2, 3, 4};

    std::cout << (std::vector<int>(li.begin(), li.end()) == vec2 ? "true" : "false") << std::endl;
    std::cout << (std::vector<int>(li.begin(), li.end()) == vec3 ? "true" : "false") << std::endl;
    return 0;
}
