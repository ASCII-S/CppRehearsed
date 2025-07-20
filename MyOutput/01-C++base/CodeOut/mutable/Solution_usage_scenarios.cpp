#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>
#include <optional>

// Scenario 1: Lazy Initialization
class DatabaseConnection {
private:
    std::string connection_string_;
    // TODO 1: Add mutable connection pointer for lazy initialization
    mutable std::unique_ptr<std::string> connection_;
    
public:
    DatabaseConnection(const std::string& conn_str) : connection_string_(conn_str) {}
    
    // TODO 2: Implement get_connection() const function
    const std::string& get_connection() const {
        if (!connection_) {
            std::cout << "Initializing connection to: " << connection_string_ << std::endl;
            // Simulate connection initialization
            connection_ = std::make_unique<std::string>("Connected to " + connection_string_);
        }
        return *connection_;
    }
    
    // TODO 3: Add a function to check if connection is initialized
    bool is_connected() const {
        return connection_ != nullptr;
    }
};

// Scenario 2: Debug and Logging
class Calculator {
private:
    double result_;
    // TODO 4: Add mutable variables for debugging/logging
    mutable int call_count_ = 0;
    mutable std::string last_operation_;
    mutable bool debug_enabled_ = false;
    
public:
    Calculator() : result_(0.0) {}
    
    // TODO 5: Implement calculate() const function with logging
    double calculate(double a, double b, const std::string& operation) const {
        ++call_count_;
        last_operation_ = operation + "(" + std::to_string(a) + ", " + std::to_string(b) + ")";
        
        if (debug_enabled_) {
            std::cout << "[DEBUG] Call #" << call_count_ << ": " << last_operation_ << std::endl;
        }
        
        double result = 0.0;
        if (operation == "add") {
            result = a + b;
        } else if (operation == "subtract") {
            result = a - b;
        } else if (operation == "multiply") {
            result = a * b;
        } else if (operation == "divide") {
            result = (b != 0) ? a / b : 0.0;
        }
        
        if (debug_enabled_) {
            std::cout << "[DEBUG] Result: " << result << std::endl;
        }
        
        return result;
    }
    
    // TODO 6: Add debug control functions
    void enable_debug() const {
        debug_enabled_ = true;
    }
    
    void disable_debug() const {
        debug_enabled_ = false;
    }
    
    int get_call_count() const {
        return call_count_;
    }
    
    const std::string& get_last_operation() const {
        return last_operation_;
    }
};

// Scenario 3: Iterator State
class NumberContainer {
private:
    std::vector<int> numbers_;
    // TODO 7: Add mutable iterator state
    mutable size_t current_index_ = 0;
    mutable int iteration_count_ = 0;
    
public:
    NumberContainer(std::initializer_list<int> nums) : numbers_(nums) {}
    
    // TODO 8: Implement get_next() const function
    int get_next() const {
        if (numbers_.empty()) {
            return 0;
        }
        
        int value = numbers_[current_index_];
        current_index_ = (current_index_ + 1) % numbers_.size();
        ++iteration_count_;
        
        return value;
    }
    
    // TODO 9: Add iterator status functions
    size_t get_current_index() const {
        return current_index_;
    }
    
    int get_iteration_count() const {
        return iteration_count_;
    }
    
    void reset_iterator() const {
        current_index_ = 0;
        iteration_count_ = 0;
    }
};

// Scenario 4: Caching with Mutex (Thread-Safe)
class ExpensiveCalculator {
private:
    int base_value_;
    // TODO 10: Add mutable cache and mutex
    mutable std::optional<double> cache_;
    mutable std::mutex cache_mutex_;
    mutable int computation_count_ = 0;
    
public:
    ExpensiveCalculator(int base) : base_value_(base) {}
    
    // TODO 11: Implement compute() const function with thread-safe caching
    double compute() const {
        std::lock_guard<std::mutex> lock(cache_mutex_);
        
        if (!cache_.has_value()) {
            std::cout << "Computing expensive operation for base " << base_value_ << "..." << std::endl;
            // Simulate expensive computation
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            
            double result = base_value_ * base_value_ * 3.14159;
            cache_ = result;
            ++computation_count_;
        }
        
        return cache_.value();
    }
    
    // TODO 12: Add cache management functions
    void clear_cache() const {
        std::lock_guard<std::mutex> lock(cache_mutex_);
        cache_.reset();
    }
    
    int get_computation_count() const {
        std::lock_guard<std::mutex> lock(cache_mutex_);
        return computation_count_;
    }
    
    bool is_cached() const {
        std::lock_guard<std::mutex> lock(cache_mutex_);
        return cache_.has_value();
    }
};

// TODO 13: Create test functions for each scenario

// Test function for lazy initialization
void test_lazy_initialization() {
    std::cout << "\n=== Testing Lazy Initialization ===" << std::endl;
    
    DatabaseConnection db("postgresql://localhost:5432/mydb");
    
    std::cout << "Created database connection object" << std::endl;
    std::cout << "Is connected: " << (db.is_connected() ? "Yes" : "No") << std::endl;
    
    std::cout << "\nFirst call to get_connection():" << std::endl;
    const std::string& conn1 = db.get_connection();
    std::cout << "Connection: " << conn1 << std::endl;
    std::cout << "Is connected: " << (db.is_connected() ? "Yes" : "No") << std::endl;
    
    std::cout << "\nSecond call to get_connection() (should not reinitialize):" << std::endl;
    const std::string& conn2 = db.get_connection();
    std::cout << "Connection: " << conn2 << std::endl;
}

// Test function for debug and logging
void test_debug_logging() {
    std::cout << "\n=== Testing Debug and Logging ===" << std::endl;
    
    Calculator calc;
    
    std::cout << "Performing calculations without debug:" << std::endl;
    double result1 = calc.calculate(10, 5, "add");
    double result2 = calc.calculate(20, 4, "divide");
    
    std::cout << "Call count: " << calc.get_call_count() << std::endl;
    std::cout << "Last operation: " << calc.get_last_operation() << std::endl;
    
    std::cout << "\nEnabling debug mode:" << std::endl;
    calc.enable_debug();
    
    double result3 = calc.calculate(8, 3, "multiply");
    double result4 = calc.calculate(15, 7, "subtract");
    
    std::cout << "Total calls: " << calc.get_call_count() << std::endl;
    
    std::cout << "\nDisabling debug mode:" << std::endl;
    calc.disable_debug();
    double result5 = calc.calculate(100, 25, "divide");
    
    std::cout << "Final call count: " << calc.get_call_count() << std::endl;
}

// Test function for iterator state
void test_iterator_state() {
    std::cout << "\n=== Testing Iterator State ===" << std::endl;
    
    NumberContainer container{1, 2, 3, 4, 5};
    
    std::cout << "Container contents: {1, 2, 3, 4, 5}" << std::endl;
    std::cout << "Getting next values (should wrap around):" << std::endl;
    
    for (int i = 0; i < 8; ++i) {
        int value = container.get_next();
        std::cout << "Value: " << value 
                  << ", Index: " << container.get_current_index() 
                  << ", Iteration: " << container.get_iteration_count() << std::endl;
    }
    
    std::cout << "\nResetting iterator:" << std::endl;
    container.reset_iterator();
    std::cout << "After reset - Index: " << container.get_current_index() 
              << ", Iteration count: " << container.get_iteration_count() << std::endl;
    
    std::cout << "Next value: " << container.get_next() << std::endl;
}

// Test function for thread-safe caching
void test_thread_safe_caching() {
    std::cout << "\n=== Testing Thread-Safe Caching ===" << std::endl;
    
    ExpensiveCalculator calc(42);
    
    std::cout << "Initial state:" << std::endl;
    std::cout << "Is cached: " << (calc.is_cached() ? "Yes" : "No") << std::endl;
    std::cout << "Computation count: " << calc.get_computation_count() << std::endl;
    
    // Test single-threaded behavior
    std::cout << "\nSingle-threaded test:" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    double result1 = calc.compute();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "First call result: " << result1 << ", time: " << duration1.count() << "ms" << std::endl;
    std::cout << "Computation count: " << calc.get_computation_count() << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    double result2 = calc.compute();
    end = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Second call result: " << result2 << ", time: " << duration2.count() << "ms" << std::endl;
    std::cout << "Computation count: " << calc.get_computation_count() << std::endl;
    
    // Test multi-threaded behavior
    std::cout << "\nMulti-threaded test:" << std::endl;
    calc.clear_cache();
    
    std::vector<std::thread> threads;
    std::vector<double> results(5);
    
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back([&calc, &results, i]() {
            results[i] = calc.compute();
        });
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "All threads completed" << std::endl;
    std::cout << "Computation count: " << calc.get_computation_count() << std::endl;
    std::cout << "All results should be identical:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread " << i << ": " << results[i] << std::endl;
    }
}

int main() {
    std::cout << "=== Mutable Usage Scenarios Demo ===" << std::endl;
    
    // TODO 14: Call all test functions
    test_lazy_initialization();
    test_debug_logging();
    test_iterator_state();
    test_thread_safe_caching();
    
    // TODO 15: Additional demonstrations
    std::cout << "\n=== Summary ===" << std::endl;
    std::cout << "This demo shows various legitimate uses of mutable:" << std::endl;
    std::cout << "1. Lazy Initialization - defer expensive operations until needed" << std::endl;
    std::cout << "2. Debug/Logging - track information without changing logical state" << std::endl;
    std::cout << "3. Iterator State - maintain position in const traversal" << std::endl;
    std::cout << "4. Thread-Safe Caching - cache results with proper synchronization" << std::endl;
    std::cout << "\nKey principle: mutable should only modify 'logically const' data!" << std::endl;
    
    return 0;
} 