#include <forward_list>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::forward_list<int> fl = {1, 3, 4, 6, 3, 8, 5};
    auto prev = fl.before_begin();
    auto curr = fl.begin();

    while (curr != fl.end())
    {
        if (*curr % 2)
            curr = fl.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }
    for (const auto &i : fl)
        std::cout << i << std::endl;
    return 0;
}
