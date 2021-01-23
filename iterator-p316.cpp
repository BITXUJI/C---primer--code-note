#include <vector>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else
        {
            iter = vi.erase(iter);
        }
    }
    for (const auto &i : vi)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
