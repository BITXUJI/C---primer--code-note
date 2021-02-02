#include <string>
#include <new>
#include <iostream>
#include <vector>
int main(int argc, char const *argv[])
{
    // int *pi = new int;
    int *pi = new int();
    std::string *ps = new std::string;
    std::string *ps3 = new std::string();
    int *pi1 = new int(1024);
    std::string *ps2 = new std::string(10, '9');
    std::vector<int> *pv = new std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    const int *pci = new const int(1024);
    const std::sting *pcs = new const std::string;
    delete pi;
    pi = nullptr;
    delete pci;
    pci = nullptr;
    return 0;
}
