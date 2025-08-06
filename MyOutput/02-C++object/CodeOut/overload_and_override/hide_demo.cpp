// C++ Name Hiding Practice
// Estimated time: 10 minutes
#include <iostream>
using namespace std;

// TODO 1: Define a base class Base
// - Add a function void func(int) that prints "Base::func(int)"
// - Add a function void func(double) that prints "Base::func(double)"
class Base 
{
public:
    Base(){}

    void func(int a)
    {
        cout << "Base::func(int)" << endl;
    }

    void func(double d)
    {
        cout << "Base::func(double)" << endl;
    }
};

// TODO 2: Define a derived class Derived
// - Add a function void func(string) that prints "Derived::func(string)"
// - Observe: this hides all Base::func overloads
class Derived : public Base
{
public:
    Derived(){}

    void func(string)
    {
        cout << "Derived::func(string)" << endl;
    }
};

// TODO 3: In main, create a Derived object
// - Try to call func(int), func(double), func(string)
// - See which are accessible

// TODO 4: Use 'using Base::func;' in Derived
// - Test again which functions are accessible

int main()
{
    // Complete the above TODOs step by step
    Base* b = new Base();
    b->func(1);
    Derived* d = new Derived();
    d->func("s");
    Base *bd = new Derived();
    // bd->func("2");  // 基类指针无法使用子类函数
    // 一个容易忽略的点:指向子类的基类指针只能访问子类的基类部分.
    // 原因:每个子类在内存上都包含了父类的内容,在用基类指针时只能看到父类部分.只有子类重写override基类函数时,通过基类指针+虚函数表,才能访问到子类函数
    return 0;
}