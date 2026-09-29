#include <iostream>
#include <string>

using namespace std;

class Session {
    string user;

public:
    explicit Session(const string& name) : user(name) {
        cout << "Enter " << user << "\n";
    }
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
