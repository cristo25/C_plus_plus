#include "services/Library.h"
#include "../../../03_DSA/10_Searching/Searches.h"
// We use sort to sort or change data order.
#include <algorithm>
// We use numeric_limits to check the largest allowed integer before adding.
#include <limits>
// We report errors with messages, such as invalid_argument for an invalid value.
#include <stdexcept>
// We use swap to exchange catalogs after saving.
#include <utility>

namespace project {
    using namespace std;

    Library::Library(CatalogStore& store) : store(store), dao(store.load()) {
        for (const Book& book : dao.all()) {
            validateTitle(book.title);
        }
    }

    void Library::validateTitle(const string& title) {
        bool hasText = false;
        // We look for at least one character that is not a space.
        for (char character : title) {
            if (character != ' ') {
                hasText = true;
            }
        }
        if (!hasText || title.size() > 200) {
            throw invalid_argument("The title must contain text and use at most 200 bytes");
        }
        for (unsigned char character : title) {
            if (character < 32 || character == 127) {
                throw invalid_argument("The title cannot contain control characters");
            }
        }
    }

    vector<const Book*> Library::booksSorted() const {
        vector<const Book*> view;
        for (const Book& book : dao.all()) {
            view.push_back(&book);
        }
        // Sort read-only cards without rearranging the DAO owning vector.
        sort(view.begin(), view.end(), [](const Book* left, const Book* right) {
            return left->id < right->id;
        });
        return view;
    }

    const Book* Library::findById(int id) const {
        const auto view = booksSorted();
        vector<int> ids;
        for (const Book* book : view) {
            ids.push_back(book->id);
        }
        // Reuse the course search: it requires sorted IDs. The view lasts for this query.
        const auto position = binarySearch(ids, id);
        if (!position) {
            return nullptr;
        }
        return view[*position];
    }

    void Library::record(const string& message) {
        if (events.size() >= static_cast<size_t>(numeric_limits<int>::max())) {
            throw overflow_error("The history exceeds its index range");
        }
        const int index = static_cast<int>(events.size());
        events.push_back(message);
        try {
            order.append(index);
        } catch (...) {
            events.pop_back();
            throw;
        }
    }

    void Library::commit(BookDAO& candidate, const string& message) {
        // We keep a copy so we can undo the change. If saving fails, we keep the previous books.
        undo.push(dao);
        try {
            store.save(candidate);
        } catch (...) {
            undo.pop();
            throw;
        }
        swap(dao, candidate);
        record(message);
    }

    void Library::addBook(const Book& book) {
        validateTitle(book.title);
        BookDAO candidate = dao;
        if (!candidate.create(book)) {
            throw invalid_argument("Nonpositive or duplicate ID, or the 10000-book limit was reached");
        }
        commit(candidate, "Book added: " + to_string(book.id));
    }

    void Library::renameBook(int id, const string& title) {
        validateTitle(title);
        BookDAO candidate = dao;
        if (!candidate.update(id, title)) {
            throw invalid_argument("That book ID does not exist");
        }
        commit(candidate, "Title updated: " + to_string(id));
    }

    void Library::removeBook(int id) {
        BookDAO candidate = dao;
        if (!candidate.remove(id)) {
            throw invalid_argument("That book ID does not exist");
        }
        commit(candidate, "Book removed: " + to_string(id));
    }

    bool Library::undoLast() {
        if (undo.empty()) {
            return false;
        }
        BookDAO previous = undo.top();
        store.save(previous);
        swap(dao, previous);
        undo.pop();
        record("Last catalog change undone");
        return true;
    }

    void Library::requestDelivery(int id, size_t source, size_t target) {
        const Book* book = findById(id);
        if (book == nullptr) {
            throw invalid_argument("That book ID does not exist");
        }
        if (!network.shortestRoute(source, target)) {
            throw invalid_argument("There is no route between those buildings");
        }
        // Copy the book before any future catalog mutation. The request is a complete copy.
        pending.push(Delivery{*book, source, target});
        record("Delivery requested for book: " + to_string(id));
    }

    optional<CompletedDelivery> Library::processDelivery() {
        if (pending.empty()) {
            return nullopt;
        }
        const Delivery& delivery = pending.front();
        const auto route = network.shortestRoute(delivery.source, delivery.target);
        if (!route) {
            throw logic_error("The map no longer permits completing the request");
        }
        CompletedDelivery result{delivery, *route};
        record("Delivery completed for book: " + to_string(delivery.book.id));
        pending.pop();
        return result;
    }

    vector<Delivery> Library::pendingDeliveries() const {
        // Inspecting pending requests does not consume the original queue: traverse a copy.
        auto snapshot = pending;
        vector<Delivery> result;
        while (!snapshot.empty()) {
            result.push_back(snapshot.front());
            snapshot.pop();
        }
        return result;
    }

    vector<string> Library::history(bool reverseOrder) const {
        const auto ids = reverseOrder ? order.reversed() : order.values();
        vector<string> result;
        for (int index : ids) {
            result.push_back(events[static_cast<size_t>(index)]);
        }
        return result;
    }

    const CampusMap& Library::map() const {
        return network;
    }
}
