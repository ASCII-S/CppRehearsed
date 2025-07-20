#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    void hello() { cout << "Hello from Derived" << endl; }
};

int main()
{
    Base *b = new Derived();
    Derived *d = dynamic_cast<Derived *>(b);
    if (d)
        d->hello();
    else
        cout << "Cast failed" << endl;
    delete b;
    return 0;
}