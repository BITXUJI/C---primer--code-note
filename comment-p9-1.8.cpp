#include <iostream>
int main(int argc, const char **argv)
{
    //Test /* */ errors
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /*"*/ " */"; // missing "
    std::cout << /* "*/ " /* " /*" */;
    return 0;
}

