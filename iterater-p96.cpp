#include <vector>
#include <iostream>
#include <string>

main()
{
    std::vector<int>::iterator iter;
    std::vector<int> v;
    v.push_back(19);
    v.push_back(12);
    v.push_back(14);
    v.push_back(17);
    v.push_back(18);
    for (iter = v.begin(); iter != v.end(); iter++)
        *iter += 10;
    for (auto &i : v)
        i++;
    for (auto i : v)
        std::cout << i << std::endl;
    const std::vector<int> v1{1, 3, 4, 5};

    //error: conversion from '__normal_iterator<const int*,[...]>' to non-scalar type '__normal_iterator<int*,[...]>' requested
    // for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++)

    for (std::vector<int>::const_iterator i = v1.begin(); i != v1.end(); i++)
        std::cout << *i << std::endl;

    for (auto i = v1.begin(); i != v1.end(); i++)
        std::cout << *i << std::endl;

    //error: assignment of read-only location 'i.__gnu_cxx::__normal_iterator<const int*, std::vector<int> >::operator*()'
    //*i += 1;

    const std::string s1("hello wordl");

    //error: conversion from '__normal_iterator<const char*,[...]>' to non-scalar type '__normal_iterator<char*,[...]>' requested
    // for (std::string::iterator i = s1.begin(); i != s1.end(); i++)
    for (std::string::const_iterator i = s1.begin(); i != s1.end(); i++)
        std::cout << *i << std::endl;

    for (auto i = s1.begin(); i != s1.end(); i++)
        std::cout << *i << std::endl;
}