/**
 * @file sizeof_basic_types.cpp
 *
 * @brief 演示各种基本类型占用内存的大小
 *
 * 此处类型占用的大小取决于编译器版本，如果使用的编译器是32位的，则生成32位的程序，其指针大小为4字节。
 * 当然64位cpu也兼容32位的程序，但此时程序打印的指针大小不与处理器位数一致。
 */
#include <iostream>

#define PRINT_SIZE(type) std::cout << #type << " size: " << sizeof(type) << " Bytes" << std::endl;

int main()
{
    std::cout << "sizeof pointer stands for the bit width of the CPU (if the compiled version matches the CPU architecture)" << std::endl;
    PRINT_SIZE(void *)
    PRINT_SIZE(int *)
    PRINT_SIZE(void)
    PRINT_SIZE(int)
    PRINT_SIZE(long int)
    PRINT_SIZE(float)
    PRINT_SIZE(double)
    PRINT_SIZE(char)
    PRINT_SIZE(bool)
    char str[10] = "hello";
    std::cout << "sizeof str: " << sizeof(str) << " Bytes" << std::endl;
    std::string s("hello");
    std::cout << "sizeof s: " << sizeof(s) << " Bytes" << std::endl;
    std::cout << "Note: sizeof string contains the null terminator(\\0)" << std::endl;
    return 0;
}