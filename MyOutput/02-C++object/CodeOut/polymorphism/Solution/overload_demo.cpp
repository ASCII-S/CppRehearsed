#include <iostream>
#include <string>
using namespace std;

class Calculator
{
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    string add(const string &a, const string &b) { return a + b; }
};

class Complex
{
public:
    int real, imag;
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }
    void print() const { cout << real << "+i" << imag << endl; }
};

int main()
{
    Calculator calc;
    cout << calc.add(1, 2) << endl;
    cout << calc.add(1.1, 2.2) << endl;
    cout << calc.add(string("Hello, "), string("World!")) << endl;
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}