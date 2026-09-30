// 2. A struct contains a class; an array contains those structs
//
// We will add available quantity to each product. With struct Record we group a Product and an
// integer quantity, then store several Record cards in an array. We can picture a compartment
// holding the product and a stock label. With records[0].product we reach the object, and with
// records[0].quantity the number. receiveOne takes Record& to change the original card: removing &
// would change only a copy.
//
// Practice: We will store records with products and quantities.
// - We will create a struct with Product and quantity, then store several records.
// - We will change one quantity through a function with a reference.

#include <iostream>
// We use numeric_limits to check the largest allowed integer before adding.
#include <limits>
// We report errors with messages, such as invalid_argument for an invalid value.
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
    Record records[2]{
        Record{Product("Notebook", 300), 2},
        Record{Product("Pencil", 100), 5}
    };

    receiveOne(records[0]);
    for (const Record& record : records) {
        cout << record.product.getName() << ": " << record.quantity << "\n";
    }
}
