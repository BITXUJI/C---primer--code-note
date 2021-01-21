#include <string>
#include <fstream>
#include <vector>
#include <iostream>
void ReadFileLinesToVec(const std::string &fileName, std::vector<std::string> &vec)
{
    std::ifstream ifs(fileName);
    if (ifs)
    {
        std::string buf;
        while (getline(ifs, buf))
            vec.push_back(buf);
    }
}
void ReadFileWordsToVec(const std::string &fileName, std::vector<std::string> &vec)
{
    std::ifstream ifs(fileName);
    if (ifs)
    {
        std::string buf;
        while (ifs >> buf)
            vec.push_back(buf);
    }
}

int main(int argc, const char **argv)
{
    std::vector<std::string> vec;
    ReadFileWordsToVec("aaa", vec);
    for (auto i : vec)
        std::cout << i << std::endl;
    return 0;
}