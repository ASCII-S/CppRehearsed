#include <iostream>

int main()
{
    int x = 10;
    int y = 20;
    const int *p_int = &x;
    // *p_int = 20;
    p_int = &y;
    std::cout << *p_int << std::endl;

    int *const cp_int = &x;
    *cp_int = 30;
    // cp_int = &y;
    std::cout << *cp_int << std::endl;

    return 0;
}