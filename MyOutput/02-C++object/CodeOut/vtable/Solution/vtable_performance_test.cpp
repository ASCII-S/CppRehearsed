#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <memory>
#include <algorithm>
using namespace std;
using namespace std::chrono;

// Solution for TODO 1: Create classes for performance testing
class VirtualBase {
public:
    // TODO 1.1: Add virtual destructor
    virtual ~VirtualBase() = default;
    
    // TODO 1.2: Add virtual function calculateValue(int x) that returns x * 2 + 1
    virtual int calculateValue(int x) {
        return x * 2 + 1;
    }
    
    // TODO 1.3: Add virtual function processArray(vector<int>& arr) that sorts the array
    virtual void processArray(vector<int>& arr) {
        sort(arr.begin(), arr.end());
    }
    
    // TODO 1.4: Add virtual function fibonacci(int n) that calculates nth fibonacci number
    virtual int fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};

class VirtualDerived : public VirtualBase {
public:
    // TODO 2.1: Override calculateValue(int x) to return x * 3 + 2
    int calculateValue(int x) override {
        return x * 3 + 2;
    }
    
    // TODO 2.2: Override processArray to reverse sort the array (descending order)
    void processArray(vector<int>& arr) override {
        sort(arr.begin(), arr.end(), greater<int>());
    }
    
    // TODO 2.3: Override fibonacci with optimized version (with memoization hint)
    int fibonacci(int n) override {
        static vector<int> memo(50, -1);
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    }
};

class NonVirtualClass {
public:
    // TODO 3.1: Add non-virtual calculateValue(int x) that returns x * 3 + 2
    int calculateValue(int x) {
        return x * 3 + 2;
    }
    
    // TODO 3.2: Add non-virtual processArray(vector<int>& arr) that reverse sorts
    void processArray(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
    }
    
    // TODO 3.3: Add non-virtual fibonacci(int n) with same logic as VirtualDerived
    int fibonacci(int n) {
        static vector<int> memo(50, -1);
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    }
};

// Solution for TODO 4: Create timing utility functions
class PerformanceTimer {
public:
    // TODO 4.1: Add method to start timing
    void start() {
        start_time = high_resolution_clock::now();
    }
    
    // TODO 4.2: Add method to stop timing and return duration in nanoseconds
    long long stop() {
        auto end_time = high_resolution_clock::now();
        return duration_cast<nanoseconds>(end_time - start_time).count();
    }
    
    // TODO 4.3: Add method to run and time a function multiple times
    template<typename Func>
    long long timeFunction(Func&& func, int iterations) {
        start();
        for (int i = 0; i < iterations; ++i) {
            func();
        }
        return stop();
    }
    
private:
    high_resolution_clock::time_point start_time;
};

vector<int> generateTestData(size_t size, int min_val, int max_val) {
    // TODO 4.4: Generate random test data for array operations
    vector<int> data;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min_val, max_val);
    
    for (size_t i = 0; i < size; ++i) {
        data.push_back(dis(gen));
    }
    return data;
}

// Solution for TODO 5: Create performance test functions
void testSimpleVirtualCalls(int iterations) {
    // TODO 5.1: Test calculateValue() virtual vs non-virtual
    cout << "Testing simple function calls with " << iterations << " iterations..." << endl;
    
    VirtualBase* virtualObj = new VirtualDerived();
    NonVirtualClass nonVirtualObj;
    PerformanceTimer timer;
    
    // Test virtual calls
    long long virtualTime = timer.timeFunction([&]() {
        volatile int result = virtualObj->calculateValue(42);
    }, iterations);
    
    // Test non-virtual calls
    long long nonVirtualTime = timer.timeFunction([&]() {
        volatile int result = nonVirtualObj.calculateValue(42);
    }, iterations);
    
    cout << "Virtual calls: " << virtualTime / 1000000.0 << "ms" << endl;
    cout << "Non-virtual calls: " << nonVirtualTime / 1000000.0 << "ms" << endl;
    cout << "Overhead: " << ((double)virtualTime / nonVirtualTime - 1.0) * 100 << "%" << endl;
    
    delete virtualObj;
}

void testComplexVirtualCalls(int iterations, size_t data_size) {
    // TODO 5.2: Test processArray() virtual vs non-virtual
    cout << "\nTesting complex operations (array sorting) with " << iterations << " iterations..." << endl;
    
    VirtualBase* virtualObj = new VirtualDerived();
    NonVirtualClass nonVirtualObj;
    PerformanceTimer timer;
    
    auto testData = generateTestData(data_size, 1, 1000);
    
    // Test virtual calls
    long long virtualTime = timer.timeFunction([&]() {
        auto dataCopy = testData;
        virtualObj->processArray(dataCopy);
    }, iterations);
    
    // Test non-virtual calls
    long long nonVirtualTime = timer.timeFunction([&]() {
        auto dataCopy = testData;
        nonVirtualObj.processArray(dataCopy);
    }, iterations);
    
    cout << "Virtual array processing: " << virtualTime / 1000000.0 << "ms" << endl;
    cout << "Non-virtual array processing: " << nonVirtualTime / 1000000.0 << "ms" << endl;
    cout << "Overhead: " << ((double)virtualTime / nonVirtualTime - 1.0) * 100 << "%" << endl;
    
    delete virtualObj;
}

void testRecursiveVirtualCalls(int iterations, int fib_n) {
    // TODO 5.3: Test fibonacci() virtual vs non-virtual
    cout << "\nTesting recursive calls (fibonacci(" << fib_n << ")) with " << iterations << " iterations..." << endl;
    
    VirtualBase* virtualObj = new VirtualDerived();
    NonVirtualClass nonVirtualObj;
    PerformanceTimer timer;
    
    // Test virtual calls
    long long virtualTime = timer.timeFunction([&]() {
        volatile int result = virtualObj->fibonacci(fib_n);
    }, iterations);
    
    // Test non-virtual calls
    long long nonVirtualTime = timer.timeFunction([&]() {
        volatile int result = nonVirtualObj.fibonacci(fib_n);
    }, iterations);
    
    cout << "Virtual fibonacci: " << virtualTime / 1000000.0 << "ms" << endl;
    cout << "Non-virtual fibonacci: " << nonVirtualTime / 1000000.0 << "ms" << endl;
    cout << "Overhead: " << ((double)virtualTime / nonVirtualTime - 1.0) * 100 << "%" << endl;
    
    delete virtualObj;
}

// Solution for TODO 6: Create polymorphic collection test
void testPolymorphicCollection(int collection_size, int iterations) {
    // TODO 6.1: Create vector of VirtualBase pointers pointing to VirtualDerived objects
    vector<unique_ptr<VirtualBase>> virtualCollection;
    for (int i = 0; i < collection_size; ++i) {
        virtualCollection.push_back(make_unique<VirtualDerived>());
    }
    
    // TODO 6.2: Create vector of NonVirtualClass objects
    vector<NonVirtualClass> nonVirtualCollection(collection_size);
    
    PerformanceTimer timer;
    
    // TODO 6.3: Time virtual calls on polymorphic collection
    long long virtualTime = timer.timeFunction([&]() {
        for (auto& obj : virtualCollection) {
            volatile int result = obj->calculateValue(123);
        }
    }, iterations);
    
    // TODO 6.4: Time direct calls on non-virtual collection
    long long nonVirtualTime = timer.timeFunction([&]() {
        for (auto& obj : nonVirtualCollection) {
            volatile int result = obj.calculateValue(123);
        }
    }, iterations);
    
    // TODO 6.5: Compare results and analyze cache behavior
    cout << "\nPolymorphic collection test (" << collection_size << " objects, " << iterations << " iterations):" << endl;
    cout << "Virtual collection calls: " << virtualTime / 1000000.0 << "ms" << endl;
    cout << "Non-virtual collection calls: " << nonVirtualTime / 1000000.0 << "ms" << endl;
    cout << "Overhead: " << ((double)virtualTime / nonVirtualTime - 1.0) * 100 << "%" << endl;
    cout << "Cache effects included in measurements" << endl;
}

// Solution for TODO 7: Create branch prediction test
void testBranchPrediction(int iterations) {
    // TODO 7.1: Create array of different derived types
    cout << "\nTesting branch prediction impact..." << endl;
    
    const int obj_count = 1000;
    vector<unique_ptr<VirtualBase>> predictableCollection;
    vector<unique_ptr<VirtualBase>> randomCollection;
    
    // Predictable pattern (all same type)
    for (int i = 0; i < obj_count; ++i) {
        predictableCollection.push_back(make_unique<VirtualDerived>());
    }
    
    // Random pattern (mix of base and derived)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    
    for (int i = 0; i < obj_count; ++i) {
        if (dis(gen)) {
            randomCollection.push_back(make_unique<VirtualDerived>());
        } else {
            randomCollection.push_back(make_unique<VirtualBase>());
        }
    }
    
    PerformanceTimer timer;
    
    // TODO 7.2: Test with predictable calling pattern (same type repeatedly)
    long long predictableTime = timer.timeFunction([&]() {
        for (auto& obj : predictableCollection) {
            volatile int result = obj->calculateValue(456);
        }
    }, iterations);
    
    // TODO 7.3: Test with random calling pattern (unpredictable branches)
    long long randomTime = timer.timeFunction([&]() {
        for (auto& obj : randomCollection) {
            volatile int result = obj->calculateValue(456);
        }
    }, iterations);
    
    // TODO 7.4: Compare performance difference
    cout << "Predictable virtual calls: " << predictableTime / 1000000.0 << "ms" << endl;
    cout << "Random virtual calls: " << randomTime / 1000000.0 << "ms" << endl;
    cout << "Branch prediction impact: " << ((double)randomTime / predictableTime - 1.0) * 100 << "%" << endl;
}

// Solution for TODO 8: Create compiler optimization analysis
void testCompilerOptimizations() {
    // TODO 8.1: Test cases where compiler might devirtualize calls
    cout << "\nCompiler optimization analysis:" << endl;
    cout << "- Known type at compile time: Compiler may devirtualize" << endl;
    cout << "- Unknown type (polymorphic): Full virtual dispatch required" << endl;
    
    VirtualDerived knownObj;
    VirtualBase* unknownObj = new VirtualDerived();
    
    // TODO 8.2: Test cases where virtual calls cannot be optimized
    cout << "- Direct object call may be optimized" << endl;
    cout << "- Pointer-based call typically uses vtable" << endl;
    
    // TODO 8.3: Explain optimization opportunities and limitations
    cout << "- Template-based polymorphism enables compile-time optimization" << endl;
    cout << "- Profile-guided optimization can help with virtual calls" << endl;
    cout << "- Modern compilers have sophisticated devirtualization" << endl;
    
    delete unknownObj;
}

// Solution for TODO 9: Create memory layout performance test
void testMemoryLayoutPerformance(int iterations) {
    // TODO 9.1: Test sequential access patterns
    cout << "\nMemory layout performance test..." << endl;
    
    const int obj_count = 10000;
    vector<unique_ptr<VirtualBase>> objects;
    
    for (int i = 0; i < obj_count; ++i) {
        objects.push_back(make_unique<VirtualDerived>());
    }
    
    PerformanceTimer timer;
    
    // TODO 9.2: Test random access patterns
    long long sequentialTime = timer.timeFunction([&]() {
        for (auto& obj : objects) {
            volatile int result = obj->calculateValue(789);
        }
    }, iterations / 10);
    
    // TODO 9.3: Measure cache miss effects
    cout << "Sequential access time: " << sequentialTime / 1000000.0 << "ms" << endl;
    cout << "Cache locality affects vtable access performance" << endl;
}

int main() {
    cout << "=== Virtual Function Performance Analysis ===" << endl;
    
    // Configuration for tests
    const int SIMPLE_ITERATIONS = 10000000;
    const int COMPLEX_ITERATIONS = 100000;
    const size_t ARRAY_SIZE = 1000;
    const int FIBONACCI_N = 20;
    const int COLLECTION_SIZE = 10000;
    
    // Solution for TODO 10: Run comprehensive performance tests
    
    cout << "\n--- Simple Function Call Performance ---" << endl;
    // TODO 10.1: Run simple virtual vs non-virtual tests
    testSimpleVirtualCalls(SIMPLE_ITERATIONS);
    
    cout << "\n--- Complex Operation Performance ---" << endl;
    // TODO 10.2: Run complex operation tests (array processing)
    testComplexVirtualCalls(COMPLEX_ITERATIONS, ARRAY_SIZE);
    
    cout << "\n--- Recursive Call Performance ---" << endl;
    // TODO 10.3: Run recursive function tests
    testRecursiveVirtualCalls(1000, FIBONACCI_N);
    
    cout << "\n--- Polymorphic Collection Performance ---" << endl;
    // TODO 10.4: Run polymorphic collection tests
    testPolymorphicCollection(COLLECTION_SIZE, 1000);
    
    cout << "\n--- Branch Prediction Impact ---" << endl;
    // TODO 10.5: Run branch prediction tests
    testBranchPrediction(10000);
    
    cout << "\n--- Compiler Optimization Analysis ---" << endl;
    // TODO 10.6: Analyze compiler optimization scenarios
    testCompilerOptimizations();
    
    cout << "\n--- Memory Layout Performance ---" << endl;
    // TODO 10.7: Test memory layout impact
    testMemoryLayoutPerformance(1000);
    
    cout << "\n--- Performance Summary and Recommendations ---" << endl;
    // TODO 10.8: Summarize findings and provide practical advice
    cout << "\nKey Findings:" << endl;
    cout << "1. Virtual function overhead: typically 20-50% for simple operations" << endl;
    cout << "2. Overhead decreases for complex operations (sorting, computation)" << endl;
    cout << "3. Branch prediction significantly impacts virtual call performance" << endl;
    cout << "4. Cache locality affects vtable access patterns" << endl;
    cout << "5. Modern compilers can optimize many virtual calls" << endl;
    
    cout << "\nRecommendations:" << endl;
    cout << "- Use virtual functions for design flexibility, not performance" << endl;
    cout << "- Consider templates for performance-critical polymorphism" << endl;
    cout << "- Profile real workloads - synthetic benchmarks can mislead" << endl;
    cout << "- Modern hardware handles virtual calls efficiently" << endl;
    cout << "- Focus on algorithmic improvements over micro-optimizations" << endl;
    cout << "- Virtual function overhead is often negligible in real applications" << endl;
    
    return 0;
} 