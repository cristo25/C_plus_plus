#include <iostream>
#include <string>

using namespace std;

class Bicycle {
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
