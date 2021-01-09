#include <iostream>
#include <vector>
#include <string>
int main(int argc, const char **argv)
{
    int number;
    std::cin >> number;
    std::vector<int> v1;
    for (int i = 50; i < 100; i++)
        v1.push_back(i);

    auto beg = v1.cbegin();
    auto end = v1.cend();
    auto mid = beg + v1.size() / 2; //auto mid =beg +(end-beg)/2;
    while (beg != end && (*mid) != number)
    {
        if (number < *mid)
            end = mid;
        else
            beg = mid + 1;

        mid = beg + (end - beg) / 2; //end-beg :difference_type

        //error: no match for 'operator+' (operand types are '__gnu_cxx::__normal_iterator<const int*, std::vector<int> >' and '__gnu_cxx::__normal_iterator<const int*, std::vector<int> >')
        // mid = (beg + end) / 2;
    }
    std::cout << (mid - v1.cbegin()) << std::endl;

    return 0;
}