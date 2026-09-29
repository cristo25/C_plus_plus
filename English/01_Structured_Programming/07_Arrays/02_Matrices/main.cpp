// Matrices
//
// We will move from one drawer to a cabinet with several drawers. In int cabinet[2][3] we have two
// rows and three columns. We choose a row first and then a slot: cabinet[1][2] is the third slot in
// the second row. We use one loop for rows and another for their values. Both start at zero and
// stop before leaving the cabinet.
//

#include <iostream>

using namespace std;

int main() {
    // A cabinet with two drawers and three compartments per drawer: two rows and three columns.
    int cabinet[2][3]{{1, 2, 3}, {4, 5, 6}};
    // The const reference visits each row without copying or modifying it.
    for (const auto& row : cabinet) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << "\n";
    }
}
