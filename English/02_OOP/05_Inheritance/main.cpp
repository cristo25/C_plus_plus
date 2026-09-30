// Inheritance
//
// We will describe a more specific version of something we already have. An ElectricBicycle is
// still a Bicycle, but it also has a battery. With : public Bicycle we retain the bicycle's public
// operations and add our own. We call this relationship inheritance. In assist we check the battery
// before spending it and pedaling. This fits an “is a” relationship; for “has a part” we use the
// composition from the previous lesson.
//

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
    if (!bicycle.assist()) {
        return 1;
    }

    cout << "Speed: " << bicycle.getSpeed() << "\n";
}

// Practice: let's create a Vehicle class and an ElectricCar class that inherits from it.
// - Give the vehicle a function that moves it forward.
// - Give the electric car a battery that loses charge when used.
// - Show the distance and remaining charge after using the car.
