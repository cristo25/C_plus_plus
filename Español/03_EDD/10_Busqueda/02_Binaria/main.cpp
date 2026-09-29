#include "../Busquedas.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    const vector<int> datos{1, 3, 3, 5, 8};
    auto posicion = binaria(datos, 3);

    if (posicion) {
        cout << "Indice: " << *posicion << "\n";
    }
}
