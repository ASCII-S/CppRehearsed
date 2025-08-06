#include<iostream>
using namespace std;
// TODO1: 定义一个基类A，包含一个成员变量
class A
{
public:
    double a;
};
// TODO2: 定义B和C分别虚继承A
class B : virtual public  A
{
};

class C: virtual public A
{
};

// TODO3: 定义D同时继承B和C，演示菱形继承
class D : public B, public C
{
};

// TODO4: 在main函数中，创建D对象，访问A的成员，观察是否有二义性
int main()
{
    D d;
    cout << d.a << endl;
}

// 参考：完成后可对照Solution/diamond_virtual_inherit.cpp中的标准答案