// Leer y mostrar datos
//
// getline lee una línea completa. getline(cin, ...) captura la edad como texto y un
// istringstream la interpreta; comprueba el resultado antes de usarlos. Una entrada incorrecta
// debe producir un mensaje y terminar sin calcular con datos inválidos.
//
// Analogía: La consola es una ventanilla: entra una solicitud, verificas que esté completa y
// entregas una respuesta.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Solicita la ciudad con getline. Si mezclas >> y getline, consume antes el salto de
// línea pendiente.
// Se lee la línea completa para rechazar texto sobrante como 20abc, y se rechazan nombres
// formados solo por espacios.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string nombre;
    int edad = 0;
    cout << "Nombre: ";
    // getline captura la línea completa, incluidos espacios; rechazamos un nombre vacío.
    if (!getline(cin, nombre) || nombre.find_first_not_of(" \t\r") == string::npos) {
        cerr << "Nombre invalido.\n";
        return 1;
    }
    cout << "Edad: ";
    string linea;
    if (!getline(cin, linea)) {
        return 1;
    }
    // Interpretamos el texto como un número. ws consume espacios; eof descarta texto sobrante
    // como 20abc.
    istringstream lectura(linea);
    if (!(lectura >> edad) || edad < 0 || edad > 130 || !(lectura >> ws).eof()) {
        cerr << "Edad invalida.\n";
        return 1;
    }
    cout << "Hola, " << nombre << ". Tienes " << edad << " anios.\n";
}
