#include <iostream>
#include <memory>
#include <vector>
#include <typeinfo>
#include <string>
using namespace std;

// Solution for TODO 1: Define a polymorphic base class named Vehicle
class Vehicle {
protected:
    int speed = 0;
    
public:
    virtual ~Vehicle() = default;
    
    virtual string getType() = 0;
    
    virtual int getSpeed() {
        return speed;
    }
};

// Solution for TODO 2: Define a derived class named Car
class Car : public Vehicle {
private:
    string brand;
    
public:
    Car(const string& b) : brand(b) {}
    
    string getType() override {
        return "Car";
    }
    
    int getSpeed() override {
        return speed;
    }
    
    string getBrand() {
        return brand;
    }
    
    void accelerate(int increase) {
        speed += increase;
    }
};

// Solution for TODO 3: Define a derived class named Motorcycle
class Motorcycle : public Vehicle {
private:
    int engineSize;
    
public:
    Motorcycle(int engine) : engineSize(engine) {}
    
    string getType() override {
        return "Motorcycle";
    }
    
    int getSpeed() override {
        return speed;
    }
    
    int getEngineSize() {
        return engineSize;
    }
    
    void turboBoost() {
        speed *= 2;
    }
};

// Solution for TODO 4: Create a function named identifyVehicle
void identifyVehicle(Vehicle* vehicle) {
    cout << "Identifying vehicle type: " << vehicle->getType() << endl;
    
    // Try to cast to Car
    Car* car = dynamic_cast<Car*>(vehicle);
    if (car) {
        cout << "It's a Car with brand: " << car->getBrand() << endl;
        return;
    }
    
    // Try to cast to Motorcycle
    Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(vehicle);
    if (motorcycle) {
        cout << "It's a Motorcycle with engine size: " << motorcycle->getEngineSize() << "cc" << endl;
        return;
    }
    
    cout << "Unknown vehicle type" << endl;
}

// Solution for TODO 5: Create a function named convertSpeed
double convertSpeed(const int& kmh) {
    // Simulate legacy API that requires non-const reference
    int& nonConstKmh = const_cast<int&>(kmh);
    
    // Convert to double for calculation
    double kmhDouble = static_cast<double>(nonConstKmh);
    
    // Convert km/h to mph
    return kmhDouble / 1.60934;
}

int main() {
    cout << "=== Comprehensive Type Conversion Demo ===" << endl;
    
    // Solution for TODO 6: Create vehicle objects using polymorphism
    cout << "\n=== Creating Vehicles ===" << endl;
    
    Vehicle* carPtr = new Car("Toyota");
    Vehicle* motorcyclePtr = new Motorcycle(600);
    
    // Set different speeds
    static_cast<Car*>(carPtr)->accelerate(80);
    static_cast<Motorcycle*>(motorcyclePtr)->turboBoost();  // Starts from 0, so remains 0
    
    // Let's give the motorcycle some initial speed
    static_cast<Motorcycle*>(motorcyclePtr)->accelerate(50);
    static_cast<Motorcycle*>(motorcyclePtr)->turboBoost();  // Now doubles to 100
    
    cout << "Car speed: " << carPtr->getSpeed() << " km/h" << endl;
    cout << "Motorcycle speed: " << motorcyclePtr->getSpeed() << " km/h" << endl;
    
    // Solution for TODO 7: Demonstrate static_cast for safe upcasting
    cout << "\n=== Static Cast Upcasting ===" << endl;
    
    Car stackCar("Honda");
    Vehicle* vehiclePtr = static_cast<Vehicle*>(&stackCar);
    
    cout << "Vehicle type through static_cast: " << vehiclePtr->getType() << endl;
    
    // Solution for TODO 8: Demonstrate dynamic_cast for safe downcasting
    cout << "\n=== Dynamic Cast Downcasting ===" << endl;
    
    Car* castedCar = dynamic_cast<Car*>(carPtr);
    if (castedCar) {
        cout << "Successfully cast to Car, brand: " << castedCar->getBrand() << endl;
    } else {
        cout << "Failed to cast to Car" << endl;
    }
    
    // Try to cast motorcycle to car (should fail)
    Car* failedCast = dynamic_cast<Car*>(motorcyclePtr);
    if (failedCast) {
        cout << "Successfully cast Motorcycle to Car" << endl;
    } else {
        cout << "Failed to cast Motorcycle to Car (as expected)" << endl;
    }
    
    // Solution for TODO 9: Demonstrate the difference between static_cast and dynamic_cast
    cout << "\n=== Static vs Dynamic Cast Comparison ===" << endl;
    
    // This would cause compilation error - static_cast requires related types
    // Car* staticCastResult = static_cast<Car*>(motorcyclePtr);  // COMPILATION ERROR
    
    // dynamic_cast safely returns nullptr for incompatible types
    Car* dynamicCastResult = dynamic_cast<Car*>(motorcyclePtr);
    cout << "dynamic_cast result: " << (dynamicCastResult ? "SUCCESS" : "FAILED (nullptr)") << endl;
    
    cout << "Note: static_cast between unrelated types would cause compilation error" << endl;
    
    // Solution for TODO 10: Demonstrate const_cast in a practical scenario
    cout << "\n=== Const Cast for Legacy API ===" << endl;
    
    const int speedKmh = 100;
    double speedMph = convertSpeed(speedKmh);
    
    cout << "Speed in km/h: " << speedKmh << endl;
    cout << "Speed in mph: " << speedMph << endl;
    
    // Solution for TODO 11: Demonstrate reinterpret_cast for low-level operations
    cout << "\n=== Reinterpret Cast for Address Manipulation ===" << endl;
    
    Vehicle* vehicleAddress = carPtr;
    uintptr_t addressValue = reinterpret_cast<uintptr_t>(vehicleAddress);
    
    cout << "Vehicle pointer: " << vehicleAddress << endl;
    cout << "Address as integer: " << addressValue << endl;
    cout << "Address as hex: 0x" << hex << addressValue << dec << endl;
    
    // This might be useful for:
    // 1. Creating hash values from pointers
    // 2. Storing pointers in integer containers
    // 3. Low-level memory debugging
    
    // Solution for TODO 12: Use identifyVehicle function
    cout << "\n=== Vehicle Identification ===" << endl;
    
    identifyVehicle(carPtr);
    identifyVehicle(motorcyclePtr);
    
    // Solution for TODO 13: Demonstrate type_info with typeid
    cout << "\n=== Type Information ===" << endl;
    
    cout << "Car typeid name: " << typeid(*carPtr).name() << endl;
    cout << "Motorcycle typeid name: " << typeid(*motorcyclePtr).name() << endl;
    
    // Compare with dynamic_cast results
    cout << "Car dynamic_cast check: " << (dynamic_cast<Car*>(carPtr) ? "Is Car" : "Not Car") << endl;
    cout << "Motorcycle dynamic_cast check: " << (dynamic_cast<Motorcycle*>(motorcyclePtr) ? "Is Motorcycle" : "Not Motorcycle") << endl;
    
    // Cross-check
    cout << "Car as Motorcycle: " << (dynamic_cast<Motorcycle*>(carPtr) ? "Is Motorcycle" : "Not Motorcycle") << endl;
    cout << "Motorcycle as Car: " << (dynamic_cast<Car*>(motorcyclePtr) ? "Is Car" : "Not Car") << endl;
    
    // Solution for TODO 14: Clean up resources
    cout << "\n=== Cleanup ===" << endl;
    
    delete carPtr;
    delete motorcyclePtr;
    
    cout << "All resources cleaned up successfully" << endl;
    
    return 0;
}

// Note: This comprehensive solution demonstrates all four cast types in practical scenarios
// Key learning points:
// 1. static_cast: Safe for related types and basic conversions
// 2. dynamic_cast: Safe runtime type checking for polymorphic hierarchies
// 3. const_cast: Remove const for legacy API compatibility
// 4. reinterpret_cast: Low-level bit reinterpretation (use with caution)
// 5. typeid: Runtime type identification
// 6. Importance of virtual destructors in polymorphic hierarchies
// 7. When to use each cast type based on safety and requirements 