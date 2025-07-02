/**
 * @file sizeof_struct_align_english.cpp
 *
 * @brief Memory alignment demonstration
 */
#include <iostream>
using namespace std;

// Struct 1: char first, int second
struct st1
{
    char c; // 1 byte
    int i;  // 4 bytes, needs 3 bytes padding
};

// Struct 2: int first, char second
struct st2
{
    int i;  // 4 bytes
    char c; // 1 byte, needs 3 bytes padding
};

// Struct 3: two chars, one int
struct st3
{
    char c1; // 1 byte
    char c2; // 1 byte
    int i;   // 4 bytes, needs 2 bytes padding
};

// Struct 4: disable alignment with pragma pack(1)
#pragma pack(push, 1)
struct st4
{
    char c; // 1 byte
    int i;  // 4 bytes, no padding
};
#pragma pack(pop)

int main()
{
    cout << "=== Memory Alignment Demo ===" << endl;
    cout << "sizeof(char): " << sizeof(char) << " bytes" << endl;
    cout << "sizeof(int): " << sizeof(int) << " bytes" << endl;
    cout << endl;

    cout << "st1 {char, int}: " << sizeof(st1) << " bytes" << endl;
    cout << "st2 {int, char}: " << sizeof(st2) << " bytes" << endl;
    cout << "st3 {char, char, int}: " << sizeof(st3) << " bytes" << endl;
    cout << "st4 {char, int} (packed): " << sizeof(st4) << " bytes" << endl;

    cout << endl;
    cout << "=== Memory Layout Analysis ===" << endl;
    cout << "st1: [char(1)] + [padding(3)] + [int(4)] = 8 bytes" << endl;
    cout << "st2: [int(4)] + [char(1)] + [padding(3)] = 8 bytes" << endl;
    cout << "st3: [char(1)] + [char(1)] + [padding(2)] + [int(4)] = 8 bytes" << endl;
    cout << "st4: [char(1)] + [int(4)] = 5 bytes (alignment disabled)" << endl;

    return 0;
}