// Classes and objects
//
// A class defines data and operations. An object is a concrete instance. public makes members
// accessible from outside; the next lesson protects state with private.
//
// Analogy: A class is a bicycle blueprint. Every bicycle built from it is an object with its own
// color.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add a braking method and check that the two objects keep independent states.
// The blue bicycle is also displayed, at speed 0, showing its independent state.

#include <iostream>
#include <string>

using namespace std;

// The class is a blueprint; each object has its own color and speed.
class Bicycle {
// These public attributes introduce objects; the next lesson protects their state.
public:
    string color;
    int speed = 0;
    void pedal() {
        speed += 5;
    }
};

int main() {
    Bicycle red;
    red.color = "red";
    Bicycle blue;
    blue.color = "blue";
    red.pedal();

    cout << "Bicycle " << red.color << ": " << red.speed << "\n";
    cout << "Bicycle " << blue.color << ": " << blue.speed << "\n";
}
