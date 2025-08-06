#include <iostream>
#include <cmath>
#include <string>

// Abstract class Shape with pure virtual function
class Shape {
protected:
    std::string name;
    
public:
    Shape(const std::string& n) : name(n) {}
    virtual ~Shape() {}
    
    // Pure virtual function - must be implemented by derived classes
    virtual double calculateArea() const = 0;
    
    std::string getName() const { return name; }
};

// Circle class inheriting from Shape
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r, const std::string& n) : Shape(n), radius(r) {}
    
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
    
    double getRadius() const { return radius; }
};

// Rectangle class inheriting from Shape
class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h, const std::string& n) 
        : Shape(n), width(w), height(h) {}
    
    double calculateArea() const override {
        return width * height;
    }
    
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

// Function to demonstrate polymorphism
void printArea(const Shape* shape) {
    std::cout << shape->getName() << " area: " << shape->calculateArea() << std::endl;
}

int main() {
    std::cout << "=== Pure Virtual Function Basic Demo ===" << std::endl;
    
    // Create instances of Circle and Rectangle
    Circle circle(5.0, "Circle");
    Rectangle rectangle(4.0, 6.0, "Rectangle");
    
    // Demonstrate polymorphism using base class pointers
    Shape* shape1 = &circle;
    Shape* shape2 = &rectangle;
    
    printArea(shape1);
    printArea(shape2);
    
    // Test that abstract class cannot be instantiated
    // Shape shape; // This would cause compilation error
    
    std::cout << "\n=== Demo completed ===" << std::endl;
    return 0;
} 