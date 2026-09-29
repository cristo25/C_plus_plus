#ifndef PROJECT_LIBRARY_H
#define PROJECT_LIBRARY_H

#include <optional>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "data/CatalogStore.h"
#include "services/CampusMap.h"
#include "../../../03_DSA/03_Linked_Lists/02_Doubly_Linked/DoublyLinkedList.h"

namespace project {
    using namespace std;
    using namespace course;

    class Library {
        // The store must outlive Library; the other members belong to this class.
        CatalogStore& store;
        BookDAO dao;
        CampusMap network;
        queue<Delivery> pending;
        stack<BookDAO> undo;
        // Nodes hold stable indexes, rather than addresses that vector growth could invalidate.
        vector<string> events;
        DoublyLinkedList order;

        void record(const string& message);
        void commit(BookDAO candidate, const string& message);
        static void validateTitle(const string& title);
    public:
        explicit Library(CatalogStore& store);
        vector<const Book*> booksSorted() const;
        const Book* findById(int id) const;
        void addBook(const Book& book);
        void renameBook(int id, const string& title);
        void removeBook(int id);
        bool undoLast();
        void requestDelivery(int id, size_t source, size_t target);
        optional<CompletedDelivery> processDelivery();
        vector<Delivery> pendingDeliveries() const;
        vector<string> history(bool reverseOrder = false) const;
        const CampusMap& map() const;
    };
}

#endif
