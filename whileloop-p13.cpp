#include <iostream>

main()
{
    int sum = 0, value = 0;
    /**
     * End-of-file: 
     *  ctrl+z for Windows 
     *  ctrl+d for Unix and Mac OS
     * std::cin >>value
     *  While loop stops on condition that 
     *  istream object std::cin becomes invalid:
     *      end-of-file
     *      not integer 
     **/
    while (std::cin >> value)
    {
        sum += value;
    }
    std::cout << "Sum is: " << sum << std::endl;
}