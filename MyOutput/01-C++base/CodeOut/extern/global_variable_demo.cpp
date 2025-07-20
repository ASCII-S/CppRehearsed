// Global Variable Sharing Practice
// Time: 3 minutes

#include <iostream>

// TODO 1: Define a global integer variable named 'counter' and initialize it to 0
int counter = 0;

// TODO 2: Define a global string variable named 'app_name' and initialize it to "MyApp"
std::string app_name = "MyApp";

// TODO 3: Create a function named 'increment_counter' that increases counter by 1
void increment_counter(){
    counter++;
}

// TODO 4: Create a function named 'get_app_info' that prints both counter and app_name
void get_app_info(){
    std::cout << "counter: " << counter << " app_name: " << app_name << std::endl;
}

// int main() {
//     // TODO 5: Call increment_counter() three times
//     increment_counter();
//     increment_counter();
//     increment_counter();

//     // TODO 6: Call get_app_info() to display current values
//     get_app_info();
    
//     return 0;
// }

// Create another file (file2.cpp) and try to access these variables using extern
// Instructions:
// - Declare the variables using extern
// - Create functions to modify them
// - Test the sharing behavior 
// - use `g++ -o extern_demo global_variable_demo.cpp file2.cpp` to compile and run