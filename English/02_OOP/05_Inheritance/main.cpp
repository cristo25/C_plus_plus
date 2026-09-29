// Inheritance
//
// A derived class reuses a base when an is-a relationship exists. Public inheritance preserves
// that relationship for callers. Prefer composition for has-a relationships. This base is not
// used to destroy derived objects through base pointers; the next lesson covers virtual
// destructors.
//
// Analogy: An electric bicycle is still a bicycle and adds a battery.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Use a loop to consume the battery and verify that its charge never becomes negative.

#include <iostream>

using namespace std;

class Bicycle {
    int speed = 0;

public:
    void pedal() {
        speed += 5;
    }
    int getSpeed() const {
        return speed;
    }
};

// Inheritance: an electric bicycle IS a bicycle and reuses its public operations.
class ElectricBicycle : public Bicycle {
    int battery = 100;

public:
    bool assist() {
        if (battery < 10) {
            return false;
        }
        battery -= 10;
        pedal();
        return true;
    }
    int charge() const {
        return battery;
    }
};

int main() {
    ElectricBicycle bicycle;
    if (!(bicycle.assist())) {
        return 1;
    }

    cout << "Speed: " << bicycle.getSpeed() << "\n";
}
