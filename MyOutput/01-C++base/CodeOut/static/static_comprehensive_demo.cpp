/*
 * Static Keyword Comprehensive Demo
 *
 * This file combines all uses of the static keyword in C++.
 * Complete the TODOs to create a comprehensive understanding.
 *
 * Estimated time: 12-15 minutes
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TODO 1: Create a static global variable 'debug_mode' initialized to true
// Write your code here:
static bool debug_mode = true;

// TODO 2: Create a static function 'log_message' that:
// - Takes a string parameter 'message'
// - Only prints the message if debug_mode is true
// - Prefixes the message with "[DEBUG] "
// Write your code here:
static void log_message(string message)
{
    if (debug_mode)
    {
        cout << "[DEBUG] " << message << endl;
    }
}

class BankAccount
{
private:
    // TODO 3: Declare static member variables:
    // - total_accounts (int) - counts total accounts created
    // - total_balance (double) - sum of all account balances
    // - bank_name (string) - name of the bank
    // Write your declarations here:
    static int total_accounts;
    static double total_balance;
    static string bank_name;

    // TODO 4: Declare non-static member variables:
    // - account_number (int) - unique account number
    // - balance (double) - individual account balance
    // - owner_name (string) - account owner's name
    // Write your declarations here:
    int account_number;
    double balance;
    string owner_name;

public:
    // TODO 5: Implement a constructor that:
    // - Takes owner_name and initial_balance as parameters
    // - Increments total_accounts
    // - Sets account_number to total_accounts
    // - Sets balance to initial_balance
    // - Adds initial_balance to total_balance
    // - Calls log_message with account creation info
    // Write your code here:
    BankAccount(string owner_name, int initial_balance)
    {
        BankAccount::total_accounts++;
        this->account_number = total_accounts;
        this->owner_name = owner_name;
        this->balance = initial_balance;
        BankAccount::total_balance += initial_balance;
        log_message("creat BacnkAccount owner_name:" + owner_name + "balance:" + to_string(this->balance));
    }
    // TODO 6: Implement a destructor that:
    // - Subtracts this account's balance from total_balance
    // - Decrements total_accounts
    // - Calls log_message with account destruction info
    // Write your code here:
    ~BankAccount()
    {
        BankAccount::total_balance -= this->balance;
        BankAccount::total_accounts--;
        log_message("destruct BankAccount owner_name:" + owner_name + " balance:" + to_string(this->balance));
    }

    // TODO 7: Implement a static function 'set_bank_name' that:
    // - Takes a string parameter and sets bank_name
    // Write your code here:
    static void set_bank_name(string name)
    {
        BankAccount::bank_name = name;
    }

    // TODO 8: Implement a static function 'get_bank_info' that:
    // - Prints bank name, total accounts, and total balance
    // Write your code here:
    static void get_bank_info()
    {
        cout << "---bank info---" << endl;
        cout << "bank_name: " << BankAccount::bank_name << endl;
        cout << "total_accounts: " << BankAccount::total_accounts << endl;
        cout << "total_balance: " << BankAccount::total_balance << endl;
    }

    // TODO 9: Implement a member function 'deposit' that:
    // - Takes a double amount parameter
    // - Adds amount to this account's balance
    // - Adds amount to total_balance
    // - Calls log_message with transaction info
    // Write your code here:
    void deposit(double amount)
    {
        this->balance += amount;
        BankAccount::total_balance += amount;
        log_message("deposit " + to_string(amount) + " to BankAccount owner_name:" + owner_name + " balance:" + to_string(this->balance));
    }

    // TODO 10: Implement a member function 'get_account_info' that:
    // - Prints account number, owner name, and balance
    // Write your code here:
    void get_account_info()
    {
        cout << "---account info---" << endl;
        cout << "account_number: " << this->account_number << endl;
        cout << "owner_name: " << this->owner_name << endl;
        cout << "balance: " << this->balance << endl;
    }

    // TODO 11: Implement a static function 'transfer_funds' that:
    // - Takes two BankAccount references (from and to) and an amount
    // - Transfers amount from one account to another
    // - Updates individual balances (total_balance remains the same)
    // - Calls log_message with transfer info
    // - Returns true if successful, false if insufficient funds
    // Write your code here:
    static bool transfer_funds(BankAccount &from, BankAccount &to, double amount)
    {
        log_message("transfer_funds from " + to_string(from.balance) + " to " + to_string(to.balance) + " amount:" + to_string(amount));
        if (amount > from.balance)
        {
            log_message("transfer_funds failed, insufficient funds");
            return false;
        }
        double from_balance = from.balance;
        double to_balance = to.balance;
        try
        {
            from.balance -= amount;
            to.balance += amount;
        }
        catch (...)
        {
            from.balance = from_balance;
            to.balance = to_balance;
            log_message("transfer_funds failed, exception");
            return false;
        }
        log_message("transfer_funds success");
        return true;
    }
};

// TODO 12: Define all static member variables outside the class:
// - total_accounts = 0
// - total_balance = 0.0
// - bank_name = "Default Bank"
// Write your code here:
int BankAccount::total_accounts = 0;
double BankAccount::total_balance = 0.0;
string BankAccount::bank_name = "Default Bank";

class Logger
{
private:
    // TODO 13: Create a static function 'get_instance' that returns a static Logger instance
    // This implements the Singleton pattern with Meyer's Singleton
    // Write your code here:
    static Logger &get_instance()
    {
        static Logger instance;
        return instance;
    }

public:
    // TODO 14: Implement a static function 'log' that:
    // - Takes a string message
    // - Gets the singleton instance
    // - Calls instance method to actually log the message
    // Write your code here:
    static void log(string message)
    {
        Logger::get_instance().log_impl(message);
    }

private:
    // TODO 15: Implement a private member function 'log_impl' that:
    // - Takes a string message
    // - Uses a static local counter to number log entries
    // - Prints "[LOG #X] message" where X is the log entry number
    // Write your code here:
    void log_impl(string message)
    {
        static int log_count = 0;
        log_count++;
        log_message("[LOG " + to_string(log_count) + "] " + message);
    }
};

int main()
{
    cout << "=== Static Comprehensive Demo ===" << endl;

    // TODO 16: Set the bank name to "Global Bank"
    // Write your code here:
    BankAccount::set_bank_name("Global Bank");

    // TODO 17: Show initial bank info
    // Write your code here:
    BankAccount::get_bank_info();

    cout << "\n1. Creating bank accounts:" << endl;
    {
        // TODO 18: Create 3 bank accounts with different names and initial balances
        // Write your code here:
        BankAccount account1("John Doe", 1000);
        BankAccount account2("Jane Smith", 2000);
        BankAccount account3("Jim Beam", 3000);

        // TODO 19: Show bank info after creating accounts
        // Write your code here:
        BankAccount::get_bank_info();

        cout << "\n2. Testing transactions:" << endl;

        // TODO 20: Make deposits to different accounts
        // Write your code here:
        account1.deposit(500);
        account2.deposit(1000);
        account3.deposit(1500);

        // TODO 21: Show individual account info for all accounts
        // Write your code here:
        account1.get_account_info();
        account2.get_account_info();
        account3.get_account_info();

        // TODO 22: Transfer money between accounts
        // Write your code here:
        BankAccount::transfer_funds(account1, account2, 200);
        account1.get_account_info();
        account2.get_account_info();

        // TODO 23: Show bank info after transactions
        // Write your code here:
        BankAccount::get_bank_info();

    } // Accounts go out of scope here

    cout << "\n3. After accounts destroyed:" << endl;
    // TODO 24: Show final bank info
    // Write your code here:
    BankAccount::get_bank_info();

    cout << "\n4. Testing logger:" << endl;
    // TODO 25: Use Logger::log() to log several messages
    // Write your code here:
    Logger::log("This is a test message");
    Logger::log("This is another test message");
    Logger::log("This is a third test message");

    cout << "\n5. Turning off debug mode:" << endl;
    // TODO 26: Set debug_mode to false and try logging again
    // Write your code here:
    debug_mode = false;
    cout << "debug_mode: " << debug_mode << endl;
    Logger::log("This is a test message");
    Logger::log("This is another test message");
    Logger::log("This is a third test message");

    return 0;
}

/*
 * Advanced Questions:
 * 1. What happens to static variables when the program terminates?
 * 2. How do static variables behave in multi-threaded environments?
 * 3. What are the initialization order issues with static variables?
 * 4. When should you use static variables vs global variables vs singletons?
 * 5. How does the linker handle static symbols?
 */