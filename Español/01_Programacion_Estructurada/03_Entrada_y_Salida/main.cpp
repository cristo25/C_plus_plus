#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string nombre;
    int edad = 0;
    cout << "Nombre: ";
    if (!getline(cin, nombre) || nombre.find_first_not_of(" \t\r") == string::npos) {
        cerr << "Nombre invalido.\n";
        return 1;
    }
    cout << "Edad: ";
    string linea;
    if (!getline(cin, linea)) {
        return 1;
    }
    istringstream lectura(linea);
    if (!(lectura >> edad) || edad < 0 || edad > 130 || !(lectura >> ws).eof()) {
        cerr << "Edad invalida.\n";
        return 1;
    }
    cout << "Hola, " << nombre << ". Tienes " << edad << " anios.\n";
}
