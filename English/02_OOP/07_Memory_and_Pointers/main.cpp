// Memory and pointers in OOP
//
// We will apply pointers to a Student object. We create the student with make_unique and lend its
// address with get. With observer->getName() we follow that address and call a student function; ->
// means following the pointer and using the dot. Calling reset releases the student. The borrowed
// address then becomes unusable: we must stop using it and set it to nullptr. The borrowed pointer
// is never responsible for deleting the student.
//

#include <iostream>
// We use unique_ptr to release its managed object automatically.
#include <memory>
// We store and work with text using string.
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
    // reset destroys the object. The observer can no longer be followed to read its value
    // afterward.
    owner.reset();
    observer = nullptr;
}
