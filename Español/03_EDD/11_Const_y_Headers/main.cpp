#include "Consultas.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    const vector<int> datos{9, 4, 10, 6};
    const size_t cantidad = contarMayores(datos, LIMITE_DE_EJEMPLO);
    cout << "Valores mayores a " << LIMITE_DE_EJEMPLO << ": " << cantidad << "\n";
    for (const int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}
