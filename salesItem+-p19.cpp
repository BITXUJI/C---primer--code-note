#include <iostream>
#include "Sales_item.h"
int main(int argc, const char **argv)
{
    Sales_item item1, item2;
    /**
     * $ ./"salesItem+-p19.exe" <infile >outfile
     *  Infile used as std::cin input file 
     *  Outfile used as std::cout  output file
     * 
     * */
    std::cin >> item1 >> item2;
    if (item1.same_isbn(item2))
    {
        std::cout << item1 + item2 << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN " << std::endl;
        return -1;
    }
}