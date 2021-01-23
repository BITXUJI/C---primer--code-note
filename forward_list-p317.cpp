#include <forward_list>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::forward_list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = vi.before_begin();
    auto curr = vi.begin();
    while (curr != vi.end())
    {
        if (*curr % 2)
        {
            curr = vi.insert_after(prev, *curr);
            ++curr;
            prev = curr;
            ++curr;
        }
        else
        {
            curr = vi.erase_after(prev);
        }
    }
    for (const auto &i : vi)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}