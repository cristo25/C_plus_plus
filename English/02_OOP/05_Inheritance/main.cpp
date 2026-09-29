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
