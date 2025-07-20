/**
 * Volatile Keyword Demonstration - Solution File
 *
 * This file contains complete solutions for all 4 volatile exercises.
 * Study these solutions to understand proper volatile usage.
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>

// ====================================================================
// Exercise 1: Compiler Optimization Demonstration
// ====================================================================

void test_without_volatile()
{
    std::cout << "Testing without volatile..." << std::endl;

    int value = 10;
    int *ptr = &value;

    // Simulate external modification (like hardware or another thread)
    std::thread modifier([ptr]()
                         {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        *ptr = 20;
        std::cout << "Value modified to 20 by external thread" << std::endl; });

    // Without volatile, compiler might optimize this loop
    // and cache 'value' in register, missing the external change
    auto start = std::chrono::steady_clock::now();
    while (value == 10)
    {
        // Busy wait - compiler might optimize this away with -O2
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
    auto end = std::chrono::steady_clock::now();

    std::cout << "Loop exited, final value: " << value << std::endl;
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    modifier.join();
}

void test_with_volatile()
{
    std::cout << "Testing with volatile..." << std::endl;

    volatile int value = 10; // volatile ensures fresh read from memory
    int *ptr = const_cast<int *>(&value);

    std::thread modifier([ptr]()
                         {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        *ptr = 20;
        std::cout << "Volatile value modified to 20 by external thread" << std::endl; });

    // With volatile, compiler cannot optimize away memory reads
    auto start = std::chrono::steady_clock::now();
    while (value == 10)
    {
        // Each iteration reads from memory
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
    auto end = std::chrono::steady_clock::now();

    std::cout << "Loop exited, final value: " << value << std::endl;
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    modifier.join();
}

// ====================================================================
// Exercise 2: Multi-threading Flag Control
// ====================================================================

volatile bool stop_flag = false; // volatile needed for visibility across threads

void worker_thread()
{
    std::cout << "Worker thread started..." << std::endl;
    int work_count = 0;

    while (!stop_flag)
    {
        // Simulate work
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        ++work_count;
        std::cout << "Working... (iteration " << work_count << ")" << std::endl;
    }

    std::cout << "Worker thread stopping after " << work_count << " iterations" << std::endl;
}

void test_threading_flag()
{
    std::cout << "Starting threading flag test..." << std::endl;

    // Reset flag
    stop_flag = false;

    // Start worker thread
    std::thread worker(worker_thread);

    // Let it work for a while
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    // Signal stop
    std::cout << "Main thread setting stop flag..." << std::endl;
    stop_flag = true;

    // Wait for worker to finish
    worker.join();
    std::cout << "Threading flag test completed" << std::endl;
}

// ====================================================================
// Exercise 3: Hardware Register Simulation
// ====================================================================

volatile int hardware_register = 0x00; // Simulated hardware register

void simulate_hardware_change()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    // Simulate hardware setting a specific bit pattern
    hardware_register = 0xFF;
    std::cout << "Hardware register changed to 0xFF" << std::endl;
}

void test_hardware_register()
{
    std::cout << "Testing hardware register simulation..." << std::endl;

    // Reset register
    hardware_register = 0x00;

    // Start hardware simulation
    std::thread hw_sim(simulate_hardware_change);

    std::cout << "Polling hardware register until it changes..." << std::endl;

    // Poll register until hardware sets it to 0xFF
    // volatile ensures we always read from actual memory location
    while (hardware_register != 0xFF)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "Register value: 0x" << std::hex << hardware_register << std::dec << std::endl;
    }

    std::cout << "Hardware register reached expected value: 0xFF" << std::endl;

    hw_sim.join();
}

// ====================================================================
// Exercise 4: Volatile vs Atomic Comparison
// ====================================================================

volatile int volatile_counter = 0;  // Not thread-safe for read-modify-write
std::atomic<int> atomic_counter{0}; // Thread-safe atomic operations

void increment_counters(int iterations)
{
    for (int i = 0; i < iterations; ++i)
    {
        // Volatile increment is NOT atomic (read-modify-write race condition)
        volatile_counter++;

        // Atomic increment IS atomic
        atomic_counter++;
    }
}

void test_volatile_vs_atomic()
{
    std::cout << "Testing volatile vs atomic with multiple threads..." << std::endl;

    // Reset counters
    volatile_counter = 0;
    atomic_counter = 0;

    const int num_threads = 4;
    const int iterations_per_thread = 1000;
    const int expected_total = num_threads * iterations_per_thread;

    std::vector<std::thread> threads;

    // Start multiple threads incrementing both counters
    for (int i = 0; i < num_threads; ++i)
    {
        threads.emplace_back(increment_counters, iterations_per_thread);
    }

    // Wait for all threads to complete
    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << "\nResults after " << num_threads << " threads x "
              << iterations_per_thread << " iterations:" << std::endl;
    std::cout << "Expected total: " << expected_total << std::endl;
    std::cout << "Volatile counter: " << volatile_counter
              << " (likely less due to race conditions)" << std::endl;
    std::cout << "Atomic counter: " << atomic_counter.load()
              << " (should equal expected)" << std::endl;

    if (volatile_counter < expected_total)
    {
        std::cout << "❌ Volatile lost " << (expected_total - volatile_counter)
                  << " increments due to race conditions!" << std::endl;
    }

    if (atomic_counter.load() == expected_total)
    {
        std::cout << "✅ Atomic counter maintained consistency!" << std::endl;
    }
}

// ====================================================================
// Main Function - Solution Runner
// ====================================================================

int main()
{
    std::cout << "=== Volatile Keyword Demonstration - Solutions ===" << std::endl;

    std::cout << "\n1. Compiler Optimization Test:" << std::endl;
    std::cout << "Note: Differences more visible with -O2 optimization" << std::endl;
    test_without_volatile();
    std::cout << std::endl;
    test_with_volatile();

    std::cout << "\n"
              << std::string(50, '=') << std::endl;
    std::cout << "\n2. Multi-threading Flag Test:" << std::endl;
    test_threading_flag();

    std::cout << "\n"
              << std::string(50, '=') << std::endl;
    std::cout << "\n3. Hardware Register Simulation:" << std::endl;
    test_hardware_register();

    std::cout << "\n"
              << std::string(50, '=') << std::endl;
    std::cout << "\n4. Volatile vs Atomic Comparison:" << std::endl;
    test_volatile_vs_atomic();

    std::cout << "\n"
              << std::string(50, '=') << std::endl;
    std::cout << "\n=== Key Takeaways ===" << std::endl;
    std::cout << "1. volatile prevents compiler optimizations that cache variables" << std::endl;
    std::cout << "2. volatile is essential for hardware register access" << std::endl;
    std::cout << "3. volatile does NOT guarantee atomic operations" << std::endl;
    std::cout << "4. For thread safety, use std::atomic or synchronization primitives" << std::endl;
    std::cout << "5. volatile is about visibility, not atomicity" << std::endl;

    return 0;
}

/**
 * COMPILATION AND TESTING:
 *
 * Basic compilation:
 * g++ -std=c++11 -pthread volatile_demo_solution.cpp -o solution
 *
 * Test compiler optimization differences:
 * g++ -std=c++11 -pthread -O0 volatile_demo_solution.cpp -o solution_O0
 * g++ -std=c++11 -pthread -O2 volatile_demo_solution.cpp -o solution_O2
 *
 * LEARNING POINTS:
 *
 * 1. Volatile Semantics:
 *    - Prevents compiler from caching variable in registers
 *    - Forces memory reads/writes on each access
 *    - Does not provide atomicity or memory ordering guarantees
 *
 * 2. When to Use Volatile:
 *    - Memory-mapped hardware registers
 *    - Variables modified by signal handlers
 *    - Variables shared with interrupt service routines
 *    - NOT for general multi-threading (use atomic instead)
 *
 * 3. Volatile Limitations:
 *    - No atomicity for compound operations (++, +=, etc.)
 *    - No memory ordering guarantees
 *    - Platform-dependent behavior
 *
 * 4. Modern Alternatives:
 *    - std::atomic for thread-safe operations
 *    - std::mutex for critical sections
 *    - std::memory_order for fine-grained control
 */