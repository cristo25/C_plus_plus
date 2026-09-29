#include "Product.h"
#include <stdexcept>

using namespace std;
using namespace course;

Product::Product(const string& initialName, int initialPrice)
    : name(initialName), priceCents(initialPrice) {
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
