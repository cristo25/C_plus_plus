#include "Product.h"
// We report errors with messages, such as invalid_argument for an invalid value.
#include <stdexcept>

using namespace std;
using namespace course;

Product::Product(const string& initialName, int initialPrice)
    : name(initialName), priceCents(initialPrice) {
    // The constructor validates initial state to prevent invalid products.
    if (name.empty() || priceCents < 0) {
        throw invalid_argument("Invalid product");
    }
}

const string& Product::getName() const {
    return name;
}
int Product::getPrice() const {
    return priceCents;
}
