#include <vector>
#include <iostream>
#include <string>
main()
{
    std::vector<unsigned> scores(11, 0);
    unsigned grade;
    while (std::cin >> grade)
    {
        if (grade <= 100)
            ++scores[grade / 10];
    }
    for (auto i : scores)
        std::cout << i << std::endl;
}