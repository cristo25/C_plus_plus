// Functions: parameters and return values
//
// We will put a calculation in a function. We can picture a small machine: it receives ingredients,
// does its work and returns a result. We call the inputs parameters; with return we hand back the
// result. When we receive an int by value, we work with a copy: changing it inside the function
// does not change the original variable.
//

// Practice: Let's write a program that converts minutes to seconds.
//
// - Create a function that receives the minutes.
// - Return the result with return.
// - Call it with three different values.
// - Display the results from main.

#include <iostream>

using namespace std;

// The function receives a copy of the number and returns its square.
int square(int number) {
    return number * number;
}

int main() {

    cout << square(4) << "\n";
}
