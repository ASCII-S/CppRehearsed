// Solution for C++ 类对象初始化和析构顺序演示
#include <iostream>
using namespace std;

// 1. 定义一个简单的类A，构造和析构时输出提示
class A
{
public:
    A() { cout << "A constructed\n"; }
    ~A() { cout << "A destructed\n"; }
};

// 2. 定义一个类B，构造和析构时输出提示
class B
{
public:
    B() { cout << "B constructed\n"; }
    ~B() { cout << "B destructed\n"; }
};

// 3. 定义一个类Demo，包含A和B两个成员变量，注意声明顺序
class Demo
{
    A a; // 先声明，先初始化，后析构
    B b;

public:
    Demo() { cout << "Demo constructed\n"; }
    ~Demo() { cout << "Demo destructed\n"; }
};

// 4. 定义一个基类Base，构造和析构时输出提示
class Base
{
public:
    Base() { cout << "Base constructed\n"; }
    ~Base() { cout << "Base destructed\n"; }
};

// 5. 定义一个派生类Derived，继承自Base，包含Demo成员变量
class Derived : public Base
{
    Demo demo;

public:
    Derived() { cout << "Derived constructed\n"; }
    ~Derived() { cout << "Derived destructed\n"; }
};

// 6. 定义全局对象和静态对象
A global_a; // 程序启动前构造，main结束后析构

void static_demo()
{
    static B static_b; // 第一次调用时构造，main结束后析构
}

int main()
{
    cout << "--- main start ---\n";
    // 7. 局部对象
    Demo d1; // 先构造A，再B，再Demo
    // 8. 继承与成员对象的构造析构顺序
    Derived d2; // 先Base，再Demo成员（A->B->Demo），最后Derived
    // 9. 静态局部对象
    static_demo();
    cout << "--- main end ---\n";
    return 0;
}
// 10. 运行程序，观察输出，思考每个对象的构造和析构顺序，并与文档内容对照。
// 典型输出顺序请参考文档和注释。