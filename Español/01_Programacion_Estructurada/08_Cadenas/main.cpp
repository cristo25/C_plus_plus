#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre = "Ana";
    string saludo = "Hola, " + nombre;
    auto posicion = saludo.find(nombre);

    cout << saludo << "\n";
    if (posicion != string::npos) {
        cout << saludo.substr(posicion) << "\n";
    }
}
