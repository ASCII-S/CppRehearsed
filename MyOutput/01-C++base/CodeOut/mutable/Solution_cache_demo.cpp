#include <iostream>
#include <optional>
#include <chrono>
#include <thread>

// Rectangle class demonstration for mutable caching
class Rectangle {
private:
    double length_;
    double width_;
    // TODO 1: Add a mutable cache variable to store computed area
    mutable std::optional<double> area_cache_;
    
public:
    Rectangle(double length, double width) : length_(length), width_(width) {}
    
    // TODO 2: Implement get_area() const function with caching
    double get_area() const {
        if (!area_cache_.has_value()) {
            std::cout << "Computing area... (this may take a moment)" << std::endl;
            // Simulate expensive computation
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            area_cache_ = length_ * width_;
        }
        return area_cache_.value();
    }
    
    // TODO 3: Add a function to check if area is cached
    bool is_area_cached() const {
        return area_cache_.has_value();
    }
    
    // TODO 4: Add a function to clear cache
    void clear_cache() {
        area_cache_.reset();
    }
    
    // Helper function to get dimensions
    double get_length() const { return length_; }
    double get_width() const { return width_; }
};

// TODO 5: Create a test function to demonstrate caching behavior
void test_caching() {
    std::cout << "\n=== Testing Caching Behavior ===" << std::endl;
    
    Rectangle rect(5.0, 3.0);
    
    // Test initial state
    std::cout << "Initial cache state: " << (rect.is_area_cached() ? "cached" : "not cached") << std::endl;
    
    // First call - should compute
    auto start = std::chrono::high_resolution_clock::now();
    double area1 = rect.get_area();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "First call: area = " << area1 << ", time = " << duration1.count() << "ms" << std::endl;
    std::cout << "Cache state after first call: " << (rect.is_area_cached() ? "cached" : "not cached") << std::endl;
    
    // Second call - should use cache
    start = std::chrono::high_resolution_clock::now();
    double area2 = rect.get_area();
    end = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Second call: area = " << area2 << ", time = " << duration2.count() << "ms" << std::endl;
    std::cout << "Performance improvement: " << (duration1.count() - duration2.count()) << "ms faster" << std::endl;
}

int main() {
    std::cout << "=== Mutable Caching Demo ===" << std::endl;
    
    // TODO 6: Call test_caching function
    test_caching();
    
    // TODO 7: Demonstrate the cache behavior
    std::cout << "\n=== Additional Cache Demonstrations ===" << std::endl;
    
    Rectangle rect(10.0, 4.0);
    
    // Show cache behavior
    std::cout << "Creating rectangle 10x4" << std::endl;
    std::cout << "Cache state: " << (rect.is_area_cached() ? "cached" : "not cached") << std::endl;
    
    // First computation
    std::cout << "\nFirst get_area() call:" << std::endl;
    double area = rect.get_area();
    std::cout << "Area: " << area << std::endl;
    std::cout << "Cache state: " << (rect.is_area_cached() ? "cached" : "not cached") << std::endl;
    
    // Second call (cached)
    std::cout << "\nSecond get_area() call (should be instant):" << std::endl;
    area = rect.get_area();
    std::cout << "Area: " << area << std::endl;
    
    // Clear cache and recompute
    std::cout << "\nClearing cache..." << std::endl;
    rect.clear_cache();
    std::cout << "Cache state: " << (rect.is_area_cached() ? "cached" : "not cached") << std::endl;
    
    std::cout << "\nCalling get_area() after cache clear:" << std::endl;
    area = rect.get_area();
    std::cout << "Area: " << area << std::endl;
    
    return 0;
} 