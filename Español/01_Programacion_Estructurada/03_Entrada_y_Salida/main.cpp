// Leer y mostrar datos
//
// Vamos a pedir un nombre, una ciudad y una edad. Con cout mostramos cada pregunta y con getline
// guardamos todo lo escrito hasta Enter, incluidos los espacios de un nombre completo. Con cin >>
// edad intentamos leer un número entero. Antes de mostrar la ficha, comprobamos que no falten el
// nombre ni la ciudad y que la edad esté entre 0 y 130. Si cin.fail() es verdadero, no pudimos leer
// un número. empty() solo detecta texto vacío: un texto formado por espacios no está vacío.
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

    // Pedimos el nombre completo; getline conserva sus espacios.
    cout << "Ingresa tu nombre completo: ";
    getline(cin, nombreCompleto);

    // Pedimos la ciudad del mismo modo.
    cout << "Ingresa tu ciudad: ";
    getline(cin, ciudad);

    // Pedimos la edad como número entero.
    cout << "Ingresa tu edad: ";
    cin >> edad;

    // Si dejamos una respuesta vacía, mostramos el problema y terminamos.
    if (nombreCompleto.empty() || ciudad.empty()) {
        cerr << "Error: El nombre y la ciudad no pueden estar vacios.\n";
        return 1;
    }

    if (cin.fail() || edad < 0 || edad > 130) {
        cerr << "Error: La edad no es valida.\n";
        return 1;
    }

    // Mostramos la ficha solo después de revisar los datos.
    cout << "\n--- FICHA DE REGISTRO ---\n";
    cout << "Nombre : " << nombreCompleto << "\n";
    cout << "Ciudad : " << ciudad << "\n";
    cout << "Edad   : " << edad << " anios\n";

    return 0;
}
