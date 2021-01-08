#include <iostream>
std::string global_str;
int global_int;
/**
 * Built-in type in Function is uninitialized.
 *
 * */
int main()
{
    int local_int;
    std::string local_str;
    std::cout << "global_str:" << global_str.length() << std::endl; // length =0
    std::cout << "global_int:" << global_int << std::endl;          //output 0
    std::cout << "local_str:" << local_str.length() << std::endl;   //length =0
    std::cout << "local_int:" << local_int << std::endl;            // output random
}