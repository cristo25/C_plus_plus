// The header is the menu: it declares available requests; the .cpp implements them.
#ifndef COURSE_PRODUCT_H
#define COURSE_PRODUCT_H

#include <string>

namespace course {
    using namespace std;

    class Product {
        string name;
        int priceCents;

    public:
        // The const reference avoids a copy; trailing const allows queries on const objects.
        Product(const string& initialName, int initialPrice);
        const string& getName() const;
        int getPrice() const;
    };

} // namespace course

#endif
