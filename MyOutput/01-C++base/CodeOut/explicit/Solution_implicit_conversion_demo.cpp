/**
 * File: Solution_implicit_conversion_demo.cpp
 * Purpose: Complete solution for implicit conversion demonstration
 */

#include <iostream>
#include <string>
using namespace std;

// Solution for TODO 1: Money class
class Money {
private:
    double amount;
    
public:
    Money(double value) : amount(value) {
        cout << "Money constructor called with value: " << value << endl;
    }
    
    double getAmount() const {
        return amount;
    }
    
    void show() const {
        cout << "Money: $" << amount << endl;
    }
};

// Solution for TODO 2: StringWrapper class  
class StringWrapper {
private:
    string data;
    
public:
    StringWrapper(const string& value) : data(value) {
        cout << "StringWrapper constructor called with: " << value << endl;
    }
    
    string getData() const {
        return data;
    }
    
    void print() const {
        cout << data << endl;
    }
};

// Solution for TODO 3: Test functions
void processPayment(Money m) {
    cout << "Processing payment: " << m.getAmount() << endl;
}

void handleText(StringWrapper sw) {
    cout << "Handling: " << sw.getData() << endl;
}

// Solution for TODO 4: Main function with tests
int main() {
    cout << "=== Implicit Conversion Demo ===" << endl;
    
    // Test case 1: double to Money conversion
    cout << "\n1. Calling processPayment(100.5):" << endl;
    processPayment(100.5); // double -> Money implicit conversion
    
    // Test case 2: int to double to Money conversion  
    cout << "\n2. Calling processPayment(50):" << endl;
    processPayment(50); // int -> double -> Money implicit conversion
    
    // Test case 3: const char* to string to StringWrapper conversion
    cout << "\n3. Calling handleText(\"Hello World\"):" << endl;
    handleText("Hello World"); // const char* -> string -> StringWrapper
    
    // Test case 4: Copy initialization with implicit conversion
    cout << "\n4. Creating Money m1 = 25.99:" << endl;
    Money m1 = 25.99; // Copy initialization with implicit conversion
    m1.show();
    
    // Test case 5: Copy initialization with string
    cout << "\n5. Creating StringWrapper sw1 = \"Test\":" << endl;
    StringWrapper sw1 = "Test"; // Copy initialization 
    sw1.print();
    
    cout << "\nNote: All above calls worked due to implicit conversions!" << endl;
    cout << "This might not always be what we want..." << endl;
    cout << "\nObservations:" << endl;
    cout << "- Constructors were called automatically for type conversion" << endl;
    cout << "- No explicit casting was needed" << endl;
    cout << "- This can lead to unexpected behavior in complex codebases" << endl;
    
    return 0;
} 