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
    // We prepare the session with the name we receive.
    Session(const string& name) : user(name) {
        cout << "Enter " << user << "\n";
    }
    // The destructor runs automatically when the object's lifetime ends.
    ~Session() {
        cout << "Leave " << user << "\n";
    }
};

int main() {
    {
        Session session("Ana");
    } // The lifetime of session ends here.
    cout << "Session ended\n";
}

// Practice: let's create a Game class that announces its beginning and end.
// - Receive the game's name in the constructor.
// - Print a message in the destructor.
// - Create the game inside braces and observe the order of the messages.
