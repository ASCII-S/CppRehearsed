// C++ 类对象初始化和析构顺序演示
// Estimated time: 30 minutes
// 按TODO顺序完成每个任务，建议每个8-10分钟
#include <iostream>
using namespace std;

// TODO 1: 定义一个简单的类A，构造和析构时输出提示
class A
{
public:
    A() { cout << "A constructed\n"; }
    ~A() { cout << "A destructed\n"; }
};

// TODO 2: 定义一个类B，构造和析构时输出提示
class B
{
public:
    B() { cout << "B constructed\n"; }
    ~B() { cout << "B destructed\n"; }
};

// TODO 3: 定义一个类Demo，包含A和B两个成员变量，注意声明顺序
class Demo
{
    A a;
    B b;

public:
    Demo() { cout << "Demo constructed\n"; }
    ~Demo() { cout << "Demo destructed\n"; }
};

// TODO 4: 定义一个基类Base，构造和析构时输出提示
class Base
{
public:
    Base() { cout << "Base constructed\n"; }
    ~Base() { cout << "Base destructed\n"; }
};

// TODO 5: 定义一个派生类Derived，继承自Base，包含Demo成员变量
class Derived : public Base
{
    Demo demo;

public:
    Derived() { cout << "Derived constructed\n"; }
    ~Derived() { cout << "Derived destructed\n"; }
};

// TODO 6: 定义全局对象和静态对象
A global_a;

void static_demo()
{
    static B static_b;
}

int main()
{
    cout << "--- main start ---\n";
    // TODO 7: 局部对象
    Demo d1;
    // TODO 8: 继承与成员对象的构造析构顺序
    Derived d2;
    // TODO 9: 静态局部对象
    static_demo();
    cout << "--- main end ---\n";
    return 0;
}
// TODO 10: 运行程序，观察输出，思考每个对象的构造和析构顺序，并与文档内容对照。