#include <iostream>
#include <string>
#include <vector>

main()
{
    std::vector<std::string> v1;
    v1.push_back("hello");
    v1.push_back("hewlo");
    v1.push_back("hellq");
    v1.push_back("HEE");
    v1.push_back("world");
    for (auto it = v1.cbegin(); it != v1.cend(); it++)
    {
        std::cout << it->size() << std::endl;
        std::cout << *it << std::endl;

        //error: 'class __gnu_cxx::__normal_iterator<const std::__cxx11::basic_string<char>*, std::vector<std::__cxx11::basic_string<char> > >' has no member named 'size'
        // std::cout << *it.size() << std::endl;
        }
}