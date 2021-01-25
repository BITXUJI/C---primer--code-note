#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
int main(int argc, char const *argv[])
{
    std::ifstream in("words");
    std::istream_iterator<std::string> in_iter(in), eof;
    std::ofstream out("words_cp");
    std::ostream_iterator<std::string> out_iter(out, "\n");
    std::copy(in_iter, eof, out_iter);
    std::cout << std::endl;

    return 0;
}
