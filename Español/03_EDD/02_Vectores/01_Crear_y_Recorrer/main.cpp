#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numeros{10, 20};
    numeros.push_back(30);
    int suma = 0;
    for (int numero : numeros) {
        suma += numero;
    }

    cout << "Suma: " << suma << "\n";
}
