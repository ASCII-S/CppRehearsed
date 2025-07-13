#include <iostream>
#include <cstddef>

using namespace std;

// TODO 1: Define different struct types to analyze memory alignment
// Create the following structs and predict their sizes before testing

// TODO 1.1: Basic struct with mixed data types
struct BasicStruct {
    char a;      // 1 byte at offset 0
    int b;       // 4 bytes at offset 4 (3 bytes padding after a)
    char c;      // 1 byte at offset 8
                 // 3 bytes padding at end to make total size multiple of 4
}; // Total size: 12 bytes

// TODO 1.2: Reordered struct - same members but different order
struct ReorderedStruct {
    char a;      // 1 byte at offset 0
    char c;      // 1 byte at offset 1
    int b;       // 4 bytes at offset 4 (2 bytes padding after c)
}; // Total size: 8 bytes

// TODO 1.3: Struct with double (8-byte alignment)
struct DoubleStruct {
    char a;      // 1 byte at offset 0
    double d;    // 8 bytes at offset 8 (7 bytes padding after a)
    char b;      // 1 byte at offset 16
                 // 7 bytes padding at end
}; // Total size: 24 bytes

// TODO 1.4: Optimized struct with proper ordering
struct OptimizedStruct {
    double d;    // 8 bytes at offset 0
    int b;       // 4 bytes at offset 8
    char a;      // 1 byte at offset 12
    char c;      // 1 byte at offset 13
                 // 2 bytes padding at end
}; // Total size: 16 bytes

// TODO 2: Define packed structs using pragma pack
#pragma pack(1)
// TODO 2.1: Create packed version of BasicStruct
struct PackedBasicStruct {
    char a;      // 1 byte at offset 0
    int b;       // 4 bytes at offset 1 (no padding)
    char c;      // 1 byte at offset 5
}; // Total size: 6 bytes (no padding)
#pragma pack()

// TODO 3: Define aligned structs using alignas (C++11)
// TODO 3.1: Create a struct with forced 16-byte alignment
struct alignas(16) AlignedStruct {
    char a;      // 1 byte
    int b;       // 4 bytes
                 // 11 bytes padding to reach 16-byte alignment
}; // Total size: 16 bytes

// Function to analyze struct properties
template<typename T>
void analyzeStruct(const string& structName) {
    cout << "=== " << structName << " ===" << endl;
    
    // TODO 4: Implement struct analysis
    cout << "Size: " << sizeof(T) << " bytes" << endl;
    cout << "Alignment: " << alignof(T) << " bytes" << endl;
    
    // Note: offsetof usage depends on specific struct members
    // For demonstration, we'll show BasicStruct offsets
    if (structName == "BasicStruct") {
        cout << "Member offsets:" << endl;
        cout << "  a: " << offsetof(BasicStruct, a) << endl;
        cout << "  b: " << offsetof(BasicStruct, b) << endl;
        cout << "  c: " << offsetof(BasicStruct, c) << endl;
    }
    
    cout << endl;
}

// TODO 5: Create a function to demonstrate memory layout
void demonstrateMemoryLayout() {
    cout << "=== Memory Layout Demonstration ===" << endl;
    
    // TODO 5.1: Create instances of your structs
    BasicStruct basic;
    ReorderedStruct reordered;
    PackedBasicStruct packed;
    
    // TODO 5.2: Print their addresses to show alignment
    cout << "Memory addresses (showing alignment):" << endl;
    cout << "BasicStruct address: " << &basic << " (alignment: " << alignof(BasicStruct) << ")" << endl;
    cout << "ReorderedStruct address: " << &reordered << " (alignment: " << alignof(ReorderedStruct) << ")" << endl;
    cout << "PackedBasicStruct address: " << &packed << " (alignment: " << alignof(PackedBasicStruct) << ")" << endl;
    
    // TODO 5.3: Show the difference between packed and unpacked versions
    cout << "Size comparison:" << endl;
    cout << "BasicStruct: " << sizeof(BasicStruct) << " bytes" << endl;
    cout << "PackedBasicStruct: " << sizeof(PackedBasicStruct) << " bytes" << endl;
    cout << "Space saved by packing: " << (sizeof(BasicStruct) - sizeof(PackedBasicStruct)) << " bytes" << endl;
    cout << endl;
}

// TODO 6: Implement a struct optimization exercise
void optimizationExercise() {
    cout << "=== Struct Optimization Exercise ===" << endl;
    
    // TODO 6.1: Define a poorly arranged struct with many padding bytes
    struct PoorStruct {
        char a;      // 1 byte + 7 bytes padding
        double d1;   // 8 bytes
        char b;      // 1 byte + 3 bytes padding  
        int i;       // 4 bytes
        char c;      // 1 byte + 7 bytes padding
        double d2;   // 8 bytes
    }; // Total: 32 bytes with lots of padding
    
    // TODO 6.2: Reorganize it to minimize padding
    struct OptimizedVersion {
        double d1;   // 8 bytes
        double d2;   // 8 bytes
        int i;       // 4 bytes
        char a;      // 1 byte
        char b;      // 1 byte
        char c;      // 1 byte
                     // 1 byte padding
    }; // Total: 24 bytes
    
    // TODO 6.3: Compare the sizes and show the improvement
    cout << "Poor struct size: " << sizeof(PoorStruct) << " bytes" << endl;
    cout << "Optimized struct size: " << sizeof(OptimizedVersion) << " bytes" << endl;
    cout << "Space saved: " << (sizeof(PoorStruct) - sizeof(OptimizedVersion)) << " bytes" << endl;
    cout << "Efficiency improvement: " << 
        (100.0 * (sizeof(PoorStruct) - sizeof(OptimizedVersion)) / sizeof(PoorStruct)) << "%" << endl;
    cout << endl;
}

int main() {
    cout << "C++ Memory Alignment Analysis Exercise - SOLUTION" << endl;
    cout << "=================================================" << endl;
    
    // TODO 7: Test all your struct definitions
    
    // TODO 7.1: Analyze basic structs
    analyzeStruct<BasicStruct>("BasicStruct");
    analyzeStruct<ReorderedStruct>("ReorderedStruct");
    
    // TODO 7.2: Analyze double alignment
    analyzeStruct<DoubleStruct>("DoubleStruct");
    analyzeStruct<OptimizedStruct>("OptimizedStruct");
    
    // TODO 7.3: Analyze packed structs
    analyzeStruct<PackedBasicStruct>("PackedBasicStruct");
    
    // TODO 7.4: Analyze aligned structs  
    analyzeStruct<AlignedStruct>("AlignedStruct");
    
    // TODO 8: Run demonstration functions
    demonstrateMemoryLayout();
    optimizationExercise();
    
    // TODO 9: Print platform information
    cout << "=== Platform Information ===" << endl;
    cout << "Basic type sizes on this platform:" << endl;
    cout << "char: " << sizeof(char) << " bytes (alignment: " << alignof(char) << ")" << endl;
    cout << "short: " << sizeof(short) << " bytes (alignment: " << alignof(short) << ")" << endl;
    cout << "int: " << sizeof(int) << " bytes (alignment: " << alignof(int) << ")" << endl;
    cout << "long: " << sizeof(long) << " bytes (alignment: " << alignof(long) << ")" << endl;
    cout << "long long: " << sizeof(long long) << " bytes (alignment: " << alignof(long long) << ")" << endl;
    cout << "float: " << sizeof(float) << " bytes (alignment: " << alignof(float) << ")" << endl;
    cout << "double: " << sizeof(double) << " bytes (alignment: " << alignof(double) << ")" << endl;
    cout << "void*: " << sizeof(void*) << " bytes (alignment: " << alignof(void*) << ")" << endl;
    
    return 0;
}

/* 
Expected Output Analysis:
========================

1. BasicStruct: 12 bytes (char + 3 padding + int + char + 3 padding)
2. ReorderedStruct: 8 bytes (char + char + 2 padding + int)
3. DoubleStruct: 24 bytes (char + 7 padding + double + char + 7 padding)
4. OptimizedStruct: 16 bytes (double + int + char + char + 2 padding)
5. PackedBasicStruct: 6 bytes (no padding due to pack(1))
6. AlignedStruct: 16 bytes (forced 16-byte alignment)

Key Learning Points:
===================
- Member order significantly affects struct size
- Grouping same-sized members reduces padding
- pragma pack can eliminate padding but may hurt performance
- alignas can force specific alignment requirements
- Understanding alignment helps optimize memory usage

Performance Considerations:
===========================
- Aligned access is faster than unaligned access
- Cache line efficiency improves with proper alignment
- Packed structs save space but may be slower to access
- Consider both space and time trade-offs in real applications
*/ 