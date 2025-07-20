// 面试高频：类对象的初始化和析构顺序演示
#include <iostream>
#include <string>
using namespace std;

// TODO 1: 定义一个Base类，构造和析构函数中输出提示
class Base
{
public:
    Base() { cout << "Base constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

// TODO 2: 定义一个Member类，构造和析构函数中输出提示
class Member
{
public:
    Member() { cout << "Member constructor" << endl; }
    ~Member() { cout << "Member destructor" << endl; }
};

// TODO 3: 定义一个Derived类，继承自Base，包含Member成员变量
// 构造和析构函数中输出提示
class Derived : public Base
{
    Member m;

public:
    Derived() { cout << "Derived constructor" << endl; }
    ~Derived() { cout << "Derived destructor" << endl; }
};

// TODO 4: 定义一个全局对象（类型自选），观察其构造和析构时机
Member global_member;

// TODO 5: 定义一个静态对象的函数，返回对静态对象的引用
Member &getStaticMember()
{
    static Member static_member;
    return static_member;
}

int main()
{
    cout << "--- main start ---" << endl;

    // TODO 6: 在main中定义多个局部对象，观察构造和析构顺序
    Derived d1;
    Derived d2;

    cout << "--- call getStaticMember() ---" << endl;
    getStaticMember();

    cout << "--- main end ---" << endl;
    return 0;
}
// TODO 7: 编译运行，观察输出，思考每一步的顺序和原因
// 提示：可多次运行、调整对象顺序，加深理解