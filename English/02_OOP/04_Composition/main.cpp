// Composition
//
// An object can contain another: a has-a relationship. Members are constructed before the
// containing object's constructor body runs.
//
// Analogy: A car has an engine; a car is not a type of engine.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add a method that turns the engine off through the car.

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
