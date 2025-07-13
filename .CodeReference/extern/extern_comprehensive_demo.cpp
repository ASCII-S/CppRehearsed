// Extern Comprehensive Practice
// Time: 3 minutes

#include <iostream>
#include <string>

// TODO 1: Declare (not define) an external constant string named 'VERSION'
extern const std::string VERSION;

// TODO 2: Declare an external variable named 'debug_mode' of type bool
extern bool debug_mode;

// TODO 3: Create a namespace named 'Config' and inside it:
//         - Declare an external integer 'max_connections'
namespace Config
{
    extern int max_connections;
}

// TODO 4: Create a header-style function declaration that would typically
//         be in a .h file (use extern keyword explicitly)
extern void print_connections();

// TODO 5: Implement the above function to print configuration info

// For simulation, define the external variables here
// (In real projects, these would be in separate .cpp files)

int main()
{
    // TODO 6: Use all the external variables and call the function
    print_connections();

    // TODO 7: Modify debug_mode and max_connections, then print again
    debug_mode = false;
    Config::max_connections = 200;
    print_connections();

    return 0;
}

// Challenge: Try creating a separate header file (.h) and source file (.cpp)
// Move declarations to .h and definitions to .cpp
// Test the proper extern usage