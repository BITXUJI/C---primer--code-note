#include <list>
#include <deque>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::list<int> li = {1, 3, 4, 5, 7, 10};
    std::deque<int> de;
    std::deque<int> de1;
    for (const auto &i : li)
    {
        if ((i) % 2 == 0)
        {
            de.push_back(i);
        }
        else
        {
            de1.push_back(i);
        }
    }
    for (const auto &i : de)
        std::cout << i << std::endl;
    for (const auto &i : de1)
        std::cout << i << std::endl;
    return 0;
}
