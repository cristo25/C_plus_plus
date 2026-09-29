// Choosing with switch
//
// switch selects among concrete integer, character or enumeration values. break ends a case and
// default handles unknown values. This example uses return, which ends both the case and the
// function.
//
// Analogy: A numbered restaurant menu sends each choice to a different preparation.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add a third drink and test option 0.

#include <iostream>
#include <string>

using namespace std;

string drink(int option) {
    // Each case returns a drink. return exits the function, so these cases need no break.
    switch (option) {
        case 1:
            return "Water";
        case 2:
            return "Coffee";
        default:
            return "Invalid option";
    }
}

int main() {

    cout << drink(2) << "\n";
}
