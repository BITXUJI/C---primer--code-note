#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    unsigned long quiz1 = 0;

    quiz1 |= 1UL << 27;
    std::cout << std::hex << quiz1 << std::endl;
    quiz1 &= ~(1UL << 27);
    std::cout << std::hex << quiz1 << std::endl;
    bool status = quiz1 & (1UL << 27);
    std::cout << status << std::endl;

    unsigned char bits = 0x9b; //10011011 147 /8
    std::cout << std::hex << (bits >> 3) << std::endl;
    std::cout << std::hex << (~bits) << std::endl; // output:int :ffffff64
    std::cout << std::hex << (bits << 8) << std::endl;

    unsigned char b1 = 0x65;
    unsigned char b2 = 0xaf;
    std::cout << (b1 | b2) << std::endl;
    std::cout << (b1 & b2) << std::endl;
    std::cout << (b1 ^ b2) << std::endl;

    return 0;
}
