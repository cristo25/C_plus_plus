#include "Busquedas.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{8, 3, 5, 1, 3};
    assert(lineal(datos, 8).value() == 0);
    sort(datos.begin(), datos.end());
    for (int buscado : {0, 1, 3, 5, 8, 99}) {
        assert(lineal(datos, buscado) == binaria(datos, buscado));
    }
    cout << "Indice de 8 despues de ordenar: " << binaria(datos, 8).value() << "\n";
}
