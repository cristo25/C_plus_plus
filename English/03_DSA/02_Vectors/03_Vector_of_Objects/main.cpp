// Vectors of objects
//
// A vector can store objects of one type. Members of a struct are public by default; members of
// a class are private by default. const auto& traverses without copying or changing objects.
//
// Analogy: The drawer now stores complete cards, each containing a name and a grade.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Compute the group's average and define what happens when the vector is empty.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int grade;
};

int main() {
    vector<Student> group{{"Ana", 9}, {"Luis", 8}};
    group.push_back({"Eva", 10});

    // Read each complete record through a const reference, without copying names or changing
    // grades.
    for (const auto& student : group) {
        cout << student.name << ": " << student.grade << "\n";
    }
}
