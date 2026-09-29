// Repetir con do while
//
// Vamos a hacer al menos un intento antes de preguntar si seguimos. En do while primero ejecutamos
// lo que está entre llaves y después comprobamos la condición. Podemos imaginar que probamos una
// llave y solo entonces decidimos si hace falta otro intento. Aunque la condición resulte falsa
// desde la primera revisión, ya hicimos una vuelta.
//

#include <iostream>

using namespace std;

int main() {
    int intentos = 0;
    // Primero hacemos un intento; luego decidimos si repetir. Siempre habrá al menos uno.
    do {
        ++intentos;
        cout << "Intento " << intentos << "\n";
    } while (intentos < 3);
}
