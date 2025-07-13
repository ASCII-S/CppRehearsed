// Global Variable Sharing Practice - Solution
#include <iostream>
#include <string>

// Solution 1: Define global variables
int counter = 0;
std::string app_name = "MyApp";

// Solution 3: Function to increment counter
void increment_counter() {
    counter++;
}

// Solution 4: Function to display app info
void get_app_info() {
    std::cout << "App: " << app_name << ", Counter: " << counter << std::endl;
}

int main() {
    // Solution 5: Call increment_counter three times
    increment_counter();
    increment_counter();
    increment_counter();
    
    // Solution 6: Display current values
    get_app_info();
    
    return 0;
}

// file2.cpp - Example of using extern
/*
#include <iostream>
#include <string>

// External declarations
extern int counter;
extern std::string app_name;

void reset_counter() {
    counter = 0;
}

void change_app_name(const std::string& new_name) {
    app_name = new_name;
}
*/ 