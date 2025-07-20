#include <iostream>
#include <typeinfo>
using namespace std;

// TODO 1: Define a polymorphic base class named Shape
// Requirements:
// - Add a virtual destructor
// - Add a pure virtual function named area() that returns double
// - Add a virtual function named getName() that returns "Shape"
class Shape
{
public:
    virtual ~Shape()
    {
    }

    virtual double area() = 0;

    virtual string getName()
    {
        return "Shape";
    }
};

// TODO 2: Define a derived class named Circle that inherits from Shape
// Requirements:
// - Add a private member radius of type double
// - Add a constructor that takes radius parameter
// - Override area() to return π * radius²  (use 3.14159 for π)
// - Override getName() to return "Circle"
// - Add a unique function named getRadius() that returns radius
class Circle : public Shape
{
    double radius;

public:
    Circle(double r) : radius(r)
    {
    }

    double area() override
    {
        return 3.14159 * radius * radius;
    }

    string getName() override
    {
        return "Circle";
    }

    double getRadius()
    {
        return radius;
    }
};

// TODO 3: Define a derived class named Rectangle that inherits from Shape
// Requirements:
// - Add private members width and height of type double
// - Add a constructor that takes width and height parameters
// - Override area() to return width * height
// - Override getName() to return "Rectangle"
// - Add a unique function named getPerimeter() that returns 2*(width+height)
class Rectangle : public Shape
{
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h)
    {
    }

    double area() override
    {
        return width * height;
    }

    string getName()
    {
        return "Rectangle";
    }

    double getPerimeter()
    {
        return 2 * (width + height);
    }
};

// TODO 4: Create a function named processShape
// Requirements:
// - Take a Shape* parameter
// - Use dynamic_cast to safely check if it's a Circle
// - If it's a Circle, call getRadius() and print the radius
// - Use dynamic_cast to safely check if it's a Rectangle
// - If it's a Rectangle, call getPerimeter() and print the perimeter
// - If neither, print "Unknown shape type"
void processShape(Shape *s)
{
    // dynamic_cast 的返回结果是目标类型的指针，如果转换失败，则返回 nullptr
    Circle *c = dynamic_cast<Circle *>(s);
    if (c)
    {
        std::cout << "This is a Circle" << std::endl;
        std::cout << "Radius of circle is: " << c->getRadius() << std::endl;
        return;
    }

    Rectangle *r = dynamic_cast<Rectangle *>(s);
    if (r)
    {
        std::cout << "This is a Rectangle" << std::endl;
        std::cout << "Perimeter of rectangle is: " << r->getPerimeter() << std::endl;
        return;
    }

    std::cout << "Unknown shape type" << std::endl;
}

int main()
{
    cout << "=== dynamic_cast Demo ===" << endl;

    // TODO 5: Create shape objects
    // Requirements:
    // - Create a Circle object with radius 5.0
    // - Create a Rectangle object with width 4.0 and height 3.0
    // - Store them in Shape* pointers

    cout << "\n=== Creating Shapes ===" << endl;
    Shape *s1 = new Circle(5.0);
    Shape *s2 = new Rectangle(4.0, 3.0);

    // TODO 6: Safe downcast with dynamic_cast
    // Requirements:
    // - Use dynamic_cast to convert Shape* to Circle*
    // - Check if the cast succeeded (pointer is not nullptr)
    // - If successful, call getRadius() and print the result
    // - If failed, print "Not a circle"

    cout << "\n=== Safe Downcast to Circle ===" << endl;
    processShape(s1);
    processShape(s2);

    // TODO 7: Failed downcast example
    // Requirements:
    // - Try to cast a Rectangle* to Circle* using dynamic_cast
    // - Check the result and print appropriate message

    cout << "\n=== Failed Downcast Example ===" << endl;
    Rectangle *r = new Rectangle(1, 1);
    Circle *cfail = dynamic_cast<Circle *>(r);
    if (cfail)
    {
        std::cout << "Successfully cast Rectangle to Circle" << std::endl;
    }
    else
    {
        std::cout << "Failed to cast Rectangle to Circle" << std::endl;
    }

    // TODO 8: Reference casting with exception handling
    // Requirements:
    // - Create a Shape reference from a Circle object
    // - Use try-catch to handle dynamic_cast with references
    // - Catch std::bad_cast exception and print error message

    cout << "\n=== Reference Casting with Exceptions ===" << endl;
    Circle c(1);
    Shape &sref = c;
    try
    {
        Circle &cref = dynamic_cast<Circle &>(sref);
        std::cout << "Successfully cast reference to Circle, radius: " << cref.getRadius() << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        std::cout << "Failed to cast reference: " << e.what() << std::endl;
    }

    try
    {
        Rectangle &rref = dynamic_cast<Rectangle &>(sref);
        std::cout << "Successfully cast reference to Rectangle, perimeter: " << rref.getPerimeter() << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        std::cout << "Failed to cast reference: " << e.what() << std::endl;
    }

    // TODO 9: Use the processShape function
    // Requirements:
    // - Call processShape with each shape pointer
    // - Observe how dynamic_cast enables safe type checking

    cout << "\n=== Using processShape Function ===" << endl;
    processShape(s1);
    processShape(s2);

    processShape(r);
    processShape(&sref);

    delete s1;
    delete s2;
    delete r;

    return 0;
}

// Note: This exercise should take approximately 10 minutes to complete
// Focus on understanding runtime type checking and safe casting