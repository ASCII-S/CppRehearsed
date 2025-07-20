// 面向对象三大特性综合练习
// Estimated time: 30 minutes
// 按TODO顺序完成每个任务，建议每个10分钟左右
#include <iostream>
#include <string>
using namespace std;

// TODO 1: 封装（Encapsulation）
// 1. 定义一个BankAccount类
//    - 私有成员变量: balance (double)
//    - 公有成员函数: deposit(double), withdraw(double), getBalance() const
//    - 构造函数: BankAccount(double initialBalance)
//    - 在main中创建对象，测试存取款和余额查询
//    - 尝试直接访问balance，观察编译器报错

// TODO 2: 继承（Inheritance）
// 1. 定义一个Animal基类
//    - 公有成员函数: makeSound()（虚函数，输出"Animal sound"）
// 2. 定义Dog和Cat类，继承自Animal
//    - 重写makeSound(): Dog输出"Woof!"，Cat输出"Meow!"
//    - 在main中分别创建Dog和Cat对象，调用makeSound()

// TODO 3: 多态（Polymorphism）
// 1. 在main中，定义一个Animal类型的指针
//    - 让它分别指向Dog和Cat对象，调用makeSound()
//    - 观察输出，理解多态的作用

int main()
{
    // 按顺序完成上面每个TODO
    return 0;
}