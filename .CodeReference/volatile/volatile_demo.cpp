/**
 * Volatile Keyword Demonstration - Practice File
 *
 * This file contains 4 exercises to help you understand the volatile keyword.
 * Complete each exercise following the TODO comments.
 * Estimated time: 30 minutes
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

// ====================================================================
// Exercise 1: Compiler Optimization Demonstration
// ====================================================================

/**
 * TODO: Create two versions of a function that reads a variable in a loop
 * 1. One with volatile variable
 * 2. One with regular variable
 *
 * Observe the difference when compiled with optimization (-O2)
 */

// TODO: Implement function with regular variable
void test_without_volatile()
{
    // HINT: Create an integer variable, modify it via pointer, then read in loop

    // Your code here...
}

// TODO: Implement function with volatile variable
void test_with_volatile()
{
    // HINT: Same as above but use volatile keyword

    // Your code here...
}

// ====================================================================
// Exercise 2: Multi-threading Flag Control
// ====================================================================

/**
 * TODO: Create a multi-threading scenario with a stop flag
 * 1. Use volatile bool flag to control thread execution
 * 2. Main thread sets flag after some time
 * 3. Worker thread checks flag and exits when set
 */

// TODO: Declare your flag variable here
// HINT: Should this be volatile? Why?

void worker_thread()
{
    // TODO: Implement worker thread logic
    // HINT: Loop while flag is not set, do some work in each iteration

    // Your code here...
}

void test_threading_flag()
{
    // TODO: Start worker thread, wait some time, then set flag

    // Your code here...
}

// ====================================================================
// Exercise 3: Hardware Register Simulation
// ====================================================================

/**
 * TODO: Simulate hardware register access
 * Create a scenario where:
 * 1. A "register" value changes externally (simulate with another thread)
 * 2. Main thread polls the register until specific value is reached
 * 3. Compare behavior with and without volatile
 */

// TODO: Declare simulated hardware register
// HINT: What type modifier should you use for hardware registers?

void simulate_hardware_change()
{
    // TODO: Simulate external hardware changing the register value
    // HINT: Sleep for a while, then change the register value

    // Your code here...
}

void test_hardware_register()
{
    // TODO: Start simulation thread and poll register until it changes

    // Your code here...
}

// ====================================================================
// Exercise 4: Volatile vs Atomic Comparison
// ====================================================================

/**
 * TODO: Compare volatile and atomic in multi-threading scenario
 * 1. Create a counter with volatile
 * 2. Create a counter with std::atomic
 * 3. Multiple threads increment both counters
 * 4. Compare final results to see race conditions
 */

// TODO: Declare both counters
// volatile int volatile_counter = 0;
// std::atomic<int> atomic_counter{0};

void increment_counters(int iterations)
{
    // TODO: Increment both counters in a loop
    // HINT: Notice that volatile doesn't guarantee atomicity

    // Your code here...
}

void test_volatile_vs_atomic()
{
    // TODO: Create multiple threads that increment counters
    // HINT: Use std::thread and join them

    // Your code here...
}

// ====================================================================
// Main Function - Test Runner
// ====================================================================

int main()
{
    std::cout << "=== Volatile Keyword Demonstration ===" << std::endl;

    // TODO: Uncomment and test each exercise

    std::cout << "\n1. Testing Compiler Optimization:" << std::endl;
    // test_without_volatile();
    // test_with_volatile();

    std::cout << "\n2. Testing Multi-threading Flag:" << std::endl;
    // test_threading_flag();

    std::cout << "\n3. Testing Hardware Register Simulation:" << std::endl;
    // test_hardware_register();

    std::cout << "\n4. Testing Volatile vs Atomic:" << std::endl;
    // test_volatile_vs_atomic();

    return 0;
}

/**
 * COMPILATION HINTS:
 *
 * To see compiler optimization effects:
 * g++ -O0 volatile_demo.cpp -o demo_no_opt
 * g++ -O2 volatile_demo.cpp -o demo_opt
 *
 * For threading examples:
 * g++ -pthread volatile_demo.cpp -o demo
 *
 * LEARNING OBJECTIVES:
 * 1. Understand when volatile is necessary
 * 2. See compiler optimization behavior
 * 3. Learn volatile limitations (no atomicity)
 * 4. Compare with modern alternatives (atomic)
 */