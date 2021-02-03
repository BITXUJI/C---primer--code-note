//g++ -std=c++11 MessageExample.cpp Message.cpp
//./a.out

#include "Message.h"
#include <string>
#include <vector>
#include <algorithm>
int main(int argc, char const *argv[])
{
    std::string msg = "new email";
    Message msg1(msg);
    Message msg2(std::string("old email"));
    Folder folder1;
    msg1.save(folder1);
    msg2.save(folder1);
    msg1.print_debug();
    folder1.print_debug();
    std::vector<Message> vec;
    Message msg3(std::string("a oldder email"));
    vec.push_back(msg1);
    vec.push_back(msg2);
    vec.push_back(msg3);
    std::sort(vec.begin(), vec.end());
    for (auto &item : vec)
        item.print_debug();
    return 0;
}
