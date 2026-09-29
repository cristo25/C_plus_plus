// Reading and displaying input
//
// We will ask for a name and an age. With cout we display the question; with getline(cin, name) we
// store everything up to Enter, including spaces in a full name. With cin >> age we try to read a
// whole number. Before using it, we check that reading succeeded and the age is between 0 and 130.
// We also check the remaining text to reject input such as 20abc. In find_first_not_of(" \t\r") we
// look for something other than spaces, tabs or a carriage return; string::npos means that nothing
// was found. This keeps us from accepting a name made only of spaces. We will study if in the next
// lesson; here we use it to stop when input is incorrect.
//

#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    string name;
    int age = 0;
    cout << "Name: ";
    // We read up to Enter so a full name can contain spaces.
    if (!getline(cin, name) || name.find_first_not_of(" \t\r") == string::npos) {
        cerr << "Invalid name.\n";
        return 1;
    }
    cout << "Age: ";
    // With >> we try to store an integer. If reading fails, we show the error.
    if (!(cin >> age) || age < 0 || age > 130) {
        cerr << "Invalid age.\n";
        return 1;
    }
    // We check the rest of the same line: 20abc is not a valid age.
    string remainder;
    getline(cin, remainder);
    if (cin.bad() || remainder.find_first_not_of(" \t\r") != string::npos) {
        cerr << "Invalid age.\n";
        return 1;
    }
    cout << "Hello, " << name << ". You are " << age << " years old.\n";
}
