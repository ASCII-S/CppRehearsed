#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdint>
using namespace std;

// Solution for TODO 1: Create classes to analyze memory layout
class BaseClass {
private:
    int base_data;
    char base_char;
    
public:
    // TODO 1.1: Add constructor to initialize base_data to 100 and base_char to 'B'
    BaseClass() : base_data(100), base_char('B') {}
    
    // TODO 1.2: Add virtual destructor
    virtual ~BaseClass() = default;
    
    // TODO 1.3: Add virtual function baseVirtual() printing "Base virtual function"
    virtual void baseVirtual() {
        cout << "Base virtual function" << endl;
    }
    
    // TODO 1.4: Add virtual function getName() returning "BaseClass"
    virtual string getName() {
        return "BaseClass";
    }
    
    // TODO 1.5: Add getter functions for base_data and base_char
    int getBaseData() const { return base_data; }
    char getBaseChar() const { return base_char; }
};

class DerivedClass : public BaseClass {
private:
    double derived_data;
    short derived_short;
    
public:
    // TODO 2.1: Add constructor to initialize derived_data to 3.14 and derived_short to 200
    DerivedClass() : BaseClass(), derived_data(3.14), derived_short(200) {}
    
    // TODO 2.2: Override getName() to return "DerivedClass"
    string getName() override {
        return "DerivedClass";
    }
    
    // TODO 2.3: Add new virtual function derivedVirtual() printing "Derived virtual function"
    virtual void derivedVirtual() {
        cout << "Derived virtual function" << endl;
    }
    
    // TODO 2.4: Add getter functions for derived_data and derived_short
    double getDerivedData() const { return derived_data; }
    short getDerivedShort() const { return derived_short; }
};

// Solution for TODO 3: Create a class without virtual functions for comparison
class NonVirtualClass {
private:
    int data1;
    char data2;
    double data3;
    
public:
    // TODO 3.1: Add constructor to initialize data members
    NonVirtualClass() : data1(42), data2('N'), data3(2.718) {}
    
    // TODO 3.2: Add non-virtual functions for testing
    void nonVirtualFunction() {
        cout << "Non-virtual function" << endl;
    }
    
    string getName() {
        return "NonVirtualClass";
    }
    
    // TODO 3.3: Add getter functions
    int getData1() const { return data1; }
    char getData2() const { return data2; }
    double getData3() const { return data3; }
};

// Solution for TODO 4: Create utility functions to analyze memory layout
void printMemoryContent(void* ptr, size_t size, const string& description) {
    // TODO 4.1: Print memory content in hexadecimal format
    cout << "\n" << description << " at " << ptr << ":" << endl;
    unsigned char* bytes = static_cast<unsigned char*>(ptr);
    
    for (size_t i = 0; i < size; i += 8) {
        cout << hex << uppercase << setfill('0');
        cout << "0x" << setw(8) << (reinterpret_cast<uintptr_t>(ptr) + i) << ": ";
        
        for (size_t j = 0; j < 8 && (i + j) < size; ++j) {
            cout << setw(2) << static_cast<unsigned int>(bytes[i + j]) << " ";
        }
        
        cout << " ";
        for (size_t j = 0; j < 8 && (i + j) < size; ++j) {
            char c = bytes[i + j];
            cout << (isprint(c) ? c : '.');
        }
        cout << endl;
    }
    cout << dec;
}

void analyzeObjectSize(const string& className, size_t objectSize, size_t expectedDataSize) {
    // TODO 4.2: Analyze and print object size information
    cout << "\n--- " << className << " Size Analysis ---" << endl;
    cout << "Actual object size: " << objectSize << " bytes" << endl;
    cout << "Expected data size: " << expectedDataSize << " bytes" << endl;
    
    if (objectSize > expectedDataSize) {
        size_t overhead = objectSize - expectedDataSize;
        cout << "Additional overhead: " << overhead << " bytes" << endl;
        cout << "Likely contains: ";
        if (overhead >= 8) {
            cout << "vptr (8 bytes) + ";
            overhead -= 8;
        }
        if (overhead > 0) {
            cout << "padding (" << overhead << " bytes)";
        }
        cout << endl;
    }
    
    cout << "Memory alignment: " << alignof(void*) << " bytes" << endl;
}

void locateVPtr(void* objectPtr, size_t objectSize) {
    // TODO 4.3: Attempt to locate vptr in object memory
    cout << "\n--- VPtr Location Analysis ---" << endl;
    cout << "Object at address: " << objectPtr << endl;
    
    // First 8 bytes typically contain vptr
    void** potential_vptr = static_cast<void**>(objectPtr);
    cout << "Potential vptr value: " << *potential_vptr << endl;
    cout << "This points to the vtable in read-only memory" << endl;
    
    // Check if it looks like a valid memory address
    uintptr_t vptr_value = reinterpret_cast<uintptr_t>(*potential_vptr);
    cout << "VPtr as hex: 0x" << hex << vptr_value << dec << endl;
}

// Solution for TODO 5: Create function to demonstrate vtable address
void demonstrateVTableSharing() {
    // TODO 5.1: Create multiple objects of same class
    cout << "\n--- VTable Sharing Demonstration ---" << endl;
    
    BaseClass* obj1 = new BaseClass();
    BaseClass* obj2 = new BaseClass();
    DerivedClass* obj3 = new DerivedClass();
    DerivedClass* obj4 = new DerivedClass();
    
    // TODO 5.2: Extract and compare vtable addresses
    void** vtable1 = *reinterpret_cast<void***>(obj1);
    void** vtable2 = *reinterpret_cast<void***>(obj2);
    void** vtable3 = *reinterpret_cast<void***>(obj3);
    void** vtable4 = *reinterpret_cast<void***>(obj4);
    
    // TODO 5.3: Show that vtable is shared between objects
    cout << "BaseClass obj1 vtable: " << vtable1 << endl;
    cout << "BaseClass obj2 vtable: " << vtable2 << endl;
    cout << "Same vtable shared: " << (vtable1 == vtable2 ? "Yes" : "No") << endl;
    
    // TODO 5.4: Compare vtable addresses between different classes
    cout << "\nDerivedClass obj3 vtable: " << vtable3 << endl;
    cout << "DerivedClass obj4 vtable: " << vtable4 << endl;
    cout << "Same vtable shared: " << (vtable3 == vtable4 ? "Yes" : "No") << endl;
    cout << "Different from BaseClass: " << (vtable1 != vtable3 ? "Yes" : "No") << endl;
    
    delete obj1; delete obj2; delete obj3; delete obj4;
}

// Solution for TODO 6: Create function to analyze member variable layout
void analyzeMemberLayout() {
    // TODO 6.1: Create objects of different classes
    cout << "\n--- Member Variable Layout Analysis ---" << endl;
    
    BaseClass baseObj;
    DerivedClass derivedObj;
    NonVirtualClass nonVirtualObj;
    
    // TODO 6.2: Calculate and display member variable offsets
    cout << "\nBaseClass layout:" << endl;
    cout << "Object starts at: " << &baseObj << endl;
    cout << "vptr offset: 0 (first 8 bytes)" << endl;
    cout << "base_data offset: 8 bytes (after vptr)" << endl;
    cout << "base_char offset: 12 bytes (after base_data)" << endl;
    
    // TODO 6.3: Show how vptr affects member positions
    cout << "\nDerivedClass layout:" << endl;
    cout << "Object starts at: " << &derivedObj << endl;
    cout << "Inherited vptr offset: 0" << endl;
    cout << "Inherited members follow base class layout" << endl;
    cout << "derived_data at offset ~16 bytes" << endl;
    cout << "derived_short at offset ~24 bytes" << endl;
    
    // TODO 6.4: Compare with non-virtual class layout
    cout << "\nNonVirtualClass layout (no vptr):" << endl;
    cout << "Object starts at: " << &nonVirtualObj << endl;
    cout << "data1 offset: 0 (no vptr present)" << endl;
    cout << "data2 offset: 4" << endl;
    cout << "data3 offset: 8 (with alignment padding)" << endl;
}

// Solution for TODO 7: Create function to demonstrate virtual function call overhead
void demonstrateCallOverhead() {
    // TODO 7.1: Create objects for testing
    cout << "\n--- Virtual Function Call Mechanism ---" << endl;
    
    BaseClass* virtualObj = new DerivedClass();
    DerivedClass directObj;
    
    // TODO 7.2: Demonstrate virtual function call mechanism
    cout << "\nVirtual function call process:" << endl;
    cout << "1. obj->virtualFunction() becomes:" << endl;
    cout << "2. Load vptr from object (first 8 bytes)" << endl;
    cout << "3. Index into vtable: vtable[function_index]" << endl;
    cout << "4. Call function at that address" << endl;
    
    // TODO 7.3: Show conceptual difference in call resolution
    cout << "\nDemonstration:" << endl;
    cout << "Virtual call: ";
    virtualObj->baseVirtual(); // Goes through vtable
    
    cout << "Direct call: ";
    directObj.baseVirtual(); // Also virtual, but compiler might optimize
    
    cout << "Explicit direct call: ";
    directObj.DerivedClass::baseVirtual(); // Bypasses vtable
    
    // TODO 7.4: Basic timing comparison (optional)
    cout << "\nPerformance implications:" << endl;
    cout << "- Virtual calls: ~1-2 extra memory accesses" << endl;
    cout << "- Branch prediction affects performance" << endl;
    cout << "- Inlining typically not possible" << endl;
    
    delete virtualObj;
}

int main() {
    cout << "=== VTable Memory Layout Analysis ===" << endl;
    
    // Solution for TODO 8: Main demonstration sequence
    
    cout << "\n--- Object Size Analysis ---" << endl;
    // TODO 8.1: Print sizes of different classes
    cout << "BaseClass size: " << sizeof(BaseClass) << " bytes" << endl;
    cout << "DerivedClass size: " << sizeof(DerivedClass) << " bytes" << endl;
    cout << "NonVirtualClass size: " << sizeof(NonVirtualClass) << " bytes" << endl;
    
    analyzeObjectSize("BaseClass", sizeof(BaseClass), sizeof(int) + sizeof(char));
    analyzeObjectSize("DerivedClass", sizeof(DerivedClass), sizeof(BaseClass) + sizeof(double) + sizeof(short));
    analyzeObjectSize("NonVirtualClass", sizeof(NonVirtualClass), sizeof(int) + sizeof(char) + sizeof(double));
    
    cout << "\n--- Memory Layout Analysis ---" << endl;
    // TODO 8.2: Create objects and analyze their memory layout
    BaseClass* basePtr = new BaseClass();
    DerivedClass* derivedPtr = new DerivedClass();
    NonVirtualClass* nonVirtualPtr = new NonVirtualClass();
    
    printMemoryContent(basePtr, sizeof(*basePtr), "BaseClass object");
    printMemoryContent(derivedPtr, sizeof(*derivedPtr), "DerivedClass object");
    printMemoryContent(nonVirtualPtr, sizeof(*nonVirtualPtr), "NonVirtualClass object");
    
    locateVPtr(basePtr, sizeof(*basePtr));
    locateVPtr(derivedPtr, sizeof(*derivedPtr));
    
    cout << "\n--- VTable Sharing Demonstration ---" << endl;
    // TODO 8.3: Demonstrate vtable sharing between objects
    demonstrateVTableSharing();
    
    cout << "\n--- Member Variable Layout ---" << endl;
    // TODO 8.4: Analyze member variable positioning
    analyzeMemberLayout();
    
    cout << "\n--- Virtual Function Call Mechanism ---" << endl;
    // TODO 8.5: Demonstrate call overhead concepts
    demonstrateCallOverhead();
    
    cout << "\n--- Practical Implications ---" << endl;
    // TODO 8.6: Summarize practical implications of vtable layout
    cout << "Memory overhead:" << endl;
    cout << "- 8 bytes per object with virtual functions (vptr)" << endl;
    cout << "- Shared vtable per class (minimal per-class overhead)" << endl;
    cout << "- Additional memory alignment padding" << endl;
    
    cout << "\nPerformance implications:" << endl;
    cout << "- Virtual calls: 1-2 extra memory accesses" << endl;
    cout << "- Cache locality: vtable accesses may cause cache misses" << endl;
    cout << "- Branch prediction: random virtual calls hurt performance" << endl;
    cout << "- Inlining: virtual functions typically cannot be inlined" << endl;
    
    cout << "\nDesign considerations:" << endl;
    cout << "- Use virtual functions for polymorphism, not performance" << endl;
    cout << "- Consider templates for compile-time polymorphism" << endl;
    cout << "- Profile real workloads to measure actual impact" << endl;
    cout << "- Modern CPUs handle virtual calls efficiently" << endl;
    
    delete basePtr;
    delete derivedPtr;
    delete nonVirtualPtr;
    
    return 0;
} 