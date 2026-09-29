// 2. A struct contains a class; an array contains those structs
//
// We want stock counts as well as products. Record groups a Product with
// a quantity: each drawer compartment contains a complete record with both.
// class and struct can contain each other; their main difference is default
// access. A class enforces product rules and a simple struct groups it with
// a quantity. A function takes Record& to modify the actual array record.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_OOP/08_Headers/Product.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Replace Record& with Record. Predict and explain the printed quantity.

#include <array>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

struct Record {
    Product product;
    int quantity;
};

void receiveOne(Record& record) {
    // Validation prevents negative counts and integer overflow when adding one.
    if (record.quantity < 0 || record.quantity == numeric_limits<int>::max()) {
        throw invalid_argument("Invalid quantity");
    }
    ++record.quantity;
}

int main() {
    array<Record, 2> records{
        Record{Product("Notebook", 300), 2},
        Record{Product("Pencil", 100), 5}
    };

    receiveOne(records.at(0));
    for (const Record& record : records) {
        cout << record.product.getName() << ": " << record.quantity << "\n";
    }
}
