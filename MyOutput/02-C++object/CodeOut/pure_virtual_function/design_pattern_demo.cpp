#include <iostream>
#include <vector>
#include <algorithm>

// TODO 1: Define Strategy interface using pure virtual function
// - Create abstract class SortStrategy with pure virtual function sort()
// - The sort() function should take vector<int>& as parameter
// - Add virtual destructor

// TODO 2: Implement BubbleSort strategy
// - Inherit from SortStrategy
// - Implement sort() using bubble sort algorithm
// - Add a function to print "Using Bubble Sort"

// TODO 3: Implement QuickSort strategy
// - Inherit from SortStrategy
// - Implement sort() using quick sort algorithm
// - Add a function to print "Using Quick Sort"

// TODO 4: Implement MergeSort strategy
// - Inherit from SortStrategy
// - Implement sort() using merge sort algorithm
// - Add a function to print "Using Merge Sort"

// TODO 5: Implement Context class that uses Strategy pattern
// - Add private member variable strategy (SortStrategy pointer)
// - Add constructor that takes SortStrategy pointer
// - Add setStrategy() function to change strategy at runtime
// - Add executeSort() function that calls strategy->sort()
// - Add virtual destructor

// TODO 6: Implement helper functions
// - Create a function to print vector contents
// - Create a function to generate random vector for testing

int main() {
    std::cout << "=== Strategy Pattern with Pure Virtual Functions Demo ===" << std::endl;
    
    // TODO 7: Create test data
    // - Create a vector with some integers for testing
    // - Print the original vector
    
    // TODO 8: Test different sorting strategies
    // - Create Context object with BubbleSort strategy
    // - Execute sort and print results
    // - Change strategy to QuickSort and test
    // - Change strategy to MergeSort and test
    
    // TODO 9: Demonstrate runtime strategy switching
    // - Create a vector with different data
    // - Show how you can switch strategies without changing client code
    // - Demonstrate the flexibility of the strategy pattern
    
    std::cout << "\n=== Demo completed ===" << std::endl;
    return 0;
} 