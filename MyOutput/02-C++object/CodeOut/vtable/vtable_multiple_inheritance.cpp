#include <iostream>
#include <typeinfo>
using namespace std;

// TODO 1: Define base classes for multiple inheritance
// Requirements:
// - Create class Flyable with virtual fly() and getFlightSpeed()
// - Create class Swimmable with virtual swim() and getSwimSpeed()
// - Both should have virtual destructors

class Flyable {
public:
    // TODO 1.1: Add virtual destructor
    virtual ~Flyable() {}

    // TODO 1.2: Add pure virtual function fly()
    virtual void fly() = 0;

    // TODO 1.3: Add virtual function getFlightSpeed() returning default 0
    virtual int getFlightSpeed() const { return 0; }

};

class Swimmable {
public:
    // TODO 1.4: Add virtual destructor
    virtual ~Swimmable() {}

    // TODO 1.5: Add pure virtual function swim()
    virtual void swim() = 0;

    // TODO 1.6: Add virtual function getSwimSpeed() returning default 0
    virtual int getSwimSpeed() const { return 0; }
};

// TODO 2: Create a class that inherits from both base classes
// Requirements:
// - Duck class inherits from both Flyable and Swimmable
// - Override all pure virtual functions
// - Add a unique virtual function quack()
class Duck : public Flyable, public Swimmable {
public:
    // TODO 2.1: Override fly() to print "Duck flying"
    virtual void fly() override { cout << "Duck flying" << endl; }

    // TODO 2.2: Override getFlightSpeed() to return 40
    virtual int getFlightSpeed() const override { return 40; }

    // TODO 2.3: Override swim() to print "Duck swimming"
    virtual void swim() override { cout << "Duck swimming" << endl; }

    // TODO 2.4: Override getSwimSpeed() to return 15
    virtual int getSwimSpeed() const override { return 15; }

    // TODO 2.5: Add virtual function quack()
    virtual void quack() { cout << "Duck quacking" << endl; }
};

// TODO 3: Create another multiple inheritance class with different capabilities
// Requirements:
// - Penguin class inherits from Swimmable only
// - Override virtual functions appropriately
// - Add unique behavior
class Penguin : public Swimmable {
public:
    // TODO 3.1: Override swim() to print "Penguin swimming fast"
    virtual void swim() override { cout << "Penguin swimming fast" << endl; }

    // TODO 3.2: Override getSwimSpeed() to return 25
    virtual int getSwimSpeed() const override { return 25; }

    // TODO 3.3: Add virtual function slide() printing "Penguin sliding on ice"
    virtual void slide() { cout << "Penguin sliding on ice" << endl; }
};

// TODO 4: Create a function to test Flyable interface
// Requirements:
// - Function name: testFlyable
// - Parameter: Flyable* flyable
// - Call fly() and getFlightSpeed()
// - Handle the case where object might not be able to fly
void testFlyable(Flyable* flyable) {
    // TODO 4.1: Test flying capabilities
    flyable->fly();
    cout << "Flight speed: " << flyable->getFlightSpeed() << " km/h" << endl;
}

// TODO 5: Create a function to test Swimmable interface  
// Requirements:
// - Function name: testSwimmable
// - Parameter: Swimmable* swimmable
// - Call swim() and getSwimSpeed()
void testSwimmable(Swimmable* swimmable) {
    // TODO 5.1: Test swimming capabilities
    swimmable->swim();
    cout << "Swim speed: " << swimmable->getSwimSpeed() << " km/h" << endl;
}

// TODO 6: Create a function to demonstrate pointer casting in multiple inheritance
// Requirements:
// - Function name: demonstratePointerCasting
// - Parameter: Duck* duck
// - Show how same object has different addresses when cast to different base types
// - Demonstrate that vtable pointers are different for each inheritance path
void demonstratePointerCasting(Duck* duck) {
    // TODO 6.1: Print address of Duck object
    cout << "Duck object address: " << (void*)duck << endl;

    // TODO 6.2: Cast to Flyable* and print address
    Flyable* flyable = dynamic_cast<Flyable*>(duck);
    cout << "As Flyable*: " << (void*)flyable << endl;

    // TODO 6.3: Cast to Swimmable* and print address
    Swimmable* swimmable = dynamic_cast<Swimmable*>(duck);
    cout << "As Swimmable*: " << (void*)swimmable << endl;

    // TODO 6.4: Explain the address differences
    cout << "Address difference shows multiple inheritance layout" << endl;

}

// TODO 7: Create a function to show vtable information for multiple inheritance
// Requirements:
// - Function name: showMultipleInheritanceVTable
// - Parameter: Duck* duck
// - Display size information
// - Show type information for different interface pointers
void showMultipleInheritanceVTable(Duck* duck) {
    // TODO 7.1: Print Duck object size

    // TODO 7.2: Print type information via different interface pointers

    // TODO 7.3: Demonstrate polymorphic behavior via different interfaces
}

int main() {
    cout << "=== Multiple Inheritance VTable Demonstration ===" << endl;

    // TODO 8: Create objects and demonstrate multiple inheritance vtable behavior
    // Requirements:
    // - Create Duck and Penguin objects
    // - Test them via different interface pointers
    // - Demonstrate pointer address differences
    // - Show vtable structure analysis
    // - Clean up memory

    cout << "\n--- Creating Duck object ---" << endl;
    // TODO 8.1: Create Duck object

    cout << "\n--- Creating Penguin object ---" << endl;
    // TODO 8.2: Create Penguin object

    cout << "\n--- Testing via Flyable interface ---" << endl;
    // TODO 8.3: Test Duck via Flyable interface

    cout << "\n--- Testing via Swimmable interface ---" << endl;
    // TODO 8.4: Test Duck and Penguin via Swimmable interface

    cout << "\n--- Pointer Casting Demonstration ---" << endl;
    // TODO 8.5: Demonstrate pointer casting with Duck

    cout << "\n--- VTable Analysis for Multiple Inheritance ---" << endl;
    // TODO 8.6: Show vtable information for Duck

    cout << "\n--- Cross-casting Demonstration ---" << endl;
    // TODO 8.7: Demonstrate casting between different base types
    // Show how to safely cast from Flyable* to Swimmable* via Duck*

    cout << "\n--- Diamond Problem Prevention ---" << endl;
    // TODO 8.8: Explain why this design avoids diamond problem
    // (Duck doesn't inherit from same base class twice)

    // TODO 8.9: Clean up memory

    return 0;
}

/*
Expected Output Example:
=== Multiple Inheritance VTable Demonstration ===

--- Creating Duck object ---

--- Creating Penguin object ---

--- Testing via Flyable interface ---
Duck flying
Flight speed: 40 km/h

--- Testing via Swimmable interface ---
Duck swimming
Swim speed: 15 km/h
Penguin swimming fast
Swim speed: 25 km/h

--- Pointer Casting Demonstration ---
Duck object address: 0x...
As Flyable*: 0x...
As Swimmable*: 0x... (different from above!)
Address difference shows multiple inheritance layout

--- VTable Analysis for Multiple Inheritance ---
Duck object size: 16 bytes (contains 2 vptrs)
Type via Flyable*: Duck
Type via Swimmable*: Duck

--- Cross-casting Demonstration ---
Safe casting between interfaces via common derived type

--- Diamond Problem Prevention ---
This design avoids diamond inheritance issues
*/ 