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
    // Use regular int first to see the race condition
    // Later we'll fix it with atomic or mutex
    mutable int counter = 0;
    
public:
    Counter(int initial_value) : value_(initial_value) {}
    
    // TODO 2: Implement get_value() const function
    // Requirements:
    // - Function should be const
    // - Increment the access counter each time it's called
    // - Return the value_
    // - Add a small delay to increase chance of race condition
    int get_value() const {
        // TODO: Implement with mutable counter increment
        counter++;
        return value_;
    }
    
    // TODO 3: Add a function to get access count
    // Function name: get_access_count
    // Return type: int
    // Should be const function
    int get_access_count() const {
        return counter;
    }
    
    // TODO 4: Add a function to reset access count
    // Function name: reset_access_count
    void reset_access_count(){
        counter = 0;
    }
    
};

// Thread-safe version using atomic
class SafeCounter {
private:
    int value_;
    // TODO 5: Add mutable atomic counter for thread-safe access tracking
    // Use std::atomic<int> instead of regular int
    mutable std::atomic<int> acounter{0};
public:
    SafeCounter(int initial_value) : value_(initial_value) {}
    
    // TODO 6: Implement thread-safe get_value() const function
    // Same as above but using atomic operations
    int get_value() const {
        // TODO: Implement with atomic counter increment
        ++acounter;
        return value_;
    }
    
    // TODO 7: Add thread-safe access count getter
    int get_access_count() const {
        // TODO: Return atomic counter value
        return acounter.load();
        // return 0;
    }
    
    void reset_access_count() {
        // TODO: Reset atomic counter
        acounter.store(0);
    }
};

// Alternative thread-safe version using mutex
class MutexCounter {
private:
    int value_;
    // TODO 8: Add mutable counter and mutable mutex
    // Use mutable std::mutex for synchronization
    mutable int mcounter = 0;
    mutable std::mutex mutex_;
    
public:
    MutexCounter(int initial_value) : value_(initial_value) {}
    
    // TODO 9: Implement thread-safe get_value() with mutex
    int get_value() const {
        // TODO: Use lock_guard to protect counter increment
        std::lock_guard<std::mutex> lock(mutex_);
        mcounter++;
        return value_;
    }
    
    // TODO 10: Add thread-safe access count getter with mutex
    int get_access_count() const {
        // TODO: Use lock_guard to protect counter read
        std::lock_guard<std::mutex> lock(mutex_);
        return mcounter;
        // return 0;
    }
    
    void reset_access_count() {
        // TODO: Use lock_guard to protect counter reset
        std::lock_guard<std::mutex> lock(mutex_);
        mcounter=0;
    }
};

// TODO 11: Create a test function for race condition demonstration
// Function name: test_race_condition
// Requirements:
// - Create a Counter object
// - Launch multiple threads (e.g., 10 threads)
// - Each thread calls get_value() multiple times (e.g., 1000 times)
// - Join all threads
// - Check if access count matches expected value
// - Show that race condition causes incorrect count
void test_race_condition() {
    // TODO: Implement race condition test
    std::cout << "=== Test Race Condition ===" << std::endl;
    Counter c(10);
    int num_threads = 10;
    int call_per_thread = 999;
    int expect_total_call = num_threads * call_per_thread;

    std::vector<std::thread> threads;
    for (int i=0; i< num_threads; i++){
        threads.emplace_back([&c,call_per_thread](){
            for(int i=0; i<call_per_thread; i++)
                c.get_value();
        });
    }

    for(auto &t : threads){
        t.join();
    }

    int actual_count = c.get_access_count();
    std::cout << "Expected access count: " << expect_total_call << std::endl;
    std::cout << "Actual access count: " << actual_count << std::endl;
    std::cout << "Lost updates: " << (expect_total_call - actual_count) << std::endl;

    if (actual_count != expect_total_call) {
        std::cout << "⚠️  Race condition detected! Some updates were lost." << std::endl;
    } else {
        std::cout << "✅ No race condition detected (lucky run)." << std::endl;
    }
}

// TODO 12: Create a test function for atomic solution
// Function name: test_atomic_solution
// Requirements:
// - Similar to test_race_condition but using SafeCounter
// - Show that atomic operations solve the race condition
void test_atomic_solution() {
    // TODO: Implement atomic solution test
    std::cout << "=== Test Atomic Solution ===" << std::endl;
    SafeCounter c(10);
    int num_threads = 10;
    int call_per_thread = 999;
    int expect_total_call = num_threads * call_per_thread;

    std::vector<std::thread> threads;
    for (int i=0; i< num_threads; i++){
        threads.emplace_back([&c,call_per_thread](){
            for(int i=0; i<call_per_thread; i++)
                c.get_value();
        });
    }

    for(auto &t : threads){
        t.join();
    }

    int actual_count = c.get_access_count();
    std::cout << "Expected access count: " << expect_total_call << std::endl;
    std::cout << "Actual access count: " << actual_count << std::endl;
    std::cout << "Lost updates: " << (expect_total_call - actual_count) << std::endl;

    if (actual_count != expect_total_call) {
        std::cout << "⚠️  Race condition detected! Some updates were lost." << std::endl;
    } else {
        std::cout << "✅ No race condition detected (lucky run)." << std::endl;
    }
}

// TODO 13: Create a test function for mutex solution
// Function name: test_mutex_solution
// Requirements:
// - Similar to above but using MutexCounter
// - Show that mutex also solves the race condition
void test_mutex_solution() {
    // TODO: Implement mutex solution test
    std::cout << "=== Test Mutex Solution ===" << std::endl;
    MutexCounter c(10);
    int num_threads = 10;
    int call_per_thread = 99999;
    int expect_total_call = num_threads * call_per_thread;

    std::vector<std::thread> threads;
    for (int i=0; i< num_threads; i++){
        threads.emplace_back([&c,call_per_thread](){
            for(int i=0; i<call_per_thread; i++)
                c.get_value();
        });
    }

    for(auto &t : threads){
        t.join();
    }

    int actual_count = c.get_access_count();
    std::cout << "Expected access count: " << expect_total_call << std::endl;
    std::cout << "Actual access count: " << actual_count << std::endl;
    std::cout << "Lost updates: " << (expect_total_call - actual_count) << std::endl;

    if (actual_count != expect_total_call) {
        std::cout << "⚠️  Race condition detected! Some updates were lost." << std::endl;
    } else {
        std::cout << "✅ No race condition detected (lucky run)." << std::endl;
    }    
}

int main() {
    std::cout << "=== Thread Safety Demo ===" << std::endl;
    
    // TODO 14: Call all test functions
    // - test_race_condition()
    // - test_atomic_solution()
    // - test_mutex_solution()
    auto start_time_race = std::chrono::high_resolution_clock::now();
    test_race_condition();
    auto end_time_race = std::chrono::high_resolution_clock::now();
    double duration_race = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_race - start_time_race).count();
    
    auto start_time_atomic = std::chrono::high_resolution_clock::now();
    test_atomic_solution();
    auto end_time_atomic = std::chrono::high_resolution_clock::now();
    double duration_atomic = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_atomic - start_time_atomic).count();
    
    auto start_time_mutex = std::chrono::high_resolution_clock::now();
    test_mutex_solution();
    auto end_time_mutex = std::chrono::high_resolution_clock::now();
    double duration_mutex = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_mutex - start_time_mutex).count();

    std::cout << "Race condition duration: " << duration_race << "ns" << std::endl;
    std::cout << "Atomic solution duration: " << duration_atomic << "ns" << std::endl;
    std::cout << "Mutex solution duration: " << duration_mutex << "ns" << std::endl;

    // TODO 15: Compare results and explain the differences
    // Show how mutable can break thread safety assumptions
    
    return 0;
} 