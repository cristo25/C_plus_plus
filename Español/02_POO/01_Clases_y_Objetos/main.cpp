// Clases y objetos
//
// Una clase define datos y operaciones; un objeto es una instancia concreta. public permite usar
// esos miembros desde fuera. En el siguiente tema protegeremos los datos con private.
//
// Analogía: La clase es el plano de una bicicleta; cada bicicleta construida es un objeto con su
// propio color.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega un método frenar y verifica que los objetos mantengan estados independientes.
// La bicicleta azul también se muestra, con velocidad 0, para observar que tiene su propio
// estado.

#include <iostream>
#include <string>

using namespace std;

// La clase es el molde; cada objeto tendrá su propio color y velocidad.
class Bicicleta {
// Estos atributos públicos introducen objetos; el siguiente tema protegerá el estado.
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
