// Const and headers in DSA
//
// A structure query can receive const vector<int>&, reading elements without copying or
// modifying the vector. The vector and result here are const. The header declares the operation
// and an inline constexpr constant, the implementation defines the algorithm with count_if, and
// main.cpp uses it. The query takes O(n) time and O(1) auxiliary space.
// Lists, trees and graphs already have headers containing classes and operations. This lesson
// separates a query's declaration from implementation. Compare its signature with a sorting
// function taking vector<int>& to distinguish reading from modification.
//
// Analogy: A query inspects a drawer through glass and counts items without changing their
// positions. Sorting requires opening the drawer and moving them.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Queries.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add a query counting values below a limit without modifying the data. Test an empty
// vector and expect 0. Try sorting the const vector and observe the compiler error; make a
// mutable copy if sorting is required.

#include "Queries.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    const vector<int> data{9, 4, 10, 6};
    // The query receives const vector<int>&: count without copying or changing the data.
    const size_t count = countAbove(data, EXAMPLE_LIMIT);
    cout << "Values above " << EXAMPLE_LIMIT << ": " << count << "\n";
    for (const int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}
