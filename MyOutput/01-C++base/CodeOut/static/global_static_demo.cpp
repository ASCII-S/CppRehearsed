/*
 * Global Static Variable Demo
 *
 * This file demonstrates the use of static keyword with global variables.
 * Complete the TODOs to understand how static global variables work.
 *
 * Estimated time: 5-8 minutes
 */

#include <iostream>
using namespace std;

// TODO 1: Declare a normal global variable 'normal_global' and initialize it to 100
// Write your code here:
int normal_global = 100;

// TODO 2: Declare a static global variable 'static_global' and initialize it to 200
// Write your code here:
static int static_global = 200;

// TODO 3: Declare a static global variable 'file_counter' and initialize it to 0
// This will be used to count function calls
// Write your code here:
static int file_counter = 0;

// TODO 4: Implement a function called 'increment_counter' that:
// - Increments the file_counter by 1
// - Prints the current value of file_counter
// Write your code here:
void increment_counter()
{
    file_counter++;
    cout << "file_counter: " << file_counter << endl;
}

// TODO 5: Implement a function called 'show_globals' that:
// - Prints the value of normal_global
// - Prints the value of static_global
// Write your code here:
void show_globals()
{
    cout << "normal_global: " << normal_global << endl;
    cout << "static_global: " << static_global << endl;
}
// int main()
// {
//     cout << "=== Global Static Variable Demo ===" << endl;

//     // TODO 6: Call show_globals() function
//     // Write your code here:
//     show_globals();

//     cout << "\n=== Testing function call counter ===" << endl;

//     // TODO 7: Call increment_counter() function 3 times
//     // Write your code here:
//     increment_counter();

//     cout << "\n=== Trying to access variables ===" << endl;

//     // TODO 8: Try to access both normal_global and static_global directly
//     // and print their values
//     // Write your code here:
//     cout << "normal_global: " << normal_global << endl;
//     cout << "static_global: " << static_global << endl;

//     return 0;
// }

/*
 * Questions to think about:
 * 1. What happens if you try to access these variables from another file?
 * 2. What's the difference between normal_global and static_global in terms of linkage?
 * 3. How does the static keyword affect the visibility of global variables?
 *
 * Try creating another .cpp file and attempt to access these variables!
 */

/*
 * Answers:
 * 1. normal_global can be accessed from another file by declaring it as 'extern int normal_global;'
 *    in the other file. However, static_global CANNOT be accessed from another file because
 *    it has internal linkage and is only visible within this file.
 *
 * 2. normal_global has external linkage (can be accessed from other files), while
 *    static_global has internal linkage (only accessible within this file). This means
 *    normal_global can be shared across multiple source files, but static_global is
 *    file-local and each file that declares a static global variable gets its own copy.
 *
 * 3. The static keyword when applied to global variables changes their linkage from
 *    external to internal. This means the variable is only visible within the file
 *    where it's declared, preventing other files from accessing it and avoiding
 *    potential naming conflicts in large projects.
 */