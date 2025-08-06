#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// TODO 1: Create classes to analyze memory layout
// Requirements:
// - BaseClass with virtual functions and data members
// - DerivedClass with additional virtual functions and data members
// - Show how vptr affects memory layout

class BaseClass {
private:
    int base_data;
    char base_char;
    
public:
    // TODO 1.1: Add constructor to initialize base_data to 100 and base_char to 'B'
    
    // TODO 1.2: Add virtual destructor
    
    // TODO 1.3: Add virtual function baseVirtual() printing "Base virtual function"
    
    // TODO 1.4: Add virtual function getName() returning "BaseClass"
    
    // TODO 1.5: Add getter functions for base_data and base_char
};

class DerivedClass : public BaseClass {
private:
    double derived_data;
    short derived_short;
    
public:
    // TODO 2.1: Add constructor to initialize derived_data to 3.14 and derived_short to 200
    
    // TODO 2.2: Override getName() to return "DerivedClass"
    
    // TODO 2.3: Add new virtual function derivedVirtual() printing "Derived virtual function"
    
    // TODO 2.4: Add getter functions for derived_data and derived_short
};

// TODO 3: Create a class without virtual functions for comparison
class NonVirtualClass {
private:
    int data1;
    char data2;
    double data3;
    
public:
    // TODO 3.1: Add constructor to initialize data members
    
    // TODO 3.2: Add non-virtual functions for testing
    
    // TODO 3.3: Add getter functions
};

// TODO 4: Create utility functions to analyze memory layout
// Requirements:
// - Function to print memory contents in hex
// - Function to analyze object size and alignment
// - Function to locate vptr position

void printMemoryContent(void* ptr, size_t size, const string& description) {
    // TODO 4.1: Print memory content in hexadecimal format
    // Print both address and content
    // Show 8 bytes per line for readability
}

void analyzeObjectSize(const string& className, size_t objectSize, size_t expectedDataSize) {
    // TODO 4.2: Analyze and print object size information
    // Compare actual size with expected data size
    // Calculate and display vptr overhead
    // Discuss memory alignment
}

void locateVPtr(void* objectPtr, size_t objectSize) {
    // TODO 4.3: Attempt to locate vptr in object memory
    // Print potential vptr values (first 8 bytes typically)
    // Explain what vptr points to
}

// TODO 5: Create function to demonstrate vtable address
// Requirements:
// - Show that objects of same class share vtable
// - Compare vtable addresses between different objects
// - Demonstrate vtable is in read-only memory

void demonstrateVTableSharing() {
    // TODO 5.1: Create multiple objects of same class
    
    // TODO 5.2: Extract and compare vtable addresses
    
    // TODO 5.3: Show that vtable is shared between objects
    
    // TODO 5.4: Compare vtable addresses between different classes
}

// TODO 6: Create function to analyze member variable layout
// Requirements:
// - Show how virtual functions affect member variable positions
// - Compare layout with and without virtual functions
// - Demonstrate memory alignment effects

void analyzeMemberLayout() {
    // TODO 6.1: Create objects of different classes
    
    // TODO 6.2: Calculate and display member variable offsets
    
    // TODO 6.3: Show how vptr affects member positions
    
    // TODO 6.4: Compare with non-virtual class layout
}

// TODO 7: Create function to demonstrate virtual function call overhead
// Requirements:
// - Compare direct function call vs virtual function call
// - Show assembly-level difference (conceptually)
// - Time virtual vs non-virtual calls (basic measurement)

void demonstrateCallOverhead() {
    // TODO 7.1: Create objects for testing
    
    // TODO 7.2: Demonstrate virtual function call mechanism
    
    // TODO 7.3: Show conceptual difference in call resolution
    
    // TODO 7.4: Basic timing comparison (optional)
}

int main() {
    cout << "=== VTable Memory Layout Analysis ===" << endl;
    
    // TODO 8: Main demonstration sequence
    // Requirements:
    // - Analyze sizes of different class objects
    // - Print memory layouts
    // - Show vtable sharing
    // - Demonstrate member variable positioning
    // - Show call overhead concepts
    
    cout << "\n--- Object Size Analysis ---" << endl;
    // TODO 8.1: Print sizes of different classes
    // Compare BaseClass, DerivedClass, and NonVirtualClass
    
    cout << "\n--- Memory Layout Analysis ---" << endl;
    // TODO 8.2: Create objects and analyze their memory layout
    
    cout << "\n--- VTable Sharing Demonstration ---" << endl;
    // TODO 8.3: Demonstrate vtable sharing between objects
    
    cout << "\n--- Member Variable Layout ---" << endl;
    // TODO 8.4: Analyze member variable positioning
    
    cout << "\n--- Virtual Function Call Mechanism ---" << endl;
    // TODO 8.5: Demonstrate call overhead concepts
    
    cout << "\n--- Practical Implications ---" << endl;
    // TODO 8.6: Summarize practical implications of vtable layout
    // - Memory overhead
    // - Performance implications
    // - Design considerations
    
    return 0;
}

/*
Expected Output Example:
=== VTable Memory Layout Analysis ===

--- Object Size Analysis ---
BaseClass size: 16 bytes (8 bytes vptr + 5 bytes data + 3 bytes padding)
DerivedClass size: 32 bytes (inherited + 10 bytes data + padding)
NonVirtualClass size: 16 bytes (no vptr, only data + padding)

--- Memory Layout Analysis ---
BaseClass object at 0x...
Memory content:
0x...: 12 34 56 78 9A BC DE F0  (vptr to vtable)
0x...: 64 00 00 00 42 00 00 00  (base_data=100, base_char='B', padding)

DerivedClass object at 0x...
Memory content:
0x...: 12 34 56 78 9A BC DE F0  (vptr to derived vtable)
0x...: 64 00 00 00 42 00 00 00  (inherited base data)
0x...: 1F 85 EB 51 B8 1E 09 40  (derived_data=3.14)
0x...: C8 00 00 00 00 00 00 00  (derived_short=200, padding)

--- VTable Sharing Demonstration ---
BaseClass object1 vtable: 0x...
BaseClass object2 vtable: 0x... (same as object1)
DerivedClass object vtable: 0x... (different from BaseClass)

--- Member Variable Layout ---
In BaseClass:
  vptr offset: 0
  base_data offset: 8
  base_char offset: 12

In DerivedClass:
  vptr offset: 0 (inherited)
  base_data offset: 8 (inherited)
  base_char offset: 12 (inherited)
  derived_data offset: 16
  derived_short offset: 24

--- Virtual Function Call Mechanism ---
Virtual call: obj->virtualFunc()
1. Load vptr from object
2. Index into vtable
3. Call function at vtable[index]

Direct call: obj.nonVirtualFunc()
1. Direct call to known address

--- Practical Implications ---
- Memory overhead: 8 bytes per object with virtual functions
- Call overhead: One additional indirection
- Design benefit: Runtime polymorphism capability
*/ 