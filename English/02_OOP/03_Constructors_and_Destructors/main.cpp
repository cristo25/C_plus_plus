// Constructors, destructors
//
// We will observe when an object starts and ends. Its constructor has the class name and prepares
// its data; in Session it stores the user and announces entry. Its destructor has ~ before the name
// and runs when the object's lifetime ends. We can picture opening a shop and closing it when
// leaving. Here the braces mark that stay: reaching their closing brace displays the exit message.
// Later we will use the same idea to release memory and close files automatically.
//

#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

class Session {
    string user;

public:
    // We prepare the object with its name. With explicit we require an explicit construction, such
    // as Session("Ana").
    explicit Session(const string& name) : user(name) {
        cout << "Enter " << user << "\n";
    }
    // The destructor runs automatically when the object's lifetime ends.
    ~Session() {
        cout << "Leave " << user << "\n";
    }
    const string& name() const {
        return user;
    }
};

int main() {
    {
        Session session("Ana");

    } // The lifetime of session ends here.
    cout << "Session ended\n";
}
