#include "Vec.h"
#include <iostream>
#include <utility>
int main(int argc, char const *argv[])
{
    Vec<int> ivec;
    ivec.push_back(1);
    std::cout << ivec.size() << " " << ivec.capacity() << std::endl;
    ivec.push_back(2);
    std::cout << ivec.size() << " " << ivec.capacity() << std::endl;
    Vec<int> ivec2 = std::move(ivec);
    ivec2.push_back(4);
    Vec<int> ivec3;
    ivec3 = std::move(ivec2);
    std::cout << ivec2.size() << " " << ivec2.capacity() << std::endl;
    std::cout << ivec3.size() << " " << ivec3.capacity() << std::endl;
    return 0;
}
