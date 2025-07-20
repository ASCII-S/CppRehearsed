// Solution for C++ Overload Practice
#include <iostream>
#include <string>
using namespace std;

// 1. Function overloads
int add(int a, int b)
{
    return a + b;
}
double add(double a, double b)
{
    return a + b;
}

// 2. Print overloads
void print(int x)
{
    cout << "int: " << x << endl;
}
void print(double x)
{
    cout << "double: " << x << endl;
}
void print(const string &s)
{
    cout << "string: " << s << endl;
}

// 3. Operator overload for Point
class Point
{
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    // Overload +
    Point operator+(const Point &other) const
    {
        return Point(x + other.x, y + other.y);
    }
    // Overload <<
    friend ostream &operator<<(ostream &os, const Point &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main()
{
    // Test add
    cout << "add(int, int): " << add(2, 3) << endl;
    cout << "add(double, double): " << add(2.5, 3.5) << endl;
    // Test print
    print(42);
    print(3.14);
    print("hello");
    // Test Point operator overloads
    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;
    cout << "p1 + p2 = " << p3 << endl;
    return 0;
}