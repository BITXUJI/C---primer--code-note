#include <iostream>
#include "Sales_item.h"
int main(int argc, const char **argv)
{
    typedef double wages;
    typedef wages base, *p;
    using SI = Sales_item;

    wages hourly, weekly;
    SI item;

    typedef char *pstring;
    const pstring cstr = 0;
    char val;

    //error: assignment of read-only variable 'cstr'
    // cstr = &val;

    *cstr = 5; // compile is ok but Segmentation fault
    const pstring *ps;
    return 0;
}