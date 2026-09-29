// Repeating with do while
//
// We will make at least one attempt before asking whether to continue. In do while we run the
// braces first and check the condition afterward. We can picture trying a key and only then
// deciding whether another attempt is needed. Even if the first check is false, we have already
// made one turn.
//

#include <iostream>

using namespace std;

int main() {
    int attempts = 0;
    do {
        ++attempts;
        cout << "Attempt " << attempts << "\n";
    } while (attempts < 3);
}
