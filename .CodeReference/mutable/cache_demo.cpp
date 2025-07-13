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
    // Hint: Use std::optional<double> to represent cached area
    // mutable std::optional<double> area;
    mutable double area_cache_;
    mutable bool is_cached_ = false;
    
public:
    Rectangle(double length, double width) : length_(length), width_(width) {}
    
    // TODO 2: Implement get_area() const function with caching
    // Requirements:
    // - Function should be const
    // - Check if area is already cached
    // - If not cached, compute area and cache it
    // - Return cached area
    // - Add a sleep to simulate expensive computation (100ms)
    double get_area() const {
        // TODO: Implement caching logic here
        if (!is_cached_){
            // std::this_thread::sleep_for(std::chrono::milliseconds(100));
            area_cache_ = length_ * width_;
            is_cached_ = true;
        }
        return area_cache_;
        // return 0.0; // Replace this
    }
    
    // TODO 3: Add a function to check if area is cached
    // Function name: is_area_cached
    // Return type: bool
    // Should be const function
    bool is_area_cached() const{
        return is_cached_;
    }
    
    // TODO 4: Add a function to clear cache
    // Function name: clear_cache
    // This function can be non-const since it's logically modifying the object
    void clear_cache(){
        is_cached_ = false;
    }
    
    // Helper function to get dimensions
    double get_length() const { return length_; }
    double get_width() const { return width_; }
};

// TODO 5: Create a test function to demonstrate caching behavior
// Function name: test_caching
// Requirements:
// - Create a Rectangle object
// - Call get_area() multiple times
// - Show timing differences between first call and subsequent calls
// - Demonstrate that cache works correctly
void test_caching() {
    // TODO: Implement test function
    Rectangle r(2131231232.2342345, 3123123.3242340);
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Cached: " << r.is_area_cached() << " ,area of r is " << r.get_area() << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    double duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout <<"time taken: " << duration1 << "ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << "Cached: " << r.is_area_cached() << " ,area of r is " << r.get_area() << std::endl;
    end = std::chrono::high_resolution_clock::now();
    double duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "time taken: " << duration2 << "ms" << std::endl;
    std::cout << "performance improvement: " << duration1 - duration2 << "ms" << std::endl;
    
}

int main() {
    std::cout << "=== Mutable Caching Demo ===" << std::endl;
    
    // TODO 6: Call test_caching function
    test_caching();
    // TODO 7: Demonstrate the cache behavior
    // Create a Rectangle and show:
    // - First call takes longer (computation time)
    // - Subsequent calls are faster (cached result)
    // - Cache can be cleared and recomputed
    
    return 0;
} 