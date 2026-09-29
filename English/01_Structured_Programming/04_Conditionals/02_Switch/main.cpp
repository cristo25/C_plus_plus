// Choosing with switch
//
// We will choose a drink using a number. With switch we compare that number against each case, like
// choosing from a menu. With break we leave the switch after handling an option; with default we
// respond when none matches. This is useful for a fixed set of options, such as 1, 2 and 3. In this
// example we return the drink directly with return: we leave the function, so those cases do not
// need break.
//

#include <iostream>
// We store and work with text using string.
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
