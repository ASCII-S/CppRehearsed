/**
 * File: explicit_operator_demo.cpp
 * Purpose: Demonstrate explicit conversion operators (C++11 feature)
 * Time estimate: 10 minutes
 * 
 * Learning objectives:
 * 1. Learn about conversion operators and their implicit behavior
 * 2. Understand explicit conversion operators
 * 3. Practice safe type conversions
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TODO 1: Create a Score class with implicit conversion operator (3 minutes)
// - Add private member: int points
// - Add constructor taking int value
// - Add implicit conversion operator to bool (returns points > 0)
// - Add implicit conversion operator to double (returns points / 100.0)
// - Add getter: getPoints()

class Score {
    // TODO: Implement Score class with implicit conversion operators

};

// TODO 2: Create a SafePointer class with explicit conversion operators (4 minutes)
// - Add private member: int* ptr
// - Add constructor taking int* value (can be nullptr)
// - Add explicit conversion operator to bool (returns ptr != nullptr)
// - Add explicit conversion operator to int (returns ptr ? *ptr : 0)
// - Add destructor that does nothing (we don't own the memory)
// - Add method: isValid() that returns ptr != nullptr

class SafePointer {
    // TODO: Implement SafePointer class with explicit conversion operators

};

// TODO 3: Create a Container class with explicit bool conversion (3 minutes)  
// - Add private member: vector<int> data
// - Add method: add(int value) to add elements
// - Add method: size() that returns data.size()
// - Add explicit conversion operator to bool (returns !data.empty())
// - Add method: clear() to clear the vector

class Container {
    // TODO: Implement Container class

};

// Test function for demonstrating differences
void testImplicitBehavior() {
    cout << "=== Testing Implicit Conversion Operators ===" << endl;
    
    // TODO 4: Test Score class implicit conversions (feel free to modify)
    Score s1(85);
    Score s2(0);
    
    // These should work due to implicit conversion:
    if (s1) cout << "s1 has positive points" << endl;
    if (!s2) cout << "s2 has no points" << endl;
    
    double percentage = s1; // Implicit conversion to double
    cout << "s1 as percentage: " << percentage << endl;
    
    // This might be problematic - accidental conversions:
    bool result = s1 + s2; // Both convert to bool, then bool arithmetic!
    cout << "s1 + s2 as bool: " << result << " (probably not intended!)" << endl;
}

// TODO 5: Implement testExplicitBehavior function
void testExplicitBehavior() {
    cout << "\n=== Testing Explicit Conversion Operators ===" << endl;
    
    // TODO: Create SafePointer tests
    // 1. Create int value = 42
    // 2. Create SafePointer sp1(&value) and SafePointer sp2(nullptr)
    // 3. Test explicit bool conversion: if (static_cast<bool>(sp1))
    // 4. Test explicit int conversion: int val = static_cast<int>(sp1)
    // 5. Show that implicit conversions won't work (add comments)
    
    // TODO: Create Container tests  
    // 1. Create Container c1 and add some values
    // 2. Create empty Container c2
    // 3. Test explicit bool conversion with static_cast<bool>()
    // 4. Show size information
}

int main() {
    testImplicitBehavior();
    testExplicitBehavior();
    
    cout << "\n=== Summary ===" << endl;
    cout << "Implicit conversion operators can lead to unexpected behavior." << endl;
    cout << "Explicit conversion operators provide safer, more intentional conversions." << endl;
    cout << "Use explicit when you want to prevent accidental conversions!" << endl;
    
    return 0;
}

/* 
Expected output should include:
=== Testing Implicit Conversion Operators ===
s1 has positive points
s2 has no points  
s1 as percentage: 0.85
s1 + s2 as bool: 1 (probably not intended!)

=== Testing Explicit Conversion Operators ===
sp1 is valid
sp1 value: 42
sp2 is not valid
sp2 value: 0
Container c1 has 3 elements and is not empty
Container c2 has 0 elements and is empty

=== Summary ===
Implicit conversion operators can lead to unexpected behavior.
Explicit conversion operators provide safer, more intentional conversions.
Use explicit when you want to prevent accidental conversions!
*/ 