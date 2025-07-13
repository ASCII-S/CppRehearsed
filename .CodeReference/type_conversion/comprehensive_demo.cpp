#include <iostream>
#include <memory>
#include <vector>
#include <typeinfo>
using namespace std;

// TODO 1: Define a polymorphic base class named Vehicle
// Requirements:
// - Add virtual destructor
// - Add pure virtual function getType() returning string
// - Add virtual function getSpeed() returning int (default 0)
// - Add protected member speed of type int with default value 0

// TODO 2: Define a derived class named Car that inherits from Vehicle
// Requirements:
// - Add private member brand of type string
// - Add constructor taking brand parameter
// - Override getType() to return "Car"
// - Override getSpeed() to return current speed
// - Add unique function getBrand() returning brand
// - Add function accelerate(int) to increase speed

// TODO 3: Define a derived class named Motorcycle that inherits from Vehicle
// Requirements:
// - Add private member engineSize of type int
// - Add constructor taking engineSize parameter
// - Override getType() to return "Motorcycle"
// - Override getSpeed() to return current speed
// - Add unique function getEngineSize() returning engineSize
// - Add function turboBoost() to double the current speed

// TODO 4: Create a function named identifyVehicle
// Requirements:
// - Take a Vehicle* parameter
// - Use dynamic_cast to check if it's a Car, then print brand
// - Use dynamic_cast to check if it's a Motorcycle, then print engine size
// - Handle the case where it's neither

// TODO 5: Create a function named convertSpeed
// Requirements:
// - Take a const int& parameter (speed in km/h)
// - Use const_cast to remove const (simulate legacy API requirement)
// - Use static_cast to convert to double for mph calculation
// - Return speed in mph (divide by 1.60934)

int main() {
    cout << "=== Comprehensive Type Conversion Demo ===" << endl;
    
    // TODO 6: Create vehicle objects using polymorphism
    // Requirements:
    // - Create a Car object with brand "Toyota"
    // - Create a Motorcycle object with engine size 600
    // - Store them in Vehicle* pointers
    // - Set different speeds for each vehicle
    
    cout << "\n=== Creating Vehicles ===" << endl;
    
    // TODO 7: Demonstrate static_cast for safe upcasting
    // Requirements:
    // - Create a Car object on the stack
    // - Use static_cast to convert Car* to Vehicle*
    // - Call getType() through the Vehicle pointer
    
    cout << "\n=== Static Cast Upcasting ===" << endl;
    
    // TODO 8: Demonstrate dynamic_cast for safe downcasting
    // Requirements:
    // - Use dynamic_cast to convert Vehicle* to Car*
    // - Check if conversion succeeded
    // - If successful, call getBrand() and print result
    // - If failed, print appropriate message
    
    cout << "\n=== Dynamic Cast Downcasting ===" << endl;
    
    // TODO 9: Demonstrate the difference between static_cast and dynamic_cast
    // Requirements:
    // - Try to cast a Motorcycle* to Car* using static_cast (comment out - compilation error)
    // - Try to cast a Motorcycle* to Car* using dynamic_cast (should return nullptr)
    // - Print the results and explain the difference
    
    cout << "\n=== Static vs Dynamic Cast Comparison ===" << endl;
    
    // TODO 10: Demonstrate const_cast in a practical scenario
    // Requirements:
    // - Create a const int variable with speed value 100
    // - Call convertSpeed function with it
    // - Print both km/h and mph values
    
    cout << "\n=== Const Cast for Legacy API ===" << endl;
    
    // TODO 11: Demonstrate reinterpret_cast for low-level operations
    // Requirements:
    // - Create a Vehicle pointer
    // - Use reinterpret_cast to convert it to uintptr_t
    // - Print the address value
    // - Add a comment explaining when this might be useful
    
    cout << "\n=== Reinterpret Cast for Address Manipulation ===" << endl;
    
    // TODO 12: Use identifyVehicle function
    // Requirements:
    // - Call identifyVehicle with each vehicle pointer
    // - Observe how dynamic_cast enables runtime type identification
    
    cout << "\n=== Vehicle Identification ===" << endl;
    
    // TODO 13: Demonstrate type_info with typeid
    // Requirements:
    // - Use typeid() to get type information for each vehicle
    // - Print the type names
    // - Compare with the results from dynamic_cast
    
    cout << "\n=== Type Information ===" << endl;
    
    // TODO 14: Clean up resources
    // Requirements:
    // - Delete dynamically allocated objects
    // - Print a message indicating cleanup is complete
    
    cout << "\n=== Cleanup ===" << endl;
    
    return 0;
}

// Note: This comprehensive exercise should take approximately 15-20 minutes to complete
// Focus on understanding when to use each type of cast and their relative safety
// Pay attention to the differences between compile-time and runtime type checking 