#include "Product.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    const Product notebook("Notebook", 1250);

    cout << notebook.getName() << ": " << notebook.getPrice() << " cents\n";
}
