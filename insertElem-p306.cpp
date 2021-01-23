#include <vector>
#include <list>
#include <string>
#include <deque>
#include <forward_list>
#include <array>
#include <iostream>
void pluralize(size_t cnt, std::string &word)
{
    if (cnt > 1)
        word.push_back('s'); //word+='s';
}

int main(int argc, char const *argv[])
{
    std::string word = "hello world";
    std::vector<std::string> v1;
    v1.push_back(word); // vector,list,deque
    std::list<int> ilist;
    for (size_t ix = 0; ix != 4; ++ix)
    {
        ilist.push_front(ix); //list ,forward_list,deque
    }

    std::vector<std::string> svec;
    std::list<std::string> slist;
    slist.insert(slist.begin(), "Hello"); //slist.push_front("Hello");
    svec.insert(svec.begin(), "Hello!");  //not support push_front function
    svec.insert(svec.end(), 10, "Anna");

    std::vector<std::string> v = {"quasi", "simba", "frollo", "scar"};
    slist.insert(slist.end(), v.end() - 2, v.end());
    for (auto &i : slist)
    {
        std::cout << i << std::endl;
    }
    slist.insert(slist.end(), {"these", "words", "will", "go", "at", "the", "end"});
    for (auto &i : slist)
    {
        std::cout << i << std::endl;
    }

    std::list<std::string> lst;
    auto iter = lst.begin();
    while (std::cin >> word)
    {
        iter = lst.insert(iter, word);
    }

    return 0;
}
