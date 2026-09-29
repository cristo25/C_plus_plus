#include "../Ordenamientos.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    burbuja(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}
