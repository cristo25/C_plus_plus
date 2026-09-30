// Classes and objects
//
// We will bring together data and actions that belong to the same thing. We can picture a class as
// the blueprint for a Minecraft block: it describes the data and actions of each block created from
// it. Each actual block would be an object. In this program we use Bicycle: we store color and
// speed, and pedal increases the speed. We create red and blue separately; pedaling red does not
// change blue. We call the stored data attributes and the functions inside the class methods. With
// public we allow main to use them.
//

#include <iostream>
// We store and work with text using string.
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

// Practice: let's create a Block class for two Minecraft blocks.
// - Store each block's name and hardness.
// - Add a function that reduces hardness when we hit the block.
// - Show that hitting one block does not change the other.
