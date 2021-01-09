#include <iostream>
#include <vector>
#include <string>
#include "Sales_item.h"
main()
{
    std::vector<int> ivec;
    std::vector<std::vector<std::string>> files;
    std::vector<Sales_item> Sales_vec;

    std::vector<int> ivec2(ivec);

    //error: invalid use of 'auto'
    // std::vector<auto> ivec3 = ivec;

    std::vector<int> ivec3 = ivec;

    // error: no matching function for call to 'std::vector<std::__cxx11::basic_string<char> >::vector(std::vector<int>&)'
    //std::vector<std::string> svec(ivec2);

    std::vector<std::string> articles = {"a", "an", "the"};
    std::vector<std::string> v(articles); // v=articles
    std::vector<std::string> v1{"a", "e", "u", "i", "o"};

    // error: no matching function for call to 'std::vector<std::__cxx11::basic_string<char> >::vector(const char [2], const char [2], const char [2], const char [2], const char [2])'
    // std::vector<std::string> v2("a", "e", "u", "i", "o");

    std::vector<std::string> v3(10, "c");

    // error: conversion from 'const char [2]' to non-scalar type 'std::vector<std::__cxx11::basic_string<char> >' requested
    // std::vector<std::string> v4 = (9, "c");

    //error: conversion from 'int' to non-scalar type 'std::vector<std::__cxx11::basic_string<char> >' requested
    // std::vector<std::string> v5 = 9;

    std::vector<std::string> v6(7);

    // error: no match for 'operator<<' (operand types are 'std::ostream' {aka 'std::basic_ostream<char>'} and 'std::vector<std::__cxx11::basic_string<char> >')
    // std::cout << articles << " " << v1 << " " << v3 << std::endl;

    for (auto i : articles)
        std::cout << i << std::endl;
    for (auto i : v3)
        std::cout << i << std::endl;
}