#ifndef PROJECT_DELIVERY_H
#define PROJECT_DELIVERY_H

#include <cstddef>
#include <vector>
#include "../../../02_OOP/09_DAO/BookDAO.h"

namespace project {
    using namespace std;
    using namespace course;

    // A request keeps a book copy: it holds no pointers into the DAO vector.
    struct Delivery {
        Book book;
        size_t source;
        size_t target;
    };

    struct Route {
        long long minutes;
        vector<size_t> stops;
    };

    struct CompletedDelivery {
        Delivery delivery;
        Route route;
    };
}

#endif
