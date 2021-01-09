#include <iostream>
#include <string>
#include <vector>
#include <cctype>
main()
{
    std::vector<int> v1(10);
    std::vector<int> v2{10};
    std::vector<int> v3{10, 1};
    std::vector<int> v4(10, 1);
    std::vector<int> v5 = {10, 1};
    std::vector<std::string> v6{"hello"};

    //error: no matching function for call to 'std::vector<std::__cxx11::basic_string<char> >::vector(const char [3])'
    // std::vector<std::string> v7("hi");

    std::vector<std::string> v7(10, "hi");
    std::vector<std::string> v8{10};
    std::vector<std::string> v9(10);
    std::vector<std::string> v10{10, "hi"};
    std::vector<std::string> v11 = {10, "hi"};

    //error: no matching function for call to 'std::vector<std::__cxx11::basic_string<char> >::vector(<brace-enclosed initializer list>)'
    // std::vector<std::string> v12{10, (10, 'c')};

    //error: no matching function for call to 'std::vector<std::__cxx11::basic_string<char> >::vector(int, char)'
    // std::vector<std::string> v12(10, (10, 'c'));

    //error: conversion from 'const char [3]' to non-scalar type 'std::vector<std::__cxx11::basic_string<char> >' requested
    // std::vector<std::string> v12 = (10, "Hi");

    std::string s1("hello");  //hello
    std::string s2{"hello"};  //hello
    std::string s3 = "hello"; //hello

    //error: no matching function for call to 'std::__cxx11::basic_string<char>::basic_string(int, const char [6])'
    // std::string s4(10, "Hello");

    std::string s4(10, 'c'); //cccccccccc
    std::string s5{10, 'd'}; //d

    //error: no matching function for call to 'std::__cxx11::basic_string<char>::basic_string(int, const char [2])'
    // std::string s5(10, "c");

    std::vector<std::string> v13{10, s4};
    std::vector<std::string> v14(v13);
    std::vector<std::string> v15 = v13;
    std::vector<std::string> v16{v13};
    for (auto i : v16)
        std::cout << i << std::endl;
    std::cout
        << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << std::endl;
}