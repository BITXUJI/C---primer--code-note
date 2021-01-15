// #include <vector>
// #include <string>
// #include <iostream>
// int main(int argc, char const *argv[])
// {
//     std::vector<int> vec = {1, 2, 3, 4, 5, 6};
//     std::vector<int> vec1 = {1, 2, 4};
//     if (vec1.size() > vec.size())
//     {
//         decltype(vec.size()) i = 0;
//         for (; i < vec.size(); ++i)
//         {
//             if (vec[i] != vec1[i])
//                 break;
//         }
//         if (i == vec.size())
//         {
//             std::cout << "true" << std::endl;
//         }
//         else
//         {
//             std::cout << "false" << std::endl;
//         }
//     }
//     else
//     {
//         decltype(vec1.size()) i = 0;
//         for (; i < vec1.size(); ++i)
//         {
//             if (vec[i] != vec1[i])
//                 break;
//         }
//         if (i == vec1.size())
//         {
//             std::cout << "true" << std::endl;
//         }
//         else
//         {
//             std::cout << "false" << std::endl;
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

bool is_prefix(const vector<int> &lhs, const vector<int> &rhs)
{
    if (lhs.size() > rhs.size())
        return is_prefix(rhs, lhs);
    for (unsigned i = 0; i != lhs.size(); ++i)
        if (lhs[i] != rhs[i])
            return false;
    return true;
}

int main()
{
    vector<int> l{0, 1, 1, 2};
    vector<int> r{0, 1, 1, 2, 3, 5, 8};
    cout << (is_prefix(r, l) ? "yes\n" : "no\n");

    return 0;
}