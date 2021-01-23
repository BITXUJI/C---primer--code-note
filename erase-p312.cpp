#include <vector>
#include <list>
#include <iterator>
#include <iostream>
int main(int argc, char const *argv[])
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> v(std::begin(ia), std::end(ia));
    std::list<int> li(std::begin(ia), std::end(ia));
    auto iter = v.begin();
    while (iter != v.end())
    {
        if (*iter % 2)
            iter = v.erase(iter);
        else
            ++iter;
    }
    for (const auto &i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    auto iter1 = li.begin();
    while (iter1 != li.end())
    {
        if (!(*iter1 % 2))
            iter1 = li.erase(iter1);
        else
            ++iter1;
    }
    for (const auto &i : li)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
// using namespace std;
// vector<int> vec(ia, end(ia));
// list<int> lst(vec.begin(), vec.end());

// for (auto it = lst.begin(); it != lst.end();)
//     if (*it & 0x1)
//         it = lst.erase(it);
//     else
//         ++it;

// for (auto it = vec.begin(); it != vec.end();)
//     if (!(*it & 0x1))
//         it = vec.erase(it);
//     else
//         ++it;