#include <iostream>
/*
* Calculate the sum of 1 to 10 inclusive using while loop
*/
int main(int argc, const char **argv)
{
    int sum = 0, val = 1;
    /*
    *while (condition)
    *   statement
    */
    while (val <= 10)
    {
        sum += val;
        ++val;
    }
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
}