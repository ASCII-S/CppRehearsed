#include <iostream>
#include <cstddef>

using namespace std;

// TODO 1: Define different struct types to analyze memory alignment
// Create the following structs and predict their sizes before testing

// TODO 1.1: Basic struct with mixed data types
// struct BasicStruct {
//     char a;
//     int b;
//     char c;
// };
struct BasicStruct{
    char a;
    int b;
    char c;
};

// TODO 1.2: Reordered struct - same members but different order
// struct ReorderedStruct {
//     char a;
//     char c;
//     int b;
// };
struct ReorderedStruct{
    char a;
    char b;
    int c;
};

// TODO 1.3: Struct with double (8-byte alignment)
// struct DoubleStruct {
//     char a;
//     double d;
//     char b;
// };
struct DoubleStruct{
    char a;
    double b;
    char c;
};

// TODO 1.4: Optimized struct with proper ordering
// struct OptimizedStruct {
//     double d;
//     int b;
//     char a;
//     char c;
// };
struct OptimizedStruct{
    double a;
    int b;
    char c;
    char d;
};

// TODO 2: Define packed structs using pragma pack
// Uncomment and complete the following:

/*
#pragma pack(1)
// TODO 2.1: Create packed version of BasicStruct
// struct PackedBasicStruct {
//     // Your code here
// };
#pragma pack()
*/
#pragma pack(1)
struct PackedBasicStruct{
    char a;
    int b;
    char c;
};
#pragma pack()

// TODO 3: Define aligned structs using alignas (C++11)
// TODO 3.1: Create a struct with forced 16-byte alignment
// struct AlignedStruct {
//     // Your code here with alignas(16)
// };
struct alignas(16 )AlignedStruct{
    char a;
    int b;
    char c;
};

// Function to analyze struct properties
template<typename T>
void analyzeStruct(const string& structName) {
    cout << "=== " << structName << " ===" << endl;
    
    // TODO 4: Implement struct analysis
    // Print the following information:
    // - sizeof(T)
    // - alignof(T) 
    // - offsetof for each member (use offsetof macro)
    
    // Your code here:
    cout << "sizeof(" << structName << "): " << sizeof(T) << endl;
    cout << "alignof(" << structName << "): " << alignof(T) << endl;
    cout << "offset a: " << offsetof(T,a) << endl;
    cout << "offset b: " << offsetof(T,b) << endl;
    cout << "offset c: " << offsetof(T,c) << endl;
    // cout << "offset d: " << offsetof(T,d) << endl;
    cout << endl;
}

// TODO 5: Create a function to demonstrate memory layout
void demonstrateMemoryLayout() {
    cout << "=== Memory Layout Demonstration ===" << endl;
    
    // TODO 5.1: Create instances of your structs
    // TODO 5.2: Print their addresses to show alignment
    // TODO 5.3: Show the difference between packed and unpacked versions
    
    // Your code here:
    BasicStruct bs;
    PackedBasicStruct pbs;
    AlignedStruct as;
    auto showAddress = [](auto& T, const string& name)->void{
        cout << name << " address a: " << static_cast<void*>(&T.a) << endl;
        cout << name << " address b: " << static_cast<void*>(&T.b) << endl;
        cout << name << " address c: " << static_cast<void*>(&T.c) << endl;
    };
    showAddress(bs, "BasicStruct");
    showAddress(pbs, "PackedBasicStruct");    
    showAddress(as, "AlignedStruct");
}

// TODO 6: Implement a struct optimization exercise
void optimizationExercise() {
    cout << "=== Struct Optimization Exercise ===" << endl;
    
    // TODO 6.1: Define a poorly arranged struct with many padding bytes
    // TODO 6.2: Reorganize it to minimize padding
    // TODO 6.3: Compare the sizes and show the improvement
    
    // Example poorly arranged struct:
    // struct PoorStruct {
    //     char a;
    //     double d1;
    //     char b;
    //     int i;
    //     char c;
    //     double d2;
    // };
    struct PoolStruct{
        char a1;
        int b;
        char a2;
        double c;
        char a3;
        string d;
        bool a4;
    };
    
    // Your optimized version:
    // struct OptimizedVersion {
    //     // Rearrange members here
    // };
    struct OptimizedPoolStruct{
        double c;
        int b;
        string d;
        char a1;
        char a2;
        char a3;
        bool a4;
    };
    
    // Your analysis code here:
    PoolStruct ps;
    OptimizedPoolStruct ops;
    cout << "size of PoorStruct: " << sizeof(PoolStruct) << endl;
    cout << "offset of char a1:" << offsetof(PoolStruct,a1) << endl;
    cout << "offset of int b:" << offsetof(PoolStruct,b) << endl;
    cout << "offset of char a2:" << offsetof(PoolStruct,a2) << endl;
    cout << "offset of double c:" << offsetof(PoolStruct,c) << endl;
    cout << "size of double c:" << sizeof(ps.c) << endl;
    cout << "offset of char a3:" << offsetof(PoolStruct,a3) << endl;
    cout << "offset of string d:" << offsetof(PoolStruct,d) << endl;
    cout << "size of string d:" << sizeof(ps.d) << endl;
    cout << "offset of bool a4:" << offsetof(PoolStruct,a4) << endl;
    cout << "offset of string d:" << offsetof(PoolStruct,d) << endl;

    cout << "size of OptimizedPoolStruct: " << sizeof(OptimizedPoolStruct) << endl;
    cout << "offset of double c:" << offsetof(OptimizedPoolStruct,c) << endl;
    cout << "offset of int b:" << offsetof(OptimizedPoolStruct,b) << endl;
    cout << "offset of string d:" << offsetof(OptimizedPoolStruct,d) << endl;
    cout << "size of string d:" << sizeof(ops.d) << endl;
    cout << "offset of char a1:" << offsetof(OptimizedPoolStruct,a1) << endl;
    cout << "offset of char a2:" << offsetof(OptimizedPoolStruct,a2) << endl;
    cout << "offset of char a3:" << offsetof(OptimizedPoolStruct,a3) << endl;
    cout << "offset of bool a4:" << offsetof(OptimizedPoolStruct,a4) << endl;

}

int main() {
    cout << "C++ Memory Alignment Analysis Exercise" << endl;
    cout << "======================================" << endl;
    
    // TODO 7: Test all your struct definitions
    // Call analyzeStruct for each struct you created
    
    // TODO 7.1: Analyze basic structs
    // analyzeStruct<BasicStruct>("BasicStruct");
    // analyzeStruct<ReorderedStruct>("ReorderedStruct");
    
    // TODO 7.2: Analyze double alignment
    // analyzeStruct<DoubleStruct>("DoubleStruct");
    // analyzeStruct<OptimizedStruct>("OptimizedStruct");
    
    // TODO 7.3: Analyze packed structs
    // analyzeStruct<PackedBasicStruct>("PackedBasicStruct");
    
    // TODO 7.4: Analyze aligned structs  
    // analyzeStruct<AlignedStruct>("AlignedStruct");
    
    // TODO 8: Run demonstration functions
    // demonstrateMemoryLayout();
    optimizationExercise();
    
    // TODO 9: Print platform information
    cout << "=== Platform Information ===" << endl;
    // Print sizeof basic types on this platform
    // Your code here:
    
    return 0;
}

/* 
Exercise Instructions:
======================

1. Complete all TODO items in order (1-9)
2. Predict struct sizes before implementing
3. Verify your predictions by running the code
4. Pay attention to the difference between:
   - Regular alignment vs packed alignment
   - Poor vs optimized member ordering
   - Different data type alignment requirements

Key concepts to demonstrate:
- Structure padding and alignment rules
- Effect of member ordering on struct size
- Using pragma pack to control alignment
- Using alignas for custom alignment
- offsetof macro for member position analysis

Expected time: 20-25 minutes

Tips:
- Use offsetof(struct_type, member_name) to get member offsets
- Remember that alignment requirements depend on the platform
- The largest member determines the struct's overall alignment
*/ 