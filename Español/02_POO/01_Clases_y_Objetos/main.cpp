#include <iostream>
#include <string>

using namespace std;

class Bicicleta {
public:
    string color;
    int velocidad = 0;
    void pedalear() {
        velocidad += 5;
    }
};

int main() {
    Bicicleta roja;
    roja.color = "roja";
    Bicicleta azul;
    azul.color = "azul";
    roja.pedalear();

    cout << "Bicicleta " << roja.color << ": " << roja.velocidad << "\n";
    cout << "Bicicleta " << azul.color << ": " << azul.velocidad << "\n";
}
