#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

// Solution for TODO 1: Define a polymorphic base class named Shape
class Shape {
public:
    virtual ~Shape() = default;
    
    virtual double area() = 0;
    
    virtual string getName() {
        return "Shape";
    }
};

// Solution for TODO 2: Define a derived class named Circle
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return 3.14159 * radius * radius;
    }
    
    string getName() override {
        return "Circle";
    }
    
    double getRadius() {
        return radius;
    }
};

// Solution for TODO 3: Define a derived class named Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() override {
        return width * height;
    }
    
    string getName() override {
        return "Rectangle";
    }
    
    double getPerimeter() {
        return 2 * (width + height);
    }
};

// Solution for TODO 4: Create a function named processShape
void processShape(Shape* shape) {
    cout << "Processing shape: " << shape->getName() << endl;
    
    // Try to cast to Circle
    Circle* circle = dynamic_cast<Circle*>(shape);
    if (circle) {
        cout << "It's a Circle with radius: " << circle->getRadius() << endl;
        return;
    }
    
    // Try to cast to Rectangle
    Rectangle* rectangle = dynamic_cast<Rectangle*>(shape);
    if (rectangle) {
        cout << "It's a Rectangle with perimeter: " << rectangle->getPerimeter() << endl;
        return;
    }
    
    cout << "Unknown shape type" << endl;
}

int main() {
    cout << "=== dynamic_cast Demo ===" << endl;
    
    // Solution for TODO 5: Create shape objects
    cout << "\n=== Creating Shapes ===" << endl;
    
    Shape* circlePtr = new Circle(5.0);
    Shape* rectanglePtr = new Rectangle(4.0, 3.0);
    
    cout << "Circle area: " << circlePtr->area() << endl;
    cout << "Rectangle area: " << rectanglePtr->area() << endl;
    
    // Solution for TODO 6: Safe downcast with dynamic_cast
    cout << "\n=== Safe Downcast to Circle ===" << endl;
    
    Circle* castedCircle = dynamic_cast<Circle*>(circlePtr);
    if (castedCircle) {
        cout << "Successfully cast to Circle, radius: " << castedCircle->getRadius() << endl;
    } else {
        cout << "Not a circle" << endl;
    }
    
    // Solution for TODO 7: Failed downcast example
    cout << "\n=== Failed Downcast Example ===" << endl;
    
    Circle* castedRectangle = dynamic_cast<Circle*>(rectanglePtr);
    if (castedRectangle) {
        cout << "Successfully cast to Circle, radius: " << castedRectangle->getRadius() << endl;
    } else {
        cout << "Not a circle - dynamic_cast returned nullptr" << endl;
    }
    
    // Solution for TODO 8: Reference casting with exception handling
    cout << "\n=== Reference Casting with Exceptions ===" << endl;
    
    Circle circle(3.0);
    Shape& shapeRef = circle;
    
    try {
        Circle& circleRef = dynamic_cast<Circle&>(shapeRef);
        cout << "Successfully cast reference to Circle, radius: " << circleRef.getRadius() << endl;
    } catch (const std::bad_cast& e) {
        cout << "Failed to cast reference: " << e.what() << endl;
    }
    
    // Try to cast Circle reference to Rectangle reference (should throw)
    try {
        Rectangle& rectangleRef = dynamic_cast<Rectangle&>(shapeRef);
        cout << "Successfully cast reference to Rectangle, perimeter: " << rectangleRef.getPerimeter() << endl;
    } catch (const std::bad_cast& e) {
        cout << "Failed to cast Circle reference to Rectangle: " << e.what() << endl;
    }
    
    // Solution for TODO 9: Use the processShape function
    cout << "\n=== Using processShape Function ===" << endl;
    
    processShape(circlePtr);
    processShape(rectanglePtr);
    
    // Cleanup
    delete circlePtr;
    delete rectanglePtr;
    
    return 0;
}

// Note: This solution demonstrates the safety of dynamic_cast
// Key learning points:
// 1. dynamic_cast requires polymorphic classes (with virtual functions)
// 2. Returns nullptr for failed pointer casts
// 3. Throws std::bad_cast for failed reference casts
// 4. Provides runtime type checking for safe downcasting
// 5. Enables safe type identification in polymorphic hierarchies 