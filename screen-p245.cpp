#include "Screen.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    Screen screen(5, 5, 'a');
    // char ch = screen.get();
    // std::cout << ch << std::endl;
    // ch = screen.get(0, 0);
    // screen.move(2, 2).set('A');
    screen.some_member();
    Screen screen1 = screen.move(2, 2);
    screen1.move(4, 4);
    std::cout << screen.getCursor() << std::endl;
    std::cout << screen1.getCursor() << std::endl;
    return 0;
}
