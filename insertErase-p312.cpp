#include <list>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::list<int> lst;
    auto iter = lst.begin();
    for (int i = 0; i != 10; ++i)
    {
        iter = lst.insert(iter, i);
        ++iter;
    }
    for (const auto &i : lst)
        std::cout << i << " ";
    std::cout << std::endl;
    auto it = lst.begin();
    while (it != lst.end())
    {
        if (*it % 2)
            it = lst.erase(it);
        else
            ++it;
    }
    for (const auto &i : lst)
        std::cout << i << " ";
    std::cout << std::endl;
    auto it1 = lst.begin();
    auto it2 = lst.end();
    --it2;
    --it2;
    auto it3 = lst.erase(it1, it2);
    std::cout << *it3 << std::endl;
    for (const auto &i : lst)
        std::cout << i << " ";
    std::cout << std::endl;
    lst.clear();
    std::cout << (lst.empty() ? "empty" : "Not empty") << std::endl;
    lst.erase(lst.begin(), lst.end());

    return 0;
}
