#include <iterator>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
int main(int argc, char const *argv[])
{
    std::ifstream infile("words");
    std::istream_iterator<std::string> in_iter(infile), eof;
    std::vector<std::string> svec(in_iter, eof);
    //std::copy(in_iter, eof, std::back_inserter(svec));
    std::ostream_iterator<std::string> out_iter(std::cout, " ");
    std::copy(svec.cbegin(), svec.cend(), out_iter);
    std::cout << std::endl;
    return 0;
}
