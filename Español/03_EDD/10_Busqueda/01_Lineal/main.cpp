#include "../Busquedas.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    const vector<int> datos{8, 3, 5, 3};
    auto posicion = lineal(datos, 3);

    if (posicion) {
        cout << "Indice: " << *posicion << "\n";
    }
}
