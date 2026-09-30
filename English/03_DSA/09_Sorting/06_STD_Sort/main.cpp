// Sorting with the standard library
//
// We will compare our work with tools C++ already provides in <algorithm>. sort orders a range
// between begin() and end(); end() marks the position after the last value. For student records we
// provide a function deciding which comes first. The small function written with [] is called a
// lambda: here it receives two students and compares their grades with <. stable_sort preserves the
// earlier order of ties. After understanding manual movements, we can use this tool for a complete
// task.
//
// Practice: We will sort student records by grade.
// - We will create named records with grades, including ties.
// - We will sort them with sort and observe what happens to ties.

// We use sort, stable_sort to sort or change data order.
#include <algorithm>
#include <iostream>
// We store and work with text using string.
#include <string>
// We store a collection that can grow using vector.
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
