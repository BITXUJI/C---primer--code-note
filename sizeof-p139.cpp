#include <iostream>
#include <vector>
#include <string>
#include "Sales_item.h"

struct book
{
    unsigned char a;
    unsigned long b;
    unsigned long long c;
    float d;
};

int main(int argc, char const *argv[])
{
    Sales_item data, *p;
    Sales_item &dataref = data;
    book book1;
    std::string str;
    std::vector<int> vec;
    std::vector<std::string> vecstr;
    std::cout << sizeof(Sales_item) << std::endl;             //40 class
    std::cout << sizeof(data) << std::endl;                   //40 class
    std::cout << sizeof(dataref) << std::endl;                //40 class
    std::cout << sizeof(p) << std::endl;                      //4 pointer
    std::cout << sizeof(*p) << std::endl;                     //40 class
    std::cout << sizeof(data.revenue) << std::endl;           //8 double
    std::cout << sizeof(Sales_item::revenue) << std::endl;    //8 double
    std::cout << sizeof(Sales_item::isbn) << std::endl;       //24 std::string
    std::cout << sizeof(Sales_item::units_sold) << std::endl; //4 unsigned int
    std::cout << sizeof(str) << std::endl;                    //24 std::string
    std::cout << sizeof(vec) << std::endl;                    //12 std::vector
    std::cout << sizeof(vecstr) << std::endl;                 //12 std::vector
    std::cout << sizeof(book1) << std::endl;                  //24 book
    std::cout << sizeof(book1.a) << std::endl;                //1 unsigned char
    std::cout << sizeof(book1.b) << std::endl;                //4 long
    std::cout << sizeof(book1.c) << std::endl;                //8 long long
    std::cout << sizeof(book1.d) << std::endl;                //4 float
    int ia[10];
    constexpr size_t sz = sizeof(ia) / sizeof(*ia);
    int arr2[sz];
    int x[10];
    int *p1 = x;
    std::cout << sizeof(x) / sizeof(*x) << std::endl;   //10  int [10]/ int
    std::cout << sizeof(p1) / sizeof(*p1) << std::endl; //1 pointer/int
    return 0;
}
