/*
 * Class Static Member Demo
 *
 * This file demonstrates the use of static keyword with class members.
 * Complete the TODOs to understand static member variables and functions.
 *
 * Estimated time: 10-12 minutes
 */

#include <iostream>
#include <string>
using namespace std;

class Counter
{
private:
    // TODO 1: Declare a static member variable 'total_objects' of type int
    // This will count how many Counter objects have been created
    // Write your declaration here:
    static int total_objects;

    // TODO 2: Declare a non-static member variable 'object_id' of type int
    // This will store the unique ID of each Counter object
    // Write your declaration here:
    int object_id;

public:
    // TODO 3: Implement a constructor that:
    // - Increments total_objects by 1
    // - Sets object_id to the current value of total_objects
    // - Prints "Counter object #[id] created"
    // Write your code here:
    Counter()
    {
        total_objects++;
        object_id = total_objects;
        cout << "Counter object " << object_id << " created" << endl;
    }

    // TODO 4: Implement a destructor that:
    // - Decrements total_objects by 1
    // - Prints "Counter object #[id] destroyed"
    // Write your code here:
    ~Counter()
    {
        total_objects--;
        cout << "Counter object " << object_id << " destroyed" << endl;
    }
    // TODO 5: Implement a static member function called 'get_count' that:
    // - Returns the current value of total_objects
    // - Should not access any non-static members
    // Write your code here:
    static int get_count()
    {
        return total_objects;
    }

    // TODO 6: Implement a non-static member function called 'get_id' that:
    // - Returns the object_id of this instance
    // Write your code here:
    int get_id()
    {
        return object_id;
    }

    // TODO 7: Implement a static member function called 'reset_count' that:
    // - Sets total_objects back to 0
    // - Prints "Counter reset"
    // Write your code here:
    static void reset_count()
    {
        total_objects = 0;
        cout << "Counter reset" << endl;
    }
};

// TODO 8: Define and initialize the static member variable 'total_objects' outside the class
// Initialize it to 0
// Write your code here:
int Counter::total_objects = 0;

class Singleton
{
private:
    // TODO 9: Declare a static pointer member variable 'instance' of type Singleton*
    // Write your declaration here:
    static Singleton *instance;

    // TODO 10: Make the constructor private to prevent direct instantiation
    // The constructor should print "Singleton instance created"
    // Write your code here:
    Singleton()
    {
        cout << "Singleton instance created" << endl;
    }

public:
    // TODO 11: Implement a static member function called 'get_instance' that:
    // - Returns the singleton instance (creates it if it doesn't exist)
    // - Uses static local variable for lazy initialization
    // Write your code here:
    static Singleton &get_instance()
    {
        // 静态局部变量，只会初始化一次
        static Singleton instance_obj;
        // 返回其地址，实现全局唯一
        return instance_obj;
    }
    // use class member variable to implement singleton
    // static Singleton *get_instance()
    // {
    //     if (instance == nullptr) {
    //         instance = new Singleton();
    //     }
    //     return instance;
    // }

    // TODO 12: Implement a member function called 'do_something' that:
    // - Prints "Singleton is doing something..."
    // Write your code here:
    void do_something()
    {
        cout << "Singleton is doing something" << endl;
    }
};

// TODO 13: Define the static member variable 'instance' and initialize it to nullptr
// Write your code here:
Singleton *Singleton::instance = nullptr;

int main()
{
    cout << "=== Class Static Member Demo ===" << endl;

    cout << "\n1. Testing Counter class:" << endl;

    // TODO 14: Print the initial count using Counter::get_count()
    // Write your code here:
    cout << "Counter::get_count() = " << Counter::get_count() << endl;

    {
        // TODO 15: Create 3 Counter objects in this scope
        // Observe how the count changes
        // Write your code here:
        Counter c1;
        Counter c2;
        Counter c3;

        // TODO 16: Print the current count
        // Write your code here:
        cout << "Counter::get_count() = " << Counter::get_count() << endl;

        // TODO 17: Print the ID of each counter object
        // Write your code here:
        cout << "c1.get_id() = " << c1.get_id() << endl;
        cout << "c2.get_id() = " << c2.get_id() << endl;
        cout << "c3.get_id() = " << c3.get_id() << endl;

    } // Objects go out of scope here

    // TODO 18: Print the count after objects are destroyed
    // Write your code here:
    cout << "Counter::get_count() = " << Counter::get_count() << endl;

    cout << "\n2. Testing Singleton class:" << endl;

    // TODO 19: Get the singleton instance and call do_something()
    // Write your code here:
    Singleton *s1 = Singleton::get_instance();
    s1->do_something();

    // TODO 20: Get the singleton instance again and verify it's the same instance
    // Compare the addresses of both instances
    // Write your code here:
    Singleton *s2 = Singleton::get_instance();
    cout << "s1 address: " << s1 << endl;
    cout << "s2 address: " << s2 << endl;
    cout << "s1 == s2: " << (s1 == s2) << endl;

    return 0;
}

/*
 * Questions to think about:
 * 1. Why must static member variables be defined outside the class?
 * 2. Can static member functions access non-static member variables? Why not?
 * 3. What happens to static member variables when all objects of the class are destroyed?
 * 4. How is the Singleton pattern implemented using static members?
 * 5. What are the advantages and disadvantages of static member variables?
 */