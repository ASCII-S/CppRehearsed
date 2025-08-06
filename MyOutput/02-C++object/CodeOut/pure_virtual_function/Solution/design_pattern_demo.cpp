#include <iostream>
#include <vector>
#include <algorithm>

// Strategy interface using pure virtual function
class SortStrategy {
public:
    virtual ~SortStrategy() {}
    virtual void sort(std::vector<int>& data) = 0;
};

// BubbleSort strategy
class BubbleSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Using Bubble Sort" << std::endl;
        int n = data.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// QuickSort strategy
class QuickSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Using Quick Sort" << std::endl;
        quickSort(data, 0, data.size() - 1);
    }
    
private:
    void quickSort(std::vector<int>& data, int low, int high) {
        if (low < high) {
            int pi = partition(data, low, high);
            quickSort(data, low, pi - 1);
            quickSort(data, pi + 1, high);
        }
    }
    
    int partition(std::vector<int>& data, int low, int high) {
        int pivot = data[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (data[j] < pivot) {
                i++;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return i + 1;
    }
};

// MergeSort strategy
class MergeSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Using Merge Sort" << std::endl;
        mergeSort(data, 0, data.size() - 1);
    }
    
private:
    void mergeSort(std::vector<int>& data, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(data, left, mid);
            mergeSort(data, mid + 1, right);
            merge(data, left, mid, right);
        }
    }
    
    void merge(std::vector<int>& data, int left, int mid, int right) {
        std::vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        
        while (i <= mid && j <= right) {
            if (data[i] <= data[j]) {
                temp[k++] = data[i++];
            } else {
                temp[k++] = data[j++];
            }
        }
        
        while (i <= mid) temp[k++] = data[i++];
        while (j <= right) temp[k++] = data[j++];
        
        for (i = 0; i < k; i++) {
            data[left + i] = temp[i];
        }
    }
};

// Context class that uses Strategy pattern
class SortContext {
private:
    SortStrategy* strategy;
    
public:
    SortContext(SortStrategy* s) : strategy(s) {}
    
    void setStrategy(SortStrategy* s) {
        strategy = s;
    }
    
    void executeSort(std::vector<int>& data) {
        strategy->sort(data);
    }
    
    ~SortContext() {
        delete strategy;
    }
};

// Helper function to print vector contents
void printVector(const std::vector<int>& vec) {
    std::cout << "Vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Helper function to generate test vector
std::vector<int> generateTestVector() {
    return {64, 34, 25, 12, 22, 11, 90};
}

int main() {
    std::cout << "=== Strategy Pattern with Pure Virtual Functions Demo ===" << std::endl;
    
    // Create test data
    std::vector<int> data = generateTestVector();
    std::cout << "Original ";
    printVector(data);
    
    // Test different sorting strategies
    SortContext context(new BubbleSort());
    std::vector<int> data1 = data;
    context.executeSort(data1);
    printVector(data1);
    
    context.setStrategy(new QuickSort());
    std::vector<int> data2 = data;
    context.executeSort(data2);
    printVector(data2);
    
    context.setStrategy(new MergeSort());
    std::vector<int> data3 = data;
    context.executeSort(data3);
    printVector(data3);
    
    // Demonstrate runtime strategy switching
    std::cout << "\nRuntime strategy switching:" << std::endl;
    std::vector<int> testData = {5, 2, 8, 1, 9, 3};
    printVector(testData);
    
    // Switch strategies without changing client code
    context.setStrategy(new BubbleSort());
    context.executeSort(testData);
    printVector(testData);
    
    std::cout << "\n=== Demo completed ===" << std::endl;
    return 0;
} 