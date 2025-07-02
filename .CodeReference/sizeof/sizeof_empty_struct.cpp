/**
 * @file sizeof_empty_struct.cpp
 * @brief display sizeof empty struct and class
 */

#include <iostream>
using namespace std;

struct est
{
};
class ecl
{
};
class cl_only_cfuc
{
    cl_only_cfuc() {}
};
class cl_with_func
{
    cl_with_func()
    {
    }
    void foo() {}
};
class cl_with_member
{
    int a;
};
class cl_with_char_member
{
    char a;
};
class cl_with_virtual_func
{
    virtual void foo() {}
};
class cl_with_pure_virtual_func
{
    virtual void foo() = 0;
};
class cl_with_multiple_virtual_func
{
    virtual void foo() {}
    virtual void bar() {}
};
int main()
{
    cout << "====================sizeof empty struct and class====================" << endl;
    cout << "sizeof empty struct: " << sizeof(est) << endl;
    cout << "sizeof empty class: " << sizeof(ecl) << endl;
    cout << "====================sizeof class with no virtual function====================" << endl;
    cout << "sizeof class with only construction function: " << sizeof(cl_only_cfuc) << endl;
    cout << "sizeof class with function: " << sizeof(cl_with_func) << endl;
    cout << "====================sizeof class with virtual function====================" << endl;
    cout << "sizeof class with virtual function: " << sizeof(cl_with_virtual_func) << endl;
    cout << "sizeof class with pure virtual function: " << sizeof(cl_with_pure_virtual_func) << endl;
    cout << "sizeof class with multiple virtual function: " << sizeof(cl_with_multiple_virtual_func) << endl;
    cout << "====================sizeof class with member====================" << endl;
    cout << "sizeof class with member: " << sizeof(cl_with_member) << endl;
    cout << "sizeof class with char member: " << sizeof(cl_with_char_member) << endl;
    return 0;
}