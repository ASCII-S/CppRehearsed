/**
 * @file sizeof_strlen.cpp
 *
 * @brief demonstrate the difference between sizeof and strlen
 *
 */

#include <iostream>
#include <cstring>
int main()
{
    char c;
    std::string s("hello");
    std::cout << "sizeof is an operator" << std::endl;
    std::cout << "sizeof(c): " << sizeof(c) << std::endl;
    std::cout << "sizeof(s): " << sizeof(s) << std::endl;
    std::cout << "strlen is a function(declared in <cstring>)" << std::endl;
    std::cout << "strlen(s): " << strlen(s.c_str()) << std::endl;
    return 0;
}