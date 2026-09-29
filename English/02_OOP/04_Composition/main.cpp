// Composition
//
// We will build one thing using another as a part. A Car has an Engine, so we store an Engine
// object inside Car. We call this relationship composition. From main we ask the car to start, and
// the car turns on its engine. We can picture a block containing an inventory: having a part does
// not mean being that part. When the car's lifetime ends, its contained engine ends too.
//

#include <iostream>

using namespace std;

class Engine {
    bool on = false;

public:
    void turnOn() {
        on = true;
    }
    bool isOn() const {
        return on;
    }
};

class Car {
    // Composition: a Car HAS an Engine. Its lifetime is tied to the car's lifetime.
    Engine engine;

public:
    void start() {
        engine.turnOn();
    }
    bool isRunning() const {
        return engine.isOn();
    }
};

int main() {
    Car redCar;

    redCar.start();

    cout << "Engine on\n";
}
