/**
 * g++ -std=c++11 StrVecExample.cpp StrVec.cpp
 * ./a.out
 * */
#include "StrVec.h"
#include <string>
#include <iostream>
#include <memory>
int main(int argc, char const *argv[])
{
    StrVec vec;
    vec.push_back("hello");
    vec.push_back("world");
    StrVec vec1 = vec;
    StrVec vec2;
    vec2 = vec;
    std::size_t n =5;
    vec2.resize(n);
    std::cout << vec.size() << std::endl;
    std::cout << vec.capacity() << std::endl;
    std::cout << vec1.size() << std::endl;
    std::cout << vec1.capacity() << std::endl;
    std::cout << vec2.size() << std::endl;
    std::cout << vec2.capacity() << std::endl;
    return 0;
}
