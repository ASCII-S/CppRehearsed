// Solution: 类对象的初始化和析构顺序演示
#include <iostream>
#include <string>
using namespace std;

// Base class
class Base
{
public:
    Base() { cout << "Base constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

// Member class
class Member
{
public:
    Member() { cout << "Member constructor" << endl; }
    ~Member() { cout << "Member destructor" << endl; }
};

// Derived class with member object
class Derived : public Base
{
    Member m;

public:
    Derived() { cout << "Derived constructor" << endl; }
    ~Derived() { cout << "Derived destructor" << endl; }
};

// Global object
Member global_member;

// Static object in function
Member &getStaticMember()
{
    static Member static_member;
    return static_member;
}

int main()
{
    cout << "--- main start ---" << endl;

    Derived d1;
    Derived d2;

    cout << "--- call getStaticMember() ---" << endl;
    getStaticMember();

    cout << "--- main end ---" << endl;
    return 0;
}
/*
Sample Output:
Member constructor         // global_member
--- main start ---
Base constructor          // d1
Member constructor        // d1.m
Derived constructor       // d1
Base constructor          // d2
Member constructor        // d2.m
Derived constructor       // d2
--- call getStaticMember() ---
Member constructor        // static_member
--- main end ---
Derived destructor        // d2
Member destructor         // d2.m
Base destructor           // d2
Derived destructor        // d1
Member destructor         // d1.m
Base destructor           // d1
Member destructor         // static_member
Member destructor         // global_member
*/