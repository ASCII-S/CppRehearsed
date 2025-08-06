#include <iostream>
// TODO1: 定义一个类Calculator，实现add函数的重载，支持int、double、string等类型的加法
// 提示：int add(int a, int b); double add(double a, double b); string add(string a, string b);

// TODO2: 定义一个Complex类，实现+运算符重载
// 提示：Complex operator+(const Complex& other) const;
class Complex
{
public:
    int a;
    int b;

    Complex(int x,int y):a(x),b(y) {}

    Complex operator+(const Complex& other)
    {
        a += other.a;
        b+= other.b;
        return *this;
    }

    void print()
    {
        std::cout << "a: " << a << "b:  " << b << std::endl;
    }
};

// TODO3: 在main函数中，分别测试上述重载函数和运算符重载
int main()
{
    Complex Ca(1,2);
    Complex Cb(5,7);
    Ca = Ca + Cb;
    Ca.print();
}

// 参考：完成后可对照Solution/overload_demo.cpp中的标准答案