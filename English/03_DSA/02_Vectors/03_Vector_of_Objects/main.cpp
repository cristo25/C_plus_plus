// Vectors of objects
//
// We will store complete records inside the vector. With struct Student we group a name and a
// grade, like two boxes on one card. vector<Student> holds those cards and push_back adds another.
// With const auto& we read each card without copying it: auto lets C++ infer the type, & gives
// another label for the same object, and const prevents changes through that label. We use a dot to
// choose a field on the card.
//

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
    vector<Student> group{{"Ana", 9}, {"Luis", 8}};
    group.push_back({"Eva", 10});

    // Read each complete record through a const reference, without copying names or changing
    // grades.
    for (const auto& student : group) {
        cout << student.name << ": " << student.grade << "\n";
    }
}
