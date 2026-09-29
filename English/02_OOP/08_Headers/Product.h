#ifndef COURSE_PRODUCT_H
#define COURSE_PRODUCT_H

#include <string>

namespace course {
    using namespace std;

    class Product {
        string name;
        int priceCents;

    public:
        Product(const string& initialName, int initialPrice);
        const string& getName() const;
        int getPrice() const;
    };

} // namespace course

#endif
