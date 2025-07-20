// C++ Name Hiding Practice
// Estimated time: 10 minutes
#include <iostream>
using namespace std;

// TODO 1: Define a base class Base
// - Add a function void func(int) that prints "Base::func(int)"
// - Add a function void func(double) that prints "Base::func(double)"

// TODO 2: Define a derived class Derived
// - Add a function void func(string) that prints "Derived::func(string)"
// - Observe: this hides all Base::func overloads

// TODO 3: In main, create a Derived object
// - Try to call func(int), func(double), func(string)
// - See which are accessible

// TODO 4: Use 'using Base::func;' in Derived
// - Test again which functions are accessible

int main()
{
    // Complete the above TODOs step by step
    return 0;
}