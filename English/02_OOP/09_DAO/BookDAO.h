#ifndef COURSE_BOOK_DAO_H
#define COURSE_BOOK_DAO_H

// With quoted we preserve spaces and quotation marks when saving and reading titles.
#include <iomanip>
// We receive an input source: keyboard, file or text in memory.
#include <istream>
// We receive an output destination: screen, file or text in memory.
#include <ostream>
// We read or write text in memory as if it were a file.
#include <sstream>
// We store and work with text using string.
#include <string>
// We use move to transfer data or responsibility for releasing it.
#include <utility>
// We store a collection that can grow using vector.
#include <vector>

namespace course {
    using namespace std;

    struct Book {
        int id;
        string title;
    };

    // DAO: centralizes data access; it does not decide borrowing rules.
    class BookDAO {
        static constexpr int MAX_BOOKS = 10000;
        vector<Book> books;

        static bool validTitle(const string& title) {
            return !title.empty() && title.find_first_of("\r\n") == string::npos;
        }

    public:
        // Search book by book, potentially inspecting the whole catalog. More books may mean more
        // comparisons (O(n), with n books). Return an observer that vector modifications may
        // invalidate.
        const Book* findById(int id) const {
            for (const auto& book : books) {
                if (book.id == id) {
                    return &book;
                }
            }
            return nullptr;
        }
        // Create, read, update and delete form CRUD; the DAO centralizes these operations.
        bool create(const Book& book) {
            if (books.size() >= static_cast<size_t>(MAX_BOOKS)) {
                return false;
            }
            if (book.id <= 0 || !validTitle(book.title) || findById(book.id)) {
                return false;
            }
            books.push_back(book);
            return true;
        }
        bool update(int id, const string& title) {
            if (!validTitle(title)) {
                return false;
            }
            for (auto& book : books) {
                if (book.id == id) {
                    book.title = title;
                    return true;
                }
            }
            return false;
        }
        bool remove(int id) {
            for (auto it = books.begin(); it != books.end(); ++it) {
                if (it->id == id) {
                    books.erase(it);
                    return true;
                }
            }
            return false;
        }
        const vector<Book>& all() const {
            return books;
        }

        bool save(ostream& output) const {
            output << books.size() << '\n';
            for (const auto& book : books) {
                // quoted preserves spaces and quotation marks so the complete title can be
                // restored.
                output << book.id << ' ' << quoted(book.title) << '\n';
            }
            return static_cast<bool>(output);
        }
        bool load(istream& input) {
            // Read a complete snapshot; preserve the previous state if loading fails.
            string line;
            if (!getline(input, line)) {
                return false;
            }
            istringstream header(line);
            int count = 0;
            if (!(header >> count) || count < 0 || count > MAX_BOOKS) {
                return false;
            }
            if (!(header >> ws).eof()) {
                return false;
            }
            BookDAO replacement;
            for (int i = 0; i < count; ++i) {
                if (!getline(input, line)) {
                    return false;
                }
                istringstream row(line);
                Book book{};
                if (!(row >> book.id >> ws) || row.peek() != '"') {
                    return false;
                }
                if (!(row >> quoted(book.title)) || !(row >> ws).eof()) {
                    return false;
                }
                if (!replacement.create(book)) {
                    return false;
                }
            }
            // Replace the catalog only after validating the complete copy.
            books = move(replacement.books);
            return true;
        }
    };

} // namespace course

#endif
