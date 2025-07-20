/**
 * File: explicit_demo.cpp  
 * Purpose: Demonstrate the use of explicit keyword to prevent implicit conversions
 * Time estimate: 9 minutes
 * 
 * Learning objectives:
 * 1. Learn how to use explicit keyword with constructors
 * 2. Understand compilation errors when implicit conversion is prevented
 * 3. Practice explicit object construction
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// TODO 1: Create a SafeMoney class with explicit constructor (3 minutes)
// - Add private member: double amount
// - Add explicit single-parameter constructor taking double
// - Add getter: getAmount()
// - Add display method: show() that prints "SafeMoney: $" + amount
// - Add a copy constructor (can be default)

class SafeMoney {
    // TODO: Implement SafeMoney class with explicit constructor
    double amount;
public:    
    explicit SafeMoney(){}
    explicit SafeMoney(double a): amount(a){
        cout << "SafeMoney explicit constructor called with: " << a << " " << typeid(a).name() << endl;
    }

    SafeMoney(const SafeMoney &other){
        amount = other.amount;
    }

    double getter(){return amount;}

    void show(){
        std::cout << "SafeMoney: $" << amount << std::endl;
    }
};

// TODO 2: Create a Vector3D class (3 minutes)
// - Add private members: double x, y, z
// - Add explicit constructor taking double value (sets all components to same value)
// - Add explicit constructor taking three doubles x, y, z
// - Add method: display() that prints "Vector3D(x, y, z)"
// - Add method: magnitude() that returns sqrt(x*x + y*y + z*z)

#include <cmath>

class Vector3D {
    // TODO: Implement Vector3D class with explicit constructors
    double x,y,z;
public:
    explicit Vector3D(double i): x(i),y(i),z(i) {}

    explicit Vector3D(double ix, double iy, double iz): x(ix),y(iy),z(iz) {}

    void display(){
        std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
    }

    double magnitude(){
        return sqrt(x*x + y*y + z*z);
    }
};

// TODO 3: Create test functions (1 minute)
// void processSecurePayment(SafeMoney m) - prints "Secure payment: " + m.getAmount()  
// void calculateForce(Vector3D v) - prints "Force vector: " then call v.display()

// TODO: Implement test functions here
void processSecurePayment(SafeMoney m){
    std::cout << "Secure Payment: " << m.getter() << std::endl;
}

void calculateForce(Vector3D v){
    std::cout << "Force vector: " << v.magnitude() << std::endl;
}

// TODO 4: Test explicit behavior in main (2 minutes)
// Try these scenarios and observe compilation results:
// 1. SafeMoney sm1(100.5); - should work (direct initialization)
// 2. SafeMoney sm2 = SafeMoney(75.25); - should work (explicit construction)
// 3. processSecurePayment(SafeMoney(50.0)); - should work (explicit conversion)
// 4. Vector3D v1(1.0, 2.0, 3.0); - should work
// 5. Vector3D v2(5.0); - should work (single value constructor)
//
// UNCOMMENT these lines one by one to see compilation errors:
// SafeMoney sm3 = 100.5; // Should cause compilation error
// processSecurePayment(25.0); // Should cause compilation error  
// calculateForce(3.0); // Should cause compilation error

int main() {
    cout << "=== Explicit Keyword Demo ===" << endl;
    
    // TODO: Add working test cases here
    SafeMoney sm1(100.5);
    SafeMoney sm2(100);           // direct initialization here is allowed, because it is not a implicit conversion
    SafeMoney sm3 = SafeMoney(101.6);      
    // SafeMoney sm4 = 100.5;                  // 1. error: implicit conversion not allowed
    SafeMoney sm4;
    sm4 = SafeMoney(100.4);
    // sm4 = 100.4;     // 2. error: implicit conversion not allowed
    processSecurePayment(sm1);
    processSecurePayment(sm2);
    processSecurePayment(SafeMoney(25.8));
    // processSecurePayment(100.5);        // 3. error: implicit conversion not allowed
    
    cout << "\n--- The following would cause compilation errors ---" << endl;
    cout << "// SafeMoney sm3 = 100.5; // Error: implicit conversion not allowed" << endl;
    cout << "// processSecurePayment(25.0); // Error: implicit conversion not allowed" << endl;
    cout << "// calculateForce(3.0); // Error: implicit conversion not allowed" << endl;
    
    cout << "\nExplicit keyword prevents accidental implicit conversions!" << endl;
    
    return 0;
}

/* 
Expected output should be:
=== Explicit Keyword Demo ===
SafeMoney: $100.5
SafeMoney: $75.25
Secure payment: 75.25
Secure payment: 50
Vector3D(1, 2, 3)
Vector3D(5, 5, 5)
Force vector: Vector3D(1, 2, 3)
Force vector: Vector3D(5, 5, 5)

--- The following would cause compilation errors ---
// SafeMoney sm3 = 100.5; // Error: implicit conversion not allowed
// processSecurePayment(25.0); // Error: implicit conversion not allowed
// calculateForce(3.0); // Error: implicit conversion not allowed

Explicit keyword prevents accidental implicit conversions!
*/ 