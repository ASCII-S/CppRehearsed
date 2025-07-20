// Solution for C++ Name Hiding Practice
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    void func(int x)
    {
        cout << "Base::func(int): " << x << endl;
    }
    void func(double y)
    {
        cout << "Base::func(double): " << y << endl;
    }
};

class Derived : public Base
{
public:
    void func(const string &s)
    {
        cout << "Derived::func(string): " << s << endl;
    }
    // Uncomment the following line to bring Base::func into scope
    // using Base::func;
};

int main()
{
    Derived d;
    // Only func(string) is accessible directly
    d.func("hello");
    // d.func(10);      // Error: func(int) is hidden
    // d.func(3.14);    // Error: func(double) is hidden

    // Bring Base::func into scope
    cout << "--- After using Base::func; ---" << endl;
    class DerivedWithUsing : public Base
    {
    public:
        using Base::func;
        void func(const string &s)
        {
            cout << "DerivedWithUsing::func(string): " << s << endl;
        }
    };
    DerivedWithUsing du;
    du.func("world"); // DerivedWithUsing::func(string)
    du.func(20);      // Base::func(int)
    du.func(6.28);    // Base::func(double)
    return 0;
}