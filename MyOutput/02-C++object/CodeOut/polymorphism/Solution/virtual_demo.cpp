#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() { cout << "Shape::draw()" << endl; }
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void draw() override { cout << "Circle::draw()" << endl; }
    double area() override { return 3.14 * 1 * 1; }
};

class Rectangle : public Shape
{
public:
    void draw() override { cout << "Rectangle::draw()" << endl; }
    double area() override { return 2 * 3; }
};

int main()
{
    Shape *s1 = new Circle();
    Shape *s2 = new Rectangle();
    s1->draw();
    cout << s1->area() << endl;
    s2->draw();
    cout << s2->area() << endl;
    delete s1;
    delete s2;
    return 0;
}