/**
 * File: Solution_explicit_demo.cpp  
 * Purpose: Complete solution demonstrating explicit keyword usage
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Solution for TODO 1: SafeMoney class with explicit constructor
class SafeMoney {
private:
    double amount;
    
public:
    explicit SafeMoney(double value) : amount(value) {
        cout << "SafeMoney explicit constructor called with: " << value << endl;
    }
    
    // Copy constructor (default is fine)
    SafeMoney(const SafeMoney& other) = default;
    
    double getAmount() const {
        return amount;
    }
    
    void show() const {
        cout << "SafeMoney: $" << amount << endl;
    }
};

// Solution for TODO 2: Vector3D class with explicit constructors
class Vector3D {
private:
    double x, y, z;
    
public:
    // Explicit single-parameter constructor
    explicit Vector3D(double value) : x(value), y(value), z(value) {
        cout << "Vector3D single-value constructor called with: " << value << endl;
    }
    
    // Explicit three-parameter constructor  
    explicit Vector3D(double x_val, double y_val, double z_val) 
        : x(x_val), y(y_val), z(z_val) {
        cout << "Vector3D three-value constructor called" << endl;
    }
    
    void display() const {
        cout << "Vector3D(" << x << ", " << y << ", " << z << ")" << endl;
    }
    
    double magnitude() const {
        return sqrt(x*x + y*y + z*z);
    }
};

// Solution for TODO 3: Test functions
void processSecurePayment(SafeMoney m) {
    cout << "Secure payment: " << m.getAmount() << endl;
}

void calculateForce(Vector3D v) {
    cout << "Force vector: ";
    v.display();
}

// Solution for TODO 4: Main function testing explicit behavior
int main() {
    cout << "=== Explicit Keyword Demo ===" << endl;
    
    // Working test cases with explicit constructors
    cout << "\n--- Valid explicit constructions ---" << endl;
    
    // 1. Direct initialization works
    cout << "1. SafeMoney sm1(100.5):" << endl;
    SafeMoney sm1(100.5);
    sm1.show();
    
    // 2. Explicit construction works
    cout << "\n2. SafeMoney sm2 = SafeMoney(75.25):" << endl;
    SafeMoney sm2 = SafeMoney(75.25);
    sm2.show();
    
    // 3. Explicit conversion in function call works
    cout << "\n3. processSecurePayment(SafeMoney(50.0)):" << endl;
    processSecurePayment(SafeMoney(50.0));
    
    // 4. Vector3D with three parameters
    cout << "\n4. Vector3D v1(1.0, 2.0, 3.0):" << endl;
    Vector3D v1(1.0, 2.0, 3.0);
    v1.display();
    
    // 5. Vector3D with single parameter
    cout << "\n5. Vector3D v2(5.0):" << endl;
    Vector3D v2(5.0);
    v2.display();
    
    // Test function calls with explicit objects
    cout << "\n6. Testing function calls:" << endl;
    calculateForce(v1);
    calculateForce(v2);
    
    cout << "\n--- The following would cause compilation errors ---" << endl;
    cout << "// SafeMoney sm3 = 100.5; // Error: implicit conversion not allowed" << endl;
    cout << "// processSecurePayment(25.0); // Error: implicit conversion not allowed" << endl;
    cout << "// calculateForce(3.0); // Error: implicit conversion not allowed" << endl;
    
    // Uncomment these lines one by one to see compilation errors:
    // SafeMoney sm3 = 100.5; // Error!
    // processSecurePayment(25.0); // Error!  
    // calculateForce(3.0); // Error!
    
    cout << "\nExplicit keyword prevents accidental implicit conversions!" << endl;
    cout << "Benefits:" << endl;
    cout << "- Prevents unintended type conversions" << endl;
    cout << "- Makes code more readable and intentional" << endl;
    cout << "- Reduces potential bugs from unexpected conversions" << endl;
    
    return 0;
} 