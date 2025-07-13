#include <iostream>
#include <string>  // 需要添加string头文件

// 正确的extern声明 - 声明在global_variable_demo.cpp中定义的全局变量
extern int counter;
extern std::string app_name;

// 正确的extern函数声明 - 声明在global_variable_demo.cpp中定义的函数
extern void increment_counter();
extern void get_app_info();

// 在file2.cpp中定义的新函数
void decrement_counter(){
    counter--;
}

void reset_app(){
    counter = 0;
    app_name = "ResetApp";
}

int main(){
    std::cout << "=== File2.cpp 操作演示 ===" << std::endl;
    
    // 显示初始状态
    std::cout << "初始状态: ";
    get_app_info();
    
    // 使用file2中的函数修改全局变量
    decrement_counter();
    std::cout << "执行decrement_counter()后: ";
    get_app_info();
    
    // 使用global_variable_demo.cpp中的函数
    increment_counter();
    increment_counter();
    std::cout << "执行两次increment_counter()后: ";
    get_app_info();
    
    // 重置应用
    reset_app();
    std::cout << "执行reset_app()后: ";
    get_app_info();
    
    return 0;
}