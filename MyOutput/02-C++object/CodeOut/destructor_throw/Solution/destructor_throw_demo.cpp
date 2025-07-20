// Solution: destructor_throw_demo.cpp
// Demonstrates what happens if a destructor throws an exception in C++
#include <iostream>
#include <stdexcept>
using namespace std;

class FileHandler
{
public:
    FileHandler() { cout << "FileHandler constructed." << endl; }
    // Destructor that throws an exception (bad practice!)
    ~FileHandler()
    {
        cout << "FileHandler destructed." << endl;
        // Uncomment to simulate exception in destructor
        // throw runtime_error("Exception in destructor!");
        // Good practice: catch exceptions inside destructor
        try
        {
            // throw runtime_error("Exception in destructor!");
        }
        catch (const exception &e)
        {
            cout << "Exception caught in destructor: " << e.what() << endl;
        }
    }
    // close() member function that throws an exception
    void close()
    {
        throw runtime_error("Exception in close()!");
    }
};

int main()
{
    cout << "=== Destructor Throw Exception Demo ===" << endl;
    // 1. Create a FileHandler object, destructor does NOT throw
    {
        FileHandler fh;
    }
    // 2. What if destructor throws during stack unwinding?
    try
    {
        FileHandler fh;
        throw runtime_error("Exception in main block!");
        // If you uncomment throw in destructor, program will call std::terminate
    }
    catch (const exception &e)
    {
        cout << "Caught exception in main: " << e.what() << endl;
    }
    // 3. Destructor with try-catch prevents exception escaping
    {
        FileHandler fh;
        // Destructor will catch its own exception
    }
    // 4. Use close() to throw exception, catch in main
    try
    {
        FileHandler fh2;
        fh2.close();
    }
    catch (const exception &e)
    {
        cout << "Caught exception from close(): " << e.what() << endl;
    }
    // 5. Summary
    cout << "\n[Summary]\n";
    cout << "- Never let exceptions escape from destructors!\n";
    cout << "- Use try-catch in destructors if needed.\n";
    cout << "- Prefer explicit resource release methods for error handling.\n";
    return 0;
}