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
