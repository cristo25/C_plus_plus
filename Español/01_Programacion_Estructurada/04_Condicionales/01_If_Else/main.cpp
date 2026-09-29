// Decidir con if y else
//
// Una condición produce true o false. if, else if y else eligen una rama. Combina condiciones
// con &&, || y !.
//
// Analogía: Es una bifurcación: tomas un camino distinto según la señal que encuentras.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega una autorización para menores acompañados y prueba el límite de 18 años.

#include <iostream>

using namespace std;

bool puedeEntrar(int edad, bool tieneBoleto) {
    // && exige que ambas condiciones sean verdaderas: edad suficiente y boleto.
    return edad >= 18 && tieneBoleto;
}

int main() {

    if (puedeEntrar(20, true)) {
        cout << "Entrada permitida\n";
    } else {
        cout << "Entrada rechazada\n";
    }
}
