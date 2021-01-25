#include <iterator>
#include <vector>
#include <fstream>
#include <algorithm>
int main(int argc, char const *argv[])
{
    std::ifstream in("numbers");
    std::istream_iterator<int> in_iter(in), in_eof;
    std::ofstream out1("numbers_odd"), out2("numbers_even");
    std::ostream_iterator<int> out_iter1(out1, " ");
    std::ostream_iterator<int> out_iter2(out2, "\n");
    // while (in_iter != in_eof)
    // {
    //     if (*in_iter % 2)
    //     {
    //         *out_iter1++ = *in_iter++;
    //     }
    //     else
    //     {
    //         *out_iter2++ = *in_iter++;
    //     }
    // }
    std::for_each(in_iter, in_eof, [&out_iter1, &out_iter2](const int i) {
        *(i & 0x1 ? out_iter1 : out_iter2)++ = i;
    });

    return 0;
}
