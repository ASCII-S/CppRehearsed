// destructor_throw_demo.cpp
// Demo: What happens if a destructor throws an exception in C++?
// Complete the following TODOs step by step.

#include <iostream>
#include <stdexcept>
using namespace std;

// TODO 1: Define a class FileHandler
// - Add a destructor that simulates throwing an exception (e.g., throw runtime_error)
class FileHandler
{
public:
    FileHandler() { cout << "FileHandler constructed." << endl; }
    // TODO: Destructor that throws an exception
    ~FileHandler()
    {
        // Uncomment the next line to simulate exception in destructor
        // throw runtime_error("Exception in destructor!");
        cout << "FileHandler destructed." << endl;
        // throw runtime_error("Exception in destructor");
    }
    // TODO 4: Add a close() member function that throws an exception
    void close()
    {
        // throw runtime_error("Exception in close()!");
        cout << "FileHandler closed." << endl;
        throw runtime_error("Exception in close()");
    }
};

int main()
{
    cout << "=== Destructor Throw Exception Demo ===" << endl;
    // TODO 2: Create a FileHandler object and observe what happens if destructor throws
    // Try-catch cannot catch exceptions thrown from destructors during stack unwinding
    {
        FileHandler fh;
        // Uncomment to test destructor throwing
        // throw runtime_error("Exception in main block!");
    }

    // TODO 3: Modify the destructor to use try-catch to prevent exception escaping
    // (Wrap the throw in try-catch inside the destructor)

    // TODO 4: Call close() manually, catch exception in main
    try
    {
        FileHandler fh2;
        fh2.close(); // Uncomment throw in close() to test
    }
    catch (const exception &e)
    {
        cout << "Caught exception from close(): " << e.what() << endl;
    }

    // TODO 5: Summarize the risks and best practices for throwing exceptions in destructors
    cout << "\n[Summary]\n";
    cout << "- Never let exceptions escape from destructors!\n";
    cout << "- Use try-catch in destructors if needed.\n";
    cout << "- Prefer explicit resource release methods for error handling.\n";
    return 0;
}