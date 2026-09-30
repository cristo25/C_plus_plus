// Reading and displaying input
//
// We will ask for a name, a city and an age. With cout we show each question, and with getline we
// keep everything typed before Enter, including spaces in a full name. With cin >> age we try to
// read a whole number. Before displaying the card, we check that neither name nor city is empty and
// that age is between 0 and 130. If cin.fail() is true, we could not read a number. empty() only
// finds empty text: text made of spaces is not empty.
//
// Practice: Let's make a registration program.
//
// - Ask for a full name, city and age.
// - Allow spaces in the name and city.
// - Display an error for a missing answer or an invalid age.
// - Display a card when the answers are valid.

#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    string fullName;
    string city;
    int age = 0;
    cout << "Enter your full name: ";
    getline(cin, fullName);

    cout << "Enter your city: ";
    getline(cin, city);

    cout << "Enter your age: ";
    cin >> age;

    if (fullName.empty() || city.empty()) {
        cerr << "Error: Name and city cannot be empty.\n";
        return 1;
    }

    if (cin.fail() || age < 0 || age > 130) {
        cerr << "Error: Invalid age.\n";
        return 1;
    }

    cout << "\n--- REGISTRATION CARD ---\n";
    cout << "Name : " << fullName << "\n";
    cout << "City : " << city << "\n";
    cout << "Age  : " << age << " years\n";

    return 0;
}
