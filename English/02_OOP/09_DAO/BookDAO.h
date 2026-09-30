#ifndef COURSE_BOOK_DAO_H
#define COURSE_BOOK_DAO_H

// We receive an input source: keyboard, file or text in memory.
#include <istream>
// We receive an output destination: screen, file or text in memory.
#include <ostream>
// We read or write text in memory as if it were a file.
#include <sstream>
// We store and work with text using string.
#include <string>
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
        // We search one book at a time. A larger catalog can take more comparisons.
        // The address we find becomes unusable if we later change the vector.
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
                // Use one line for the number and another for the title to keep its spaces.
                output << book.id << '\n' << book.title << '\n';
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
            char extra;
            if (header >> extra) {
                return false;
            }
            BookDAO replacement;
            for (int i = 0; i < count; ++i) {
                if (!getline(input, line)) {
                    return false;
                }
                istringstream number(line);
                int id;
                if (!(number >> id) || number >> extra) {
                    return false;
                }
                string title;
                if (!getline(input, title)) {
                    return false;
                }
                if (!replacement.create({id, title})) {
                    return false;
                }
            }
            // Replace the catalog only after validating the complete copy.
            books = replacement.books;
            return true;
        }
    };

} // namespace course

#endif
