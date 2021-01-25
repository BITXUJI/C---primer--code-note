#include <iterator>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
template <typename Sequence>
void print(Sequence const &seq)
{
    for (const auto &i : seq)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::istream_iterator<int> int_it(std::cin);
    std::istream_iterator<int> int_eof;
    std::vector<int> ivec(int_it, int_eof);
    // if (int_it != int_eof)
    // {
    //     ivec.push_back(*int_it++);
    // }
    print(ivec);
    std::ifstream in("words");
    std::istream_iterator<std::string> str_it(in);
    std::istream_iterator<std::string> str_eof;
    std::vector<std::string> svec(str_it, str_eof);
    print(svec);
    // std::cout << std::accumulate(str_it, str_eof, std::string("")) << std::endl;

    return 0;
}
