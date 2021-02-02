#include <vector>
#include <iostream>
#include <memory>
std::shared_ptr<std::vector<int>> writetovector(std::istream &s)
{
    std::shared_ptr<std::vector<int>> pv = std::make_shared<std::vector<int>>();
    int i;
    while (s >> i)
        pv->push_back(i);
    return pv;
}
void readvector(std::shared_ptr<std::vector<int>> pv)
{
    for (const auto &item : *pv)
        std::cout << item << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    auto pv = writetovector(std::cin);
    readvector(pv);

    return 0;
}