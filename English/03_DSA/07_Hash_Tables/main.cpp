// Hash tables with unordered_map
//
// unordered_map associates unique keys with values through hashing. The hash function directs a
// lookup toward a group of entries. On average, lookup or insertion takes an amount of work that
// does not grow with the total entry count (O(1)). If many keys land in the same group, an
// operation may inspect all n entries (O(n) in the worst case). The library manages collisions and
// does not guarantee iteration order. operator[] can insert; use find for lookup alone.
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
