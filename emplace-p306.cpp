#include <vector>
#include "Sales_item.h"
#include <list>
int main(int argc, char const *argv[])
{
    std::list<Sales_item> c;
    c.emplace_back("978-0590353403", 25, 15.99);

    // error: no matching function for call to 'std::vector<Sales_item>::push_back(const char [15], int, double)'
    // c.push_back("978-0590353403", 25, 15.99);

    c.push_back(Sales_item("978-0590353404", 25, 15.99));

    c.emplace_back();

    c.emplace(c.begin(), "978-0590353405");

    c.emplace_front("978-0590353406", 10, 34);

    return 0;
}
