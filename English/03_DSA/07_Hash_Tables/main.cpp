// Hash tables with unordered_map
//
// unordered_map associates unique keys with values through hashing. Search and insertion cost
// O(1) on average and O(n) in the worst case. The library manages collisions and does not
// guarantee iteration order. operator[] can insert; use find for lookup alone.
//
// Analogy: A receptionist turns a key into a locker number and distinguishes records when
// several keys collide.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Insert the same key twice with emplace and inspect the boolean result.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> students;
    students.emplace(101, "Ana");
    students.emplace(102, "Luis");
    // find reads without inserting a new key; here 101 exists because it was inserted above.
    auto found = students.find(101);
    cout << found->second << "\n";
    if (!(students.erase(102) == 1 && students.size() == 1)) {
        return 1;
    }
}
