#include <set>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::set<int>::const_iterator set_it = iset.cbegin();
    if (set_it != iset.end())
        // error: assignment of read-only location 'set_it.std::_Rb_tree_const_iterator<int>::operator*()'
        // *set_it = 43;
        std::cout << *set_it << std::endl;
    return 0;
}
// fatal error: error writing to C:\Users\XYSM\AppData\Local\Temp\ccwxXZrV.s: No error