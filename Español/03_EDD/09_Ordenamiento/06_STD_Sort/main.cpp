#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Alumno {
    string nombre;
    int nota;
};

int main() {
    vector<int> numeros{3, 1, 2};
    sort(numeros.begin(), numeros.end());

    vector<Alumno> grupo{{"Ana", 8}, {"Eva", 9}, {"Luis", 8}};
    stable_sort(grupo.begin(), grupo.end(), [](const Alumno& a, const Alumno& b) {
        return a.nota < b.nota;
    });

    for (const auto& alumno : grupo) {
        cout << alumno.nombre << ": " << alumno.nota << "\n";
    }
}
