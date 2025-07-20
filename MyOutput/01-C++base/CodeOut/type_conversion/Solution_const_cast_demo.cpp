#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Solution for TODO 1: Define a class named DataContainer
class DataContainer {
private:
    int data;
    
public:
    DataContainer(int d) : data(d) {}
    
    int getData() const {
        return data;
    }
    
    void setData(int d) {
        data = d;
    }
    
    void doubleData() {
        data *= 2;
    }
};

// Solution for TODO 2: Create a function named printData
void printData(const DataContainer& container) {
    cout << "Data value: " << container.getData() << endl;
}

// Solution for TODO 3: Create a function named modifyData
void modifyData(const DataContainer& container) {
    DataContainer& nonConstContainer = const_cast<DataContainer&>(container);
    nonConstContainer.doubleData();
    cout << "Data was modified (doubled)" << endl;
}

// Solution for TODO 4: Create a function named processString
void processString(const char* str) {
    cout << "Original string: " << str << endl;
    
    char* nonConstStr = const_cast<char*>(str);
    if (nonConstStr[0] >= 'a' && nonConstStr[0] <= 'z') {
        nonConstStr[0] = nonConstStr[0] - 'a' + 'A';  // Convert to uppercase
    }
    
    cout << "Modified string: " << str << endl;
}

int main() {
    cout << "=== const_cast Demo ===" << endl;
    
    // Solution for TODO 5: Safe const_cast example
    cout << "\n=== Safe const_cast (original object is non-const) ===" << endl;
    
    DataContainer container(10);
    const DataContainer& constRef = container;
    
    cout << "Before modification: ";
    printData(constRef);
    
    DataContainer& nonConstRef = const_cast<DataContainer&>(constRef);
    nonConstRef.setData(20);
    
    cout << "After modification: ";
    printData(constRef);
    
    // Solution for TODO 6: const_cast with const object (undefined behavior)
    cout << "\n=== Dangerous const_cast (original object is const) ===" << endl;
    
    /*
    // COMMENTED OUT - This would be undefined behavior!
    const DataContainer constContainer(30);
    DataContainer& nonConstRef2 = const_cast<DataContainer&>(constContainer);
    nonConstRef2.setData(40);  // UNDEFINED BEHAVIOR!
    
    // Why this is undefined behavior:
    // The original object (constContainer) is declared as const.
    // Even though const_cast removes the const qualifier, modifying
    // an object that was originally declared as const is undefined behavior.
    // The compiler may optimize based on the assumption that const objects
    // never change, leading to unpredictable results.
    */
    
    cout << "Dangerous const_cast example commented out (undefined behavior)" << endl;
    
    // Solution for TODO 7: const_cast with pointers
    cout << "\n=== const_cast with Pointers ===" << endl;
    
    int value = 42;
    const int* constPtr = &value;
    
    cout << "Original value: " << *constPtr << endl;
    
    int* nonConstPtr = const_cast<int*>(constPtr);
    *nonConstPtr = 100;
    
    cout << "Modified value: " << *constPtr << endl;
    
    // Solution for TODO 8: const_cast with string literals (dangerous)
    cout << "\n=== const_cast with String Literals (dangerous) ===" << endl;
    
    /*
    // COMMENTED OUT - This would be undefined behavior!
    const char* literal = "Hello";
    char* nonConstLiteral = const_cast<char*>(literal);
    nonConstLiteral[0] = 'h';  // UNDEFINED BEHAVIOR!
    
    // Why this is undefined behavior:
    // String literals are stored in read-only memory.
    // Attempting to modify them leads to undefined behavior,
    // often resulting in a segmentation fault or access violation.
    */
    
    cout << "String literal modification example commented out (undefined behavior)" << endl;
    
    // Solution for TODO 9: Practical use case
    cout << "\n=== Practical Use Case ===" << endl;
    
    DataContainer container2(50);
    cout << "Before calling modifyData: ";
    printData(container2);
    
    modifyData(container2);
    
    cout << "After calling modifyData: ";
    printData(container2);
    
    // Solution for TODO 10: const_cast with char array (safe)
    cout << "\n=== const_cast with char array ===" << endl;
    
    char greeting[] = "hello";
    cout << "Before processing: " << greeting << endl;
    
    processString(greeting);
    
    cout << "After processing: " << greeting << endl;
    
    return 0;
}

// Note: This solution demonstrates both safe and unsafe uses of const_cast
// Key learning points:
// 1. const_cast is safe when the original object is non-const
// 2. Modifying originally const objects is undefined behavior
// 3. String literals should never be modified
// 4. const_cast is useful for interfacing with legacy APIs
// 5. Always ensure the original object can be safely modified 