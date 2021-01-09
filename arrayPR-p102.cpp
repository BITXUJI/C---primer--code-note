#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char **argv)
{
    int arr[10];
    int *ptrs[10];

    //error: declaration of 'refs' as array of references
    // int &refs[10] = arr;

    int(*Parray)[10] = &arr;
    int(&arrRef)[10] = arr;
    int *(&arry)[10] = ptrs;
    return 0;
}