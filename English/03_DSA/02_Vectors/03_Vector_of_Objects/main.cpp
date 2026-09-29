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

    for (const auto& student : group) {
        cout << student.name << ": " << student.grade << "\n";
    }
}
