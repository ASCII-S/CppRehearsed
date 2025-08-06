// TODO1: 定义一个基类Shape，包含一个虚函数draw()
// TODO2: 定义一个纯虚函数area()，使Shape成为抽象类
// TODO3: 定义派生类Circle和Rectangle，重写draw()和area()
// TODO4: 在main函数中，使用基类指针指向派生类对象，演示动态多态
// 参考：完成后可对照Solution/virtual_demo.cpp中的标准答案

#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw()
    {
        cout << "shape draw ......" << endl;
    }

    virtual double area() = 0;
};

class Circle : public Shape
{
    double r;

public:

    Circle(double x) : r(x){}

    void draw() override
    {
        cout << "circle draw" << endl;
    }

    double area() override
    {
        return 3.14*r*r;
    }
};

class Rectangle : public Shape
{
    double a,b;

public: 

    Rectangle(double x, double y) : a(x),b(y) {}

    void draw() override
    {
        cout << "rectangle draw" << endl;
    }

    double area() override
    {
        return a*b;
    }
};

int main ()
{
    Shape * sc = new Circle(1.5);
    cout << "area of sc: " << sc->area() << endl;
    sc = new Rectangle(2,2.5);
    cout << "area of sc: " << sc->area() << endl;
    
    return 0;

}