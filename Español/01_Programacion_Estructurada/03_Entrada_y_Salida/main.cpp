// Leer y mostrar datos
//
// Vamos a pedir un nombre y una edad. Con cout mostramos la pregunta; con getline(cin, nombre)
// guardamos todo lo escrito hasta Enter, incluidos los espacios de un nombre completo. Con cin >>
// edad intentamos leer un entero. Antes de usarlo comprobamos que la lectura funcionó y que está
// entre 0 y 130. También revisamos el texto restante para rechazar una entrada como 20abc. En
// find_first_not_of(" \t\r") buscamos algo distinto de espacios, tabulaciones o retorno de carro;
// string::npos significa que no encontramos nada. Así evitamos aceptar un nombre formado solo por
// espacios. Vamos a estudiar if con más detalle en el siguiente tema; aquí lo usamos para
// detenernos ante un dato incorrecto.
// Practica: Realiza un programa que registre a una persona.
//
// - Pedir nombre completo, ciudad y edad.
// - Aceptar espacios en el nombre y la ciudad.
// - Mostrar un aviso si falta el nombre o la edad no es válida.
// - Mostrar una ficha con los datos cuando sean correctos.

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

int main() {
    string nombreCompleto;
    string ciudad;
    int edad = 0;

    // 1. Pedir nombre completo (acepta espacios)
    cout << "Ingresa tu nombre completo: ";
    getline(cin, nombreCompleto);

    // 2. Pedir ciudad (acepta espacios)
    cout << "Ingresa tu ciudad: ";
    getline(cin, ciudad);

    // 3. Pedir edad
    cout << "Ingresa tu edad: ";
    cin >> edad;

    // Validación básica y clara para principiantes
    if (nombreCompleto.empty() || ciudad.empty()) {
        cerr << "Error: El nombre y la ciudad no pueden estar vacios.\n";
        return 1;
    }

    if (cin.fail() || edad < 0 || edad > 130) {
        cerr << "Error: La edad no es valida.\n";
        return 1;
    }

    // 4. Mostrar ficha de datos
    cout << "\n--- FICHA DE REGISTRO ---\n";
    cout << "Nombre : " << nombreCompleto << "\n";
    cout << "Ciudad : " << ciudad << "\n";
    cout << "Edad   : " << edad << " anios\n";

    return 0;
}
