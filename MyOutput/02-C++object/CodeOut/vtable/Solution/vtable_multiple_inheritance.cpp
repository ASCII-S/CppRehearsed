#include <iostream>
#include <typeinfo>
using namespace std;

// Solution for TODO 1: Define base classes for multiple inheritance
class Flyable {
public:
    // TODO 1.1: Add virtual destructor
    virtual ~Flyable() = default;

    // TODO 1.2: Add pure virtual function fly()
    virtual void fly() = 0;

    // TODO 1.3: Add virtual function getFlightSpeed() returning default 0
    virtual int getFlightSpeed() {
        return 0;
    }
};

class Swimmable {
public:
    // TODO 1.4: Add virtual destructor
    virtual ~Swimmable() = default;

    // TODO 1.5: Add pure virtual function swim()
    virtual void swim() = 0;

    // TODO 1.6: Add virtual function getSwimSpeed() returning default 0
    virtual int getSwimSpeed() {
        return 0;
    }
};

// Solution for TODO 2: Create a class that inherits from both base classes
class Duck : public Flyable, public Swimmable {
public:
    // TODO 2.1: Override fly() to print "Duck flying"
    void fly() override {
        cout << "Duck flying" << endl;
    }

    // TODO 2.2: Override getFlightSpeed() to return 40
    int getFlightSpeed() override {
        return 40;
    }

    // TODO 2.3: Override swim() to print "Duck swimming"
    void swim() override {
        cout << "Duck swimming" << endl;
    }

    // TODO 2.4: Override getSwimSpeed() to return 15
    int getSwimSpeed() override {
        return 15;
    }

    // TODO 2.5: Add virtual function quack()
    virtual void quack() {
        cout << "Duck quacking: Quack! Quack!" << endl;
    }
};

// Solution for TODO 3: Create another multiple inheritance class with different capabilities
class Penguin : public Swimmable {
public:
    // TODO 3.1: Override swim() to print "Penguin swimming fast"
    void swim() override {
        cout << "Penguin swimming fast" << endl;
    }

    // TODO 3.2: Override getSwimSpeed() to return 25
    int getSwimSpeed() override {
        return 25;
    }

    // TODO 3.3: Add virtual function slide() printing "Penguin sliding on ice"
    virtual void slide() {
        cout << "Penguin sliding on ice" << endl;
    }
};

// Solution for TODO 4: Create a function to test Flyable interface
void testFlyable(Flyable* flyable) {
    // TODO 4.1: Test flying capabilities
    cout << "Testing flying capabilities:" << endl;
    flyable->fly();
    cout << "Flight speed: " << flyable->getFlightSpeed() << " km/h" << endl;
}

// Solution for TODO 5: Create a function to test Swimmable interface  
void testSwimmable(Swimmable* swimmable) {
    // TODO 5.1: Test swimming capabilities
    cout << "Testing swimming capabilities:" << endl;
    swimmable->swim();
    cout << "Swim speed: " << swimmable->getSwimSpeed() << " km/h" << endl;
}

// Solution for TODO 6: Create a function to demonstrate pointer casting in multiple inheritance
void demonstratePointerCasting(Duck* duck) {
    // TODO 6.1: Print address of Duck object
    cout << "Duck object address: " << static_cast<void*>(duck) << endl;

    // TODO 6.2: Cast to Flyable* and print address
    Flyable* flyable_ptr = static_cast<Flyable*>(duck);
    cout << "As Flyable*: " << static_cast<void*>(flyable_ptr) << endl;

    // TODO 6.3: Cast to Swimmable* and print address
    Swimmable* swimmable_ptr = static_cast<Swimmable*>(duck);
    cout << "As Swimmable*: " << static_cast<void*>(swimmable_ptr) << endl;

    // TODO 6.4: Explain the address differences
    cout << "Address difference shows multiple inheritance layout:" << endl;
    cout << "- Flyable interface at offset 0" << endl;
    cout << "- Swimmable interface at offset " 
         << (reinterpret_cast<char*>(swimmable_ptr) - reinterpret_cast<char*>(duck)) 
         << " bytes" << endl;
}

// Solution for TODO 7: Create a function to show vtable information for multiple inheritance
void showMultipleInheritanceVTable(Duck* duck) {
    // TODO 7.1: Print Duck object size
    cout << "Duck object size: " << sizeof(*duck) << " bytes (contains 2 vptrs)" << endl;

    // TODO 7.2: Print type information via different interface pointers
    Flyable* flyable_ptr = static_cast<Flyable*>(duck);
    Swimmable* swimmable_ptr = static_cast<Swimmable*>(duck);
    
    cout << "Type via Flyable*: " << typeid(*flyable_ptr).name() << endl;
    cout << "Type via Swimmable*: " << typeid(*swimmable_ptr).name() << endl;

    // TODO 7.3: Demonstrate polymorphic behavior via different interfaces
    cout << "\nPolymorphic behavior through different interfaces:" << endl;
    cout << "Via Flyable interface: ";
    flyable_ptr->fly();
    cout << "Via Swimmable interface: ";
    swimmable_ptr->swim();
}

int main() {
    cout << "=== Multiple Inheritance VTable Demonstration ===" << endl;

    // Solution for TODO 8: Create objects and demonstrate multiple inheritance vtable behavior

    cout << "\n--- Creating Duck object ---" << endl;
    // TODO 8.1: Create Duck object
    Duck* duck = new Duck();

    cout << "\n--- Creating Penguin object ---" << endl;
    // TODO 8.2: Create Penguin object
    Penguin* penguin = new Penguin();

    cout << "\n--- Testing via Flyable interface ---" << endl;
    // TODO 8.3: Test Duck via Flyable interface
    testFlyable(duck);

    cout << "\n--- Testing via Swimmable interface ---" << endl;
    // TODO 8.4: Test Duck and Penguin via Swimmable interface
    cout << "Duck swimming test:" << endl;
    testSwimmable(duck);
    cout << "\nPenguin swimming test:" << endl;
    testSwimmable(penguin);

    cout << "\n--- Pointer Casting Demonstration ---" << endl;
    // TODO 8.5: Demonstrate pointer casting with Duck
    demonstratePointerCasting(duck);

    cout << "\n--- VTable Analysis for Multiple Inheritance ---" << endl;
    // TODO 8.6: Show vtable information for Duck
    showMultipleInheritanceVTable(duck);

    cout << "\n--- Cross-casting Demonstration ---" << endl;
    // TODO 8.7: Demonstrate casting between different base types
    cout << "Cross-casting between interfaces:" << endl;
    Flyable* flyable_ref = static_cast<Flyable*>(duck);
    Duck* duck_from_flyable = static_cast<Duck*>(flyable_ref);
    Swimmable* swimmable_from_duck = static_cast<Swimmable*>(duck_from_flyable);
    Duck* duck_from_swimmable = static_cast<Duck*>(swimmable_from_duck);
    
    cout << "Original Duck: " << static_cast<void*>(duck) << endl;
    cout << "Via Flyable*: " << static_cast<void*>(flyable_ref) << endl;
    cout << "Back to Duck*: " << static_cast<void*>(duck_from_flyable) << endl;
    cout << "To Swimmable*: " << static_cast<void*>(swimmable_from_duck) << endl;
    cout << "Back to Duck*: " << static_cast<void*>(duck_from_swimmable) << endl;
    cout << "Safe casting maintains object identity" << endl;

    cout << "\n--- Diamond Problem Prevention ---" << endl;
    // TODO 8.8: Explain why this design avoids diamond problem
    cout << "This design avoids diamond inheritance issues because:" << endl;
    cout << "- Duck inherits from two DIFFERENT base classes" << endl;
    cout << "- No shared common ancestor between Flyable and Swimmable" << endl;
    cout << "- Each interface has its own vtable and vptr" << endl;
    cout << "- No ambiguity in member function resolution" << endl;

    // Demonstrate unique behaviors
    cout << "\n--- Unique Duck behaviors ---" << endl;
    duck->quack();
    cout << "\n--- Unique Penguin behaviors ---" << endl;
    penguin->slide();

    // TODO 8.9: Clean up memory
    delete duck;
    delete penguin;

    return 0;
} 