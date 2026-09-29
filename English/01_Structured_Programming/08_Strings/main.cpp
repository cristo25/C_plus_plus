// Strings
//
// We will work with text using string. We can picture a necklace where each bead is a letter or
// symbol. With + we join text, with size we count positions, and with find we look for a part. If
// the search returns string::npos, that part was not found. Only after checking do we use substr to
// take a piece. Here we use simple text; an accented letter can occupy more than one position
// depending on how it is stored.
//

#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    string name = "Ana";
    string greeting = "Hello, " + name;
    // find returns the index of the matching text, or string::npos when absent.
    auto position = greeting.find(name);

    cout << greeting << "\n";
    if (position != string::npos) {
        // Extract the substring only after checking that a match exists.
        cout << greeting.substr(position) << "\n";
    }
}
