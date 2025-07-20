/*
 * Local Static Variable Demo
 *
 * This file demonstrates the use of static keyword with local variables.
 * Complete the TODOs to understand the memory behavior of static local variables.
 *
 * Estimated time: 8-10 minutes
 */

#include <iostream>
using namespace std;

// TODO 1: Implement a function called 'call_counter' that:
// - Uses a static local variable 'count' initialized to 0
// - Increments count by 1 each time the function is called
// - Returns the current value of count
//
// Function signature: int call_counter()
// Write your code here:
int call_counter()
{
    static int count = 0;
    count++;
    cout << "call_counter: " << count << endl;

    return count;
}
// TODO 2: Implement a function called 'fibonacci_with_cache' that:
// - Takes an integer parameter 'n'
// - Uses static local variables to cache previous calculations
// - Returns the nth Fibonacci number
// - Prints debug info showing cache hits/misses
//
// Function signature: long fibonacci_with_cache(int n)
// Write your code here:
// long fibonacci_with_cache(int n){
//     static long cache[100] = {0};  // 缓存数组，初始化为0
//     static int cache_hits = 0;     // 缓存命中次数
//     static int cache_misses = 0;   // 缓存未命中次数

//     // 检查缓存中是否已有该值
//     if (cache[n] != 0) {
//         cache_hits++;
//         cout << "Cache HIT for fib(" << n << ") = " << cache[n] << endl;
//         return cache[n];
//     }

//     // 缓存未命中，需要计算
//     cache_misses++;
//     cout << "Cache MISS for fib(" << n << "), calculating..." << endl;

//     long result;
//     if (n == 0) {
//         result = 0;
//     } else if (n == 1) {
//         result = 1;
//     } else {
//         result = fibonacci_with_cache(n-1) + fibonacci_with_cache(n-2);
//     }

//     // 将结果存入缓存
//     cache[n] = result;
//     cout << "Stored fib(" << n << ") = " << result << " in cache" << endl;

//     return result;
// }
long fibonacci_with_cache(int n)
{
    static long cache[100] = {0};
    static int cache_hit = 0;
    static int cache_miss = 0;

    if (n < 100 && cache[n] != 0)
    {
        cout << "Cache Hit in fibonacci_with_cache:" << n << endl;
        cache_hit++;
        return cache[n];
    }

    cache_miss++;
    cout << "Cache Miss in fibonacci_with_cache:" << n << endl;

    long result;
    if (n == 0)
        result = 0;
    else if (n == 1)
        result = 1;
    else
        result = fibonacci_with_cache(n - 1) + fibonacci_with_cache(n - 2);
    if (n < 100)
        cache[n] = result;
    return result;
}

// TODO 3: Implement a function called 'get_unique_id' that:
// - Uses a static local variable 'next_id' initialized to 1
// - Returns the current value of next_id and then increments it
// - This simulates a simple ID generator
//
// Function signature: int get_unique_id()
// Write your code here:
// int get_unique_id()
// {
//     static int next_id = 1;
//     int current_id = next_id;
//     next_id++;
//     cout << "Generated ID: " << current_id << endl;
//     return current_id;
// }
int get_unique_id()
{
    static int next_id = 1;
    int current_id = next_id;
    next_id++;
    cout << "Generated ID: " << current_id << endl;
    return current_id;
}

// TODO 4: Implement a function called 'demonstrate_lifetime' that:
// - Has a normal local variable 'normal_var' initialized to 10
// - Has a static local variable 'static_var' initialized to 20
// - Prints the address and value of both variables
// - Increments both variables by 1
// - Prints their addresses and values again
//
// Function signature: void demonstrate_lifetime()
// Write your code here:
// void demonstrate_lifetime()
// {
//     int normal_var = 10;
//     static int static_var = 20;

//     cout << "Before increment:" << endl;
//     cout << "normal_var: value=" << normal_var << ", address=" << &normal_var << endl;
//     cout << "static_var: value=" << static_var << ", address=" << &static_var << endl;

//     normal_var++;
//     static_var++;

//     cout << "After increment:" << endl;
//     cout << "normal_var: value=" << normal_var << ", address=" << &normal_var << endl;
//     cout << "static_var: value=" << static_var << ", address=" << &static_var << endl;
//     cout << "---" << endl;
// }
void demonstrate_lifetime()
{
    int normal_var = 10;
    static int static_var = 20;
    cout << "Before increment:" << endl;
    cout << "normal_val:value=" << normal_var << ", address=" << &normal_var << endl;
    cout << "static_var: value=" << static_var << ", address=" << &static_var << endl;

    normal_var++;
    static_var++;

    cout << "After increment:" << endl;
    cout << "normal_var: value=" << normal_var << ", address=" << &normal_var << endl;
    cout << "static_var: value=" << static_var << ", address=" << &static_var << endl;
    cout << "---" << endl;
}

int main()
{
    cout << "=== Local Static Variable Demo ===" << endl;

    cout << "\n1. Testing call counter:" << endl;
    // TODO 5: Call call_counter() function 5 times and print results
    // Write your code here:
    for (int i = 0; i < 5; i++)
    {
        call_counter();
    }

    cout << "\n2. Testing unique ID generator:" << endl;
    // TODO 6: Call get_unique_id() function 3 times and print results
    // Write your code here:
    for (int i = 0; i < 3; i++)
    {
        get_unique_id();
    }

    cout << "\n3. Testing variable lifetime and memory location:" << endl;
    // TODO 7: Call demonstrate_lifetime() function 3 times to see the difference
    // Write your code here:
    for (int i = 0; i < 3; i++)
    {
        demonstrate_lifetime();
    }

    cout << "\n4. Testing Fibonacci with cache:" << endl;
    // TODO 8: Call fibonacci_with_cache() with values 5, 10, 5, 10
    // Notice how the cache works
    // Write your code here:
    cout << "fibonacci_with_cache(5) = " << fibonacci_with_cache(5) << endl;
    cout << "fibonacci_with_cache(10) = " << fibonacci_with_cache(10) << endl;
    cout << "fibonacci_with_cache(5) = " << fibonacci_with_cache(5) << endl;   // 应该命中缓存
    cout << "fibonacci_with_cache(10) = " << fibonacci_with_cache(10) << endl; // 应该命中缓存

    return 0;
}

/*
 * Questions to think about:
 * 1. Why do static local variables retain their values between function calls?
 * 2. Where in memory are static local variables stored compared to normal local variables?
 * 3. When exactly is a static local variable initialized?
 * 4. What happens if multiple threads call the same function with static local variables?
 */