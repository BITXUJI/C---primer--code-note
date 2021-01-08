#include <iostream>

main()
{
    double obj = 3.14159, *pd = &obj;
    void *pv = &obj;
    pv = pd;
}