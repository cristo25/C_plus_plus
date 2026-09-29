#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Alumno {
    string nombre;
    int nota;
};

int main() {
    vector<Alumno> grupo{{"Ana", 9}, {"Luis", 8}};
    grupo.push_back({"Eva", 10});

    for (const auto& alumno : grupo) {
        cout << alumno.nombre << ": " << alumno.nota << "\n";
    }
}
