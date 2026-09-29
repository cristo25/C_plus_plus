// Sorting with the standard library
//
// sort provides O(n log n) worst-case comparisons without stability guarantees. stable_sort
// preserves equivalent elements' order. The comparator must express a strict order: use <, not
// <=. A lambda [](...) { ... } defines a small function at its use site.
//
// Analogy: Give the drawer to a tested sorting tool and tell it how to compare its objects.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Sort by name, then by descending grade while preserving ties.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int grade;
};

int main() {
    vector<int> numbers{3, 1, 2};
    sort(numbers.begin(), numbers.end());

    vector<Student> group{{"Ana", 8}, {"Eva", 9}, {"Luis", 8}};
    // stable_sort preserves the original order of ties: Ana stays before Luis.
    stable_sort(group.begin(), group.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade;
    });

    for (const auto& student : group) {
        cout << student.name << ": " << student.grade << "\n";
    }
}
