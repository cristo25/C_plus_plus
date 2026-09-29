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
    stable_sort(group.begin(), group.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade;
    });

    for (const auto& student : group) {
        cout << student.name << ": " << student.grade << "\n";
    }
}
