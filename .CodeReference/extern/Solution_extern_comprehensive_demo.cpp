// Extern Comprehensive Practice - Solution
#include <iostream>
#include <string>

// Solution 1: Declare external constant string
extern const std::string VERSION;

// Solution 2: Declare external bool variable
extern bool debug_mode;

// Solution 3: Declare external variable in namespace
namespace Config {
    extern int max_connections;
}

// Solution 4: Function declaration with explicit extern
extern void print_config_info();

// Solution 5: Function implementation
void print_config_info() {
    std::cout << "=== Configuration Info ===" << std::endl;
    std::cout << "Version: " << VERSION << std::endl;
    std::cout << "Debug Mode: " << (debug_mode ? "ON" : "OFF") << std::endl;
    std::cout << "Max Connections: " << Config::max_connections << std::endl;
    std::cout << "=========================" << std::endl;
}

// Definitions (normally in separate .cpp files)
const std::string VERSION = "1.0.0";
bool debug_mode = true;

namespace Config {
    int max_connections = 100;
}

int main() {
    // Solution 6: Use external variables and call function
    std::cout << "Initial state:" << std::endl;
    print_config_info();
    
    // Solution 7: Modify variables and print again
    debug_mode = false;
    Config::max_connections = 200;
    
    std::cout << "\nAfter modifications:" << std::endl;
    print_config_info();
    
    return 0;
} 