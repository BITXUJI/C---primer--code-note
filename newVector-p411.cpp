#include <vector>
#include <iostream>
std::vector<int> *writetovector(std::istream &s)
{
    std::vector<int> *pv = new std::vector<int>{};
    int i;
    while (s >> i)
        pv->push_back(i);
    return pv;
}
void readvector(std::vector<int> *pv)
{
    for (const auto &item : *pv)
        std::cout << item << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> *pv = writetovector(std::cin);
    readvector(pv);
    delete pv;
    pv = nullptr;
    return 0;
}
