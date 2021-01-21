
#include <fstream>
#include <iostream>

#include "Sales_item.h"

using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);

    Sales_item total;
    if (input >> total)
    {
        Sales_item trans;
        while (input >> trans)
        {
            if (total.same_isbn(trans))
                total += trans;
            else
            {
                output << total << endl;
                total = trans;
            }
        }
        output << total << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }

    return 0;
}