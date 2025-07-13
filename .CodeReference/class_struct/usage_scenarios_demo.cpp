#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// TODO 1: 用struct定义一个Point结构体
// 要求：
// - 有两个public成员：x和y (都是double类型)
// - 添加构造函数：Point(double x = 0, double y = 0)
// - 添加一个计算到原点距离的函数：double distanceToOrigin()
// 思考：为什么这里适合用struct？
struct Point{
    int x;
    int y;
    Point(int x=0, int y=0): x(x),y(y){}
    double distanceToOrigin(){
        return sqrt(x*x + y*y);
    }
};

// TODO 2: 用struct定义一个Student结构体
// 要求：
// - 有成员：name (string), id (int), gpa (double)
// - 添加构造函数
// - 添加一个输出学生信息的函数：void display()
// 思考：为什么简单的数据容器适合用struct？
struct Student{
    string name;
    int age;
    double gpa;
    Student(string n, int a,double g): name(n),age(a),gpa(g){}
    void display(){
        std::cout << "name: " << name << std::endl;
        std::cout << "age: " << age << std::endl;
        std::cout << "gpa: " << gpa << std::endl;
    }
};

// TODO 3: 用class定义一个BankAccount类
// 要求：
// - 私有成员：balance (double), accountNumber (string)
// - 公有成员函数：
//   - 构造函数：BankAccount(string accNum, double initialBalance = 0)
//   - deposit(double amount) - 存款
//   - withdraw(double amount) - 取款（余额不足返回false）
//   - getBalance() const - 获取余额
// 思考：为什么这里需要用class而不是struct？

// TODO 4: 用class定义一个Calculator类
// 要求：
// - 私有成员：result (double)
// - 公有成员函数：
//   - add(double value)
//   - multiply(double value)
//   - getResult() const
//   - reset() - 重置result为0
// 思考：为什么有状态和复杂逻辑的对象适合用class？

int main() {
    // TODO 5: 测试Point结构体
    // 创建一个Point对象，直接访问x、y成员
    // 修改坐标值，计算距离
    Point p(3,4.1);
    std::cout << "distance to origin: " << p.distanceToOrigin() ;
    std::cout << std::endl;
    // TODO 6: 测试Student结构体
    // 创建Student对象，直接设置和访问成员
    Student s("bob", 6 , 2.01);
    s.display();

    // TODO 7: 测试BankAccount类
    // 创建账户，尝试存款、取款
    // 思考：为什么不能直接访问balance？
    
    // TODO 8: 测试Calculator类
    // 进行一系列计算操作
    
    // TODO 9: 思考题
    // 1. 什么时候选择struct？什么时候选择class？
    // 2. 能否用class实现Point和Student的功能？
    // 3. 能否用struct实现BankAccount的功能？
    // 4. 默认访问权限对设计有什么影响？
    
    return 0;
} 