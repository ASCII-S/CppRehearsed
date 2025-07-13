/**
 * File: implicit_conversion_demo.cpp
 * Purpose: Demonstrate the problems of implicit conversion in C++
 * Time estimate: 8 minutes
 * 
 * Learning objectives:
 * 1. Understand how implicit conversion works with single-parameter constructors
 * 2. Identify potential problems caused by implicit conversion
 * 3. See compilation and runtime behavior differences
 */

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename T>
void printType(T value){
    std::cout << "Type: " << typeid(T).name() << std::endl;
}



// TODO 1: Create a Money class (2 minutes)
// - Add a private member: double amount
// - Add a single-parameter constructor that takes double value
// - Add a getter method: getAmount() that returns amount
// - Add a display method: show() that prints "Money: $" + amount

class Money {
    // TODO: Implement Money class here
    double amout;
public:
    Money(double value) : amout(value){}

    double getAmount(){
        return amout;
    }

    void show(){
        std::cout << "Money: $" << amout << std::endl;
    }
};

// TODO 2: Create a String wrapper class (2 minutes)  
// - Add a private member: string data
// - Add a single-parameter constructor that takes const string& value
// - Add a getter method: getData() that returns data
// - Add a print method: print() that outputs data

class StringWrapper {
    // TODO: Implement StringWrapper class here
    string data;
public:
    StringWrapper(const string& value) : data(value){
        cout << "StringWrapper(const string& value)" << endl;
    }
    StringWrapper(const char* value) : data(value){}

    string getData(){
        return data;
    }

    void print(){
        std::cout << "output of StringWrapper: " << data << std::endl;
    }
};

// TODO 3: Create test functions (1 minute)
// Create these two functions:
// void processPayment(Money m) - prints "Processing payment: " + m.getAmount()
// void handleText(StringWrapper sw) - prints "Handling: " + sw.getData()

// TODO: Implement functions here
void processPayment(Money m){
    std::cout << "money: " << m.getAmount() << std::endl;
    printType(m);
}
void handleText(StringWrapper sw){
    std::cout << "Handling: " << sw.getData() << std::endl;
    printType(sw);
}


// TODO 4: Test implicit conversions in main (3 minutes)
// In main function, test these scenarios:
// 1. Call processPayment(100.5) - should work due to implicit conversion
// 2. Call processPayment(50) - should work, int to double to Money  
// 3. Call handleText("Hello World") - should not work, you wish const char* to string to StringWrapper, but only one implicit conversion is allowed in C++
// 4. Create Money m1 = 25.99; - should work due to copy initialization
// 5. Create StringWrapper sw1 = "Test"; - should work
// 
// Add comments explaining what conversions happen at each step
// Print messages to show the program flow

int main() {
    cout << "=== Implicit Conversion Demo ===" << endl;
    // TODO: Add test cases here
    processPayment(50);          // 调用链支持对标准类型进行隐式转换
    processPayment(100.5);
    string s = "Hello World";
    printType(s);
    printType("Hello World");
    handleText("Hello World");  // 调用链中只允许一次用户定义的隐式转换，因此要使用用const char* 重载构造StringWrapper
    handleText(StringWrapper("Hello World!"));

    
    Money m3 = 25.99;
    StringWrapper sw1 = "Test";
    processPayment(m3);
    handleText(sw1);

    // TODO: Add explanation comments about what conversions occurred
    cout << "\nNote: All above calls worked due to implicit conversions!" << endl;
    cout << "This might not always be what we want..." << endl;
    
    return 0;
}

/* 
Expected output should be:
=== Implicit Conversion Demo ===
Processing payment: 100.5
Processing payment: 50
Handling: Hello World
Processing payment: 25.99
Handling: Test

Note: All above calls worked due to implicit conversions!
This might not always be what we want...
*/ 