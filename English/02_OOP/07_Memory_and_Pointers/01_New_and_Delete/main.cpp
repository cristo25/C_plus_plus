// Manual dynamic memory
//
// We will create a box while the program is running. With new int(42) we reserve space for an
// integer and receive its address. We store that address in number and read 42 through *number. The
// box does not disappear merely because we stop using the pointer variable: here we must release it
// exactly once with delete. We then set number to nullptr to avoid reusing the address. We never
// use delete on an ordinary local variable or follow a pointer after releasing its data.
//

#include <iostream>

using namespace std;

int main() {
    // new allocates an integer and returns its address; this example releases it manually.
    int* number = new int(42);

    cout << *number << "\n";
    // Release the new allocation once; the pointer no longer refers to a live object.
    delete number;
    number = nullptr; // Avoid accidentally reusing this address.
}
