#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numeros{10, 30};
    numeros.insert(numeros.begin() + 1, 20);

    numeros.erase(numeros.begin());

    if (!numeros.empty()) {
        numeros.pop_back();
    }

    cout << numeros.at(0) << "\n";
}
