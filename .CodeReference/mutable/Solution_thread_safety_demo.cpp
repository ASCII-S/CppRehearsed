#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include <chrono>

// Demonstration of thread safety issues with mutable
class Counter {
private:
    int value_;
    // TODO 1: Add a mutable counter for access tracking
    mutable int access_count_ = 0;
    
public:
    Counter(int initial_value) : value_(initial_value) {}
    
    // TODO 2: Implement get_value() const function
    int get_value() const {
        // Add small delay to increase chance of race condition
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        ++access_count_;
        return value_;
    }
    
    // TODO 3: Add a function to get access count
    int get_access_count() const {
        return access_count_;
    }
    
    // TODO 4: Add a function to reset access count
    void reset_access_count() {
        access_count_ = 0;
    }
};

// Thread-safe version using atomic
class SafeCounter {
private:
    int value_;
    // TODO 5: Add mutable atomic counter for thread-safe access tracking
    mutable std::atomic<int> access_count_{0};
    
public:
    SafeCounter(int initial_value) : value_(initial_value) {}
    
    // TODO 6: Implement thread-safe get_value() const function
    int get_value() const {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        ++access_count_;
        return value_;
    }
    
    // TODO 7: Add thread-safe access count getter
    int get_access_count() const {
        return access_count_.load();
    }
    
    void reset_access_count() {
        access_count_.store(0);
    }
};

// Alternative thread-safe version using mutex
class MutexCounter {
private:
    int value_;
    // TODO 8: Add mutable counter and mutable mutex
    mutable int access_count_ = 0;
    mutable std::mutex mutex_;
    
public:
    MutexCounter(int initial_value) : value_(initial_value) {}
    
    // TODO 9: Implement thread-safe get_value() with mutex
    int get_value() const {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        std::lock_guard<std::mutex> lock(mutex_);
        ++access_count_;
        return value_;
    }
    
    // TODO 10: Add thread-safe access count getter with mutex
    int get_access_count() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return access_count_;
    }
    
    void reset_access_count() {
        std::lock_guard<std::mutex> lock(mutex_);
        access_count_ = 0;
    }
};

// TODO 11: Create a test function for race condition demonstration
void test_race_condition() {
    std::cout << "\n=== Testing Race Condition (Unsafe Counter) ===" << std::endl;
    
    Counter counter(42);
    const int num_threads = 10;
    const int calls_per_thread = 1000;
    const int expected_total = num_threads * calls_per_thread;
    
    std::vector<std::thread> threads;
    
    // Launch threads
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([&counter, calls_per_thread]() {
            for (int j = 0; j < calls_per_thread; ++j) {
                counter.get_value();
            }
        });
    }
    
    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }
    
    int actual_count = counter.get_access_count();
    std::cout << "Expected access count: " << expected_total << std::endl;
    std::cout << "Actual access count: " << actual_count << std::endl;
    std::cout << "Lost updates: " << (expected_total - actual_count) << std::endl;
    
    if (actual_count != expected_total) {
        std::cout << "⚠️  Race condition detected! Some updates were lost." << std::endl;
    } else {
        std::cout << "✅ No race condition detected (lucky run)." << std::endl;
    }
}

// TODO 12: Create a test function for atomic solution
void test_atomic_solution() {
    std::cout << "\n=== Testing Atomic Solution (Safe Counter) ===" << std::endl;
    
    SafeCounter counter(42);
    const int num_threads = 10;
    const int calls_per_thread = 1000;
    const int expected_total = num_threads * calls_per_thread;
    
    std::vector<std::thread> threads;
    
    // Launch threads
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([&counter, calls_per_thread]() {
            for (int j = 0; j < calls_per_thread; ++j) {
                counter.get_value();
            }
        });
    }
    
    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }
    
    int actual_count = counter.get_access_count();
    std::cout << "Expected access count: " << expected_total << std::endl;
    std::cout << "Actual access count: " << actual_count << std::endl;
    
    if (actual_count == expected_total) {
        std::cout << "✅ Atomic operations work correctly! No lost updates." << std::endl;
    } else {
        std::cout << "❌ Unexpected: atomic operations failed." << std::endl;
    }
}

// TODO 13: Create a test function for mutex solution
void test_mutex_solution() {
    std::cout << "\n=== Testing Mutex Solution (Mutex Counter) ===" << std::endl;
    
    MutexCounter counter(42);
    const int num_threads = 10;
    const int calls_per_thread = 1000;
    const int expected_total = num_threads * calls_per_thread;
    
    std::vector<std::thread> threads;
    
    // Launch threads
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([&counter, calls_per_thread]() {
            for (int j = 0; j < calls_per_thread; ++j) {
                counter.get_value();
            }
        });
    }
    
    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }
    
    int actual_count = counter.get_access_count();
    std::cout << "Expected access count: " << expected_total << std::endl;
    std::cout << "Actual access count: " << actual_count << std::endl;
    
    if (actual_count == expected_total) {
        std::cout << "✅ Mutex protection works correctly! No lost updates." << std::endl;
    } else {
        std::cout << "❌ Unexpected: mutex protection failed." << std::endl;
    }
}

int main() {
    std::cout << "=== Thread Safety Demo ===" << std::endl;
    
    // TODO 14: Call all test functions
    test_race_condition();
    test_atomic_solution();
    test_mutex_solution();
    
    // TODO 15: Compare results and explain the differences
    std::cout << "\n=== Summary ===" << std::endl;
    std::cout << "This demo shows how mutable can break thread safety assumptions:" << std::endl;
    std::cout << "1. Regular mutable members can cause race conditions" << std::endl;
    std::cout << "2. std::atomic provides lock-free thread safety" << std::endl;
    std::cout << "3. std::mutex provides traditional lock-based thread safety" << std::endl;
    std::cout << "4. Both atomic and mutex solutions prevent lost updates" << std::endl;
    
    std::cout << "\nKey takeaway: Always consider thread safety when using mutable!" << std::endl;
    
    return 0;
} 