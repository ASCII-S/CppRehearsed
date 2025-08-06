// C++ Overload Practice
// Estimated time: 10 minutes
#include <fstream>
#include <iostream>
#include <ostream>
using namespace std;

// TODO 1: Define two 'add' functions
// - One takes two int parameters and returns their sum
// - One takes two double parameters and returns their sum
int add(int a, int b)
{
    return a+b;
}
double add (double a, double b)
{
    return a+b;
}
template<typename T>
T add_t (T a, T b)
{
    return a+b;
}

// TODO 2: Overload the 'print' function
// - One version prints an int
// - One version prints a double
// - One version prints a string
void print(int a)
{
    cout << "int: " << a << endl;
}
void print(double a)
{
    cout << "double: " << a << endl;
}

// TODO 3: Overload the '+' operator for a custom class (e.g., Point)
// - Define a class Point with x, y members
// - Overload operator+ to add two Points
// - Overload operator<< to print a Point
class Point
{
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    double x,y;
    
    
    Point operator+(const Point &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    friend ostream &operator<<(ostream &os,const Point &p)
    {
        os <<"x: "<< p.x << " y: " << p.y << endl;
        return os;
    }
};

int main()
{
    // TODO 4: Test all overloaded functions and operators
    // - Call add with int and double
    // - Call print with int, double, string
    // - Create two Points, add them, and print the result
    cout << add_t(1,2) << endl;
    cout << add_t(1.1,2.2) << endl;
    print(1);
    print(1.1);
    Point p1(1,2);
    Point p2(3,4);
    cout << p1+p2 << endl;
    return 0;
}