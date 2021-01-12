#include <string>
#include <iostream>
#include <vector>

int main(int argc, const char **argv)
{
    std::string s1 = "a string", *p = &s1;
    auto n = s1.size();
    n = (*p).size();
    n = p->size();
    std::vector<std::string>::iterator iter;
    std::vector<std::string> strvec{"hello", "world", "i", "am", "coming", "1", "2", "3"};
    iter = strvec.begin();
    std::cout << *iter++ << std::endl;

    // error: no 'operator++(int)' declared for postfix '++' [-fpermissive]
    // std::cout << (*iter)++ << std::endl;

    // error: 'std::vector<std::__cxx11::basic_string<char> >::iterator'
    // {aka 'class __gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char>*, std::vector<std::__cxx11::basic_string<char> > >'}
    // has no member named 'empty'
    // std::cout << *iter.empty() << std::endl;

    std::cout << iter->empty() << std::endl;

    // error: no match for 'operator++' (operand type is 'std::__cxx11::basic_string<char>')
    // std::cout << ++*iter << std::endl;

    std::cout << iter++->empty() << std::endl;
    return 0;
}