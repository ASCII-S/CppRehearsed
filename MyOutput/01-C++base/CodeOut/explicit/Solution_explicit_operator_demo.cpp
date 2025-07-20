/**
 * File: Solution_explicit_operator_demo.cpp
 * Purpose: Complete solution for explicit conversion operators demonstration
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution for TODO 1: Score class with implicit conversion operators
class Score {
private:
    int points;
    
public:
    Score(int value) : points(value) {}
    
    // Implicit conversion to bool
    operator bool() const {
        return points > 0;
    }
    
    // Implicit conversion to double  
    operator double() const {
        return points / 100.0;
    }
    
    int getPoints() const {
        return points;
    }
};

// Solution for TODO 2: SafePointer class with explicit conversion operators
class SafePointer {
private:
    int* ptr;
    
public:
    SafePointer(int* value) : ptr(value) {}
    
    // Explicit conversion to bool
    explicit operator bool() const {
        return ptr != nullptr;
    }
    
    // Explicit conversion to int
    explicit operator int() const {
        return ptr ? *ptr : 0;
    }
    
    ~SafePointer() {
        // We don't own the memory, so don't delete
    }
    
    bool isValid() const {
        return ptr != nullptr;
    }
};

// Solution for TODO 3: Container class with explicit bool conversion
class Container {
private:
    vector<int> data;
    
public:
    void add(int value) {
        data.push_back(value);
    }
    
    size_t size() const {
        return data.size();
    }
    
    // Explicit conversion to bool
    explicit operator bool() const {
        return !data.empty();
    }
    
    void clear() {
        data.clear();
    }
};

// Test function for demonstrating implicit conversion problems
void testImplicitBehavior() {
    cout << "=== Testing Implicit Conversion Operators ===" << endl;
    
    Score s1(85);
    Score s2(0);
    
    // These work due to implicit conversion:
    if (s1) cout << "s1 has positive points" << endl;
    if (!s2) cout << "s2 has no points" << endl;
    
    double percentage = s1; // Implicit conversion to double
    cout << "s1 as percentage: " << percentage << endl;
    
    // This might be problematic - accidental conversions:
    bool result = s1 + s2; // Both convert to bool, then bool arithmetic!
    cout << "s1 + s2 as bool: " << result << " (probably not intended!)" << endl;
    
    cout << "Problem: Arithmetic on Score objects converts to bool unexpectedly!" << endl;
}

// Solution for TODO 5: testExplicitBehavior function
void testExplicitBehavior() {
    cout << "\n=== Testing Explicit Conversion Operators ===" << endl;
    
    // SafePointer tests
    int value = 42;
    SafePointer sp1(&value);
    SafePointer sp2(nullptr);
    
    // Must use explicit conversion
    if (static_cast<bool>(sp1)) {
        cout << "sp1 is valid" << endl;
    }
    
    if (!static_cast<bool>(sp2)) {
        cout << "sp2 is not valid" << endl;
    }
    
    // Explicit int conversion
    int val = static_cast<int>(sp1);
    cout << "sp1 value: " << val << endl;
    
    int val2 = static_cast<int>(sp2);
    cout << "sp2 value: " << val2 << endl;
    
    // These would cause compilation errors:
    // bool implicitBool = sp1; // Error!
    // int implicitInt = sp1; // Error!
    
    cout << "\n--- Container tests ---" << endl;
    
    // Container tests
    Container c1;
    c1.add(1);
    c1.add(2);
    c1.add(3);
    
    Container c2; // empty
    
    // Must use explicit conversion to bool
    if (static_cast<bool>(c1)) {
        cout << "Container c1 has " << c1.size() << " elements and is not empty" << endl;
    }
    
    if (!static_cast<bool>(c2)) {
        cout << "Container c2 has " << c2.size() << " elements and is empty" << endl;
    }
    
    // These would cause compilation errors:
    // bool implicitEmpty = c1; // Error!
    // if (c1) { ... } // Error! Must use static_cast<bool>(c1)
    
    cout << "\nAdvantage: No accidental conversions possible!" << endl;
}

int main() {
    testImplicitBehavior();
    testExplicitBehavior();
    
    cout << "\n=== Summary ===" << endl;
    cout << "Implicit conversion operators can lead to unexpected behavior:" << endl;
    cout << "- Arithmetic operations may trigger unintended conversions" << endl;
    cout << "- Function overload resolution can be ambiguous" << endl;
    cout << "- Code becomes less readable and predictable" << endl;
    cout << "\nExplicit conversion operators provide safer, more intentional conversions:" << endl;
    cout << "- Must explicitly request the conversion with static_cast" << endl;
    cout << "- Prevents accidental usage in expressions" << endl;
    cout << "- Makes code intent clearer" << endl;
    cout << "\nRule of thumb: Use explicit for conversion operators unless you specifically" << endl;
    cout << "want the convenience of implicit conversion AND it's safe!" << endl;
    
    return 0;
} 