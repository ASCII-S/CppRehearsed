/*
 * const_member_function.cpp
 * Demonstration of const member functions in C++
 *
 * This file demonstrates:
 * - const member functions and their restrictions
 * - const objects and what they can call
 * - const vs non-const function overloading
 * - mutable keyword usage
 *
 * TODO: Complete the code by following the instructions
 */

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string owner_name;
    double balance;
    mutable int access_count; // mutable allows modification in const functions

public:
    // Constructor
    BankAccount(const string &name, double initial_balance)
        : owner_name(name), balance(initial_balance), access_count(0) {}

    // TODO: const member function - can only read data
    // double get_balance() const {
    //     access_count++;  // This works because access_count is mutable
    //     return ???;
    // }
    double get_balance() const
    {
        access_count++;
        return balance;
    }
    // TODO: const member function - cannot modify member variables
    // string get_owner() const {
    //     access_count++;
    //     return ???;
    // }
    string get_owner() const
    {
        access_count++;
        return owner_name;
    }

    // TODO: non-const member function - can modify data
    // void deposit(double amount) {
    //     if (amount > 0) {
    //         ??? += amount;
    //         access_count++;
    //     }
    // }
    void deposit(double amount)
    {
        if (amount > 0)
        {
            cout << "Depositing " << amount << " to balance" << endl;
            balance += amount;
            access_count++;
        }
    }
    // TODO: non-const member function
    // void withdraw(double amount) {
    //     if (amount > 0 && amount <= ???) {
    //         ??? -= amount;
    //         access_count++;
    //     }
    // }
    void withdraw(double amount)
    {
        if (amount > 0)
        {
            cout << "Withdrawing " << amount << " from balance" << endl;
            balance -= amount;
            access_count++;
        }
    }

    // TODO: const member function that cannot call non-const functions
    // void display_info() const {
    //     cout << "Owner: " << ??? << endl;
    //     cout << "Balance: $" << ??? << endl;
    //     cout << "Access count: " << ??? << endl;
    //
    //     // TODO: Try calling a non-const function - what happens?
    //     // deposit(0);  // Uncomment to see error
    // }
    void display_info() const
    {
        cout << "Owner: " << owner_name << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Access count: " << access_count << endl;
        // deposit(0); // Error: cannot call non-const function in const member function
    }
    // TODO: Non-const version that can call other non-const functions
    // void display_info() {  // Function overloading with const version
    //     cout << "[Non-const version]" << endl;
    //     display_info();  // Calls the const version
    //     // Can also call non-const functions if needed
    // }
    void display_info()
    {
        cout << "[Non-const version]" << endl;
        static_cast<const BankAccount *>(this)->display_info(); // call const version
        deposit(0);                                             // can call non-const function here
    }

    // TODO: const member function attempting to modify (should cause errors)
    // void broken_const_function() const {
    //     // Uncomment these lines one by one to see different errors:
    //
    //     // ??? = "New Name";     // Error: cannot modify member
    //     // ??? = 1000.0;        // Error: cannot modify member
    //     // deposit(100);        // Error: cannot call non-const function
    //     // withdraw(50);        // Error: cannot call non-const function
    // }

    int get_access_count() const
    {
        cout << "get_access_count const version called" << endl;
        return access_count;
    }
    int get_access_count()
    {
        cout << "get_access_count non-const version called" << endl;
        return access_count;
    }
};

// Demo class showing const overloading
class DataContainer
{
private:
    string data;

public:
    DataContainer(const string &d) : data(d) {}

    // TODO: const version - returns const reference
    // const string& get_data() const {
    //     cout << "const version called" << endl;
    //     return ???;
    // }
    const string &get_data() const
    {
        cout << "const version called" << endl;
        return data;
    }
    // TODO: non-const version - returns non-const reference
    // string& get_data() {
    //     cout << "non-const version called" << endl;
    //     return ???;
    // }
    string &get_data()
    {
        cout << "non-const version called" << endl;
        return data;
    }

    void set_data(const string &new_data) { data = new_data; }
};

int main()
{
    cout << "=== const Member Functions Demo ===" << endl;

    // Step 1: Regular (non-const) object
    cout << "\n--- Non-const object ---" << endl;

    BankAccount account("Alice", 1000.0);

    // TODO: Call const member functions on non-const object
    // cout << "Owner: " << ???.get_owner() << endl;
    // cout << "Balance: $" << ???.get_balance() << endl;
    cout << "Owner: " << account.get_owner() << endl;
    cout << "Balance: " << account.get_balance() << endl;

    // TODO: Call non-const member functions
    // ???.deposit(500);
    // ???.withdraw(200);
    account.deposit(500);
    account.withdraw(200);

    // TODO: Display account info
    // ???.display_info();  // Which version will be called?
    account.display_info();

    // Step 2: const object
    cout << "\n--- const object ---" << endl;

    const BankAccount const_account("Bob", 2000.0);

    // TODO: Call const member functions on const object
    // cout << "Owner: " << ???.get_owner() << endl;
    // cout << "Balance: $" << ???.get_balance() << endl;
    cout << "Owner: " << const_account.get_owner() << endl;
    cout << "Balance: " << const_account.get_balance() << endl;

    // TODO: Try calling non-const member functions (should cause errors)
    // Uncomment to see errors:
    // const_account.deposit(100);   // Error: const object cannot call non-const function
    // const_account.withdraw(50);   // Error: const object cannot call non-const function

    // TODO: Call const version of display_info
    // ???.display_info();
    const_account.display_info();

    // Step 3: Function overloading based on const
    cout << "\n--- Function overloading with const ---" << endl;

    DataContainer container("Hello World");
    const DataContainer const_container("Const Hello");

    // TODO: Call get_data on both objects - observe which version is called
    // string& ref1 = ???.get_data();          // Non-const version
    // const string& ref2 = ???.get_data();    // Const version
    string &ref1 = container.get_data();
    const string &ref2 = const_container.get_data();
    // TODO: Modify through non-const reference
    // ref1 += " Modified";
    ref1 += "Modified";

    // TODO: Try to modify through const reference (should cause error)
    // ref2 += " Cannot modify";  // Uncomment to see error

    cout << "Modified data: " << container.get_data() << endl;
    cout << "Const data: " << const_container.get_data() << endl;

    // Step 4: Demonstrating mutable keyword
    cout << "\n--- mutable keyword ---" << endl;

    cout << "Access count for regular account: " << account.get_access_count() << endl;
    cout << "Access count for const account: " << const_account.get_access_count() << endl;

    // Even though we called const functions on const_account,
    // access_count was incremented because it's mutable

    // Step 5: Best practices summary
    cout << "\n=== Best Practices Summary ===" << endl;
    cout << "1. Make member functions const whenever possible" << endl;
    cout << "2. const objects can only call const member functions" << endl;
    cout << "3. const member functions cannot modify member variables" << endl;
    cout << "4. const member functions cannot call non-const member functions" << endl;
    cout << "5. Use mutable for data that doesn't affect object's logical state" << endl;
    cout << "6. Provide both const and non-const versions when appropriate" << endl;

    return 0;
}

/*
 * ADVANCED CONCEPTS TO EXPLORE:
 *
 * 1. Why can't const member functions call non-const member functions?
 * 2. When should you use the mutable keyword?
 * 3. How does const-correctness help with design?
 * 4. What happens with inheritance and const member functions?
 * 5. Can constructors and destructors be const? Why or why not?
 *
 * TODO EXERCISES:
 * 1. Complete all the TODO implementations above
 * 2. Create a class with logical const vs bitwise const scenarios
 * 3. Implement a class where const-correctness matters for thread safety
 * 4. Try violating const rules and understand the compiler errors
 *
 * REAL-WORLD APPLICATION:
 * Think about when const member functions are crucial:
 * - Getters that shouldn't modify state
 * - Functions used with const objects
 * - Thread-safe read operations
 * - Interface design for immutable operations
 */