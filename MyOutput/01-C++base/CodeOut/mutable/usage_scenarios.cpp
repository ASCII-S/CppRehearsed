#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include <mutex>

// Scenario 1: Lazy Initialization
class DatabaseConnection {
private:
    std::string connection_string_;
    // TODO 1: Add mutable connection pointer for lazy initialization
    // Use std::unique_ptr<std::string> to simulate actual connection
    
public:
    DatabaseConnection(const std::string& conn_str) : connection_string_(conn_str) {}
    
    // TODO 2: Implement get_connection() const function
    // Requirements:
    // - Function should be const
    // - Initialize connection only when first called (lazy initialization)
    // - Return reference to connection
    // - Use mutable member to store the connection
    const std::string& get_connection() const {
        // TODO: Implement lazy initialization
        
        static std::string dummy = "dummy"; // Replace this
        return dummy;
    }
    
    // TODO 3: Add a function to check if connection is initialized
    // Function name: is_connected
    // Return type: bool
    // Should be const function
    
};

// Scenario 2: Debug and Logging
class Calculator {
private:
    double result_;
    // TODO 4: Add mutable variables for debugging/logging
    // - call_count_: number of times calculate() is called
    // - last_operation_: string describing last operation
    // - debug_enabled_: boolean to enable/disable debug output
    
public:
    Calculator() : result_(0.0) {}
    
    // TODO 5: Implement calculate() const function with logging
    // Requirements:
    // - Function should be const (logically doesn't change calculator state)
    // - Increment call count
    // - Store operation description
    // - Print debug info if debug is enabled
    // - Return some calculated result
    double calculate(double a, double b, const std::string& operation) const {
        // TODO: Implement calculation with logging
        
        return a + b; // Replace with proper implementation
    }
    
    // TODO 6: Add debug control functions
    // - enable_debug(): enable debug output
    // - disable_debug(): disable debug output
    // - get_call_count(): return number of calls
    // - get_last_operation(): return last operation string
    // All should be const functions
    
};

// Scenario 3: Iterator State
class NumberContainer {
private:
    std::vector<int> numbers_;
    // TODO 7: Add mutable iterator state
    // - current_index_: current position for iteration
    // - iteration_count_: number of iterations performed
    
public:
    NumberContainer(std::initializer_list<int> nums) : numbers_(nums) {}
    
    // TODO 8: Implement get_next() const function
    // Requirements:
    // - Function should be const
    // - Return next number in sequence
    // - Update internal iterator state
    // - Wrap around to beginning when reaching end
    // - Increment iteration count
    int get_next() const {
        // TODO: Implement iterator logic
        
        return 0; // Replace this
    }
    
    // TODO 9: Add iterator status functions
    // - get_current_index(): return current index
    // - get_iteration_count(): return total iterations
    // - reset_iterator(): reset to beginning
    // All should be const functions
    
};

// Scenario 4: Caching with Mutex (Thread-Safe)
class ExpensiveCalculator {
private:
    int base_value_;
    // TODO 10: Add mutable cache and mutex
    // - cache_: optional cached result
    // - cache_mutex_: mutex for thread-safe caching
    // - computation_count_: number of times computation was performed
    
public:
    ExpensiveCalculator(int base) : base_value_(base) {}
    
    // TODO 11: Implement compute() const function with thread-safe caching
    // Requirements:
    // - Function should be const
    // - Use mutex to protect cache access
    // - Simulate expensive computation (sleep 100ms)
    // - Cache result for future calls
    // - Track computation count
    double compute() const {
        // TODO: Implement thread-safe caching
        
        return 0.0; // Replace this
    }
    
    // TODO 12: Add cache management functions
    // - clear_cache(): clear cached result
    // - get_computation_count(): return number of actual computations
    // - is_cached(): check if result is cached
    // All should be const functions with proper mutex protection
    
};

// TODO 13: Create test functions for each scenario

// Test function for lazy initialization
void test_lazy_initialization() {
    std::cout << "\n=== Testing Lazy Initialization ===" << std::endl;
    // TODO: Create DatabaseConnection and test lazy initialization
    
}

// Test function for debug and logging
void test_debug_logging() {
    std::cout << "\n=== Testing Debug and Logging ===" << std::endl;
    // TODO: Create Calculator and test debug/logging features
    
}

// Test function for iterator state
void test_iterator_state() {
    std::cout << "\n=== Testing Iterator State ===" << std::endl;
    // TODO: Create NumberContainer and test iteration features
    
}

// Test function for thread-safe caching
void test_thread_safe_caching() {
    std::cout << "\n=== Testing Thread-Safe Caching ===" << std::endl;
    // TODO: Create ExpensiveCalculator and test with multiple threads
    
}

int main() {
    std::cout << "=== Mutable Usage Scenarios Demo ===" << std::endl;
    
    // TODO 14: Call all test functions
    // - test_lazy_initialization()
    // - test_debug_logging()
    // - test_iterator_state()
    // - test_thread_safe_caching()
    
    // TODO 15: Additional demonstrations
    // Show how mutable enables these patterns while maintaining const correctness
    
    return 0;
} 