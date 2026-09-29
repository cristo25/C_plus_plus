// Memory and pointers in OOP
//
// Connect ownership to object lifetime. The integration example owns a student through
// unique_ptr and queries it through a non-owning pointer.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Student {
    string name;

public:
    explicit Student(const string& initialName) : name(initialName) {
    }
    const string& getName() const {
        return name;
    }
};

int main() {
    auto owner = make_unique<Student>("Ana");
    // get returns an observer: unique_ptr remains the owner and releases the object.
    const Student* observer = owner.get();

    cout << observer->getName() << "\n";
    // reset destroys the object. The observer can no longer be dereferenced afterward.
    owner.reset();
    observer = nullptr;
}
