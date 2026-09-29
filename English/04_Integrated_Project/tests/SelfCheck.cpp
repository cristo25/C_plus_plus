#include "testing/SelfCheck.h"
#include "ui/Console.h"
#include <algorithm>
#include <exception>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace project {
    using namespace std;

    namespace {
        // Test double to provoke a save failure without writing files.
        class RejectingStore : public CatalogStore {
            MemoryStore saved;
        public:
            bool reject = false;
            BookDAO load() const override {
                return saved.load();
            }
            void save(const BookDAO& dao) override {
                if (reject) {
                    throw runtime_error("Simulated save failure");
                }
                saved.save(dao);
            }
        };

        void expect(bool value, const string& message) {
            if (!value) {
                throw logic_error(message);
            }
        }
    }

    int selfCheck(ostream& output) {
        try {
            RejectingStore store;
            Library library(store);
            expect(library.findById(10) == nullptr, "Empty search");
            library.addBook({30, "C++"});
            library.addBook({10, "Book with \"quotes\""});
            library.addBook({20, "POO"});
            {
                const auto view = library.booksSorted();
                expect(view.at(0)->id == 10 && view.at(2)->id == 30, "Sorted view");
            }
            expect(library.findById(20)->title == "POO" && library.findById(21) == nullptr, "Binary search");
            // The shortest route improves a direct path; also check isolated target and source equal to target.
            const auto route = library.map().shortestRoute(0, 4);
            expect(route && route->minutes == 7 && route->stops == vector<size_t>({0, 2, 1, 3, 4}), "Dijkstra");
            expect(!library.map().shortestRoute(0, 5), "Isolated target");
            const auto same = library.map().shortestRoute(2, 2);
            expect(same && same->minutes == 0 && same->stops.size() == 1, "Same building");
            expect(library.map().reachable(0).size() == 5, "BFS");

            library.requestDelivery(10, 0, 4);
            library.requestDelivery(20, 2, 1);
            library.renameBook(10, "New title");
            expect(library.pendingDeliveries().at(0).book.title == "Book with \"quotes\"", "Request independent of catalog");
            const auto first = library.processDelivery();
            const auto second = library.processDelivery();
            expect(first && second && first->delivery.book.id == 10 && second->delivery.book.id == 20, "FIFO");
            expect(!library.processDelivery(), "Empty queue");

            library.removeBook(20);
            expect(library.findById(20) == nullptr && library.undoLast() && library.findById(20) != nullptr, "LIFO");
            auto previous = library.history();
            reverse(previous.begin(), previous.end());
            expect(previous == library.history(true), "Doubly linked list in both directions");

            // Failure must not add the book or consume the previous undo snapshot.
            const auto before = library.booksSorted().size();
            store.reject = true;
            bool rejected = false;
            try {
                library.addBook({40, "Error"});
            } catch (const runtime_error&) {
                rejected = true;
            }
            expect(rejected && library.findById(40) == nullptr && library.booksSorted().size() == before, "Catalog unchanged after failure");
            store.reject = false;
            expect(library.undoLast() && library.findById(10)->title == "Book with \"quotes\"", "Stack unchanged after failure");

            // The interface uses stream references: test invalid input and EOF without a real keyboard.
            istringstream input("abc\n2x\n99\n2\n20\n0\n");
            ostringstream transcript;
            Console console(library, input, transcript);
            console.run();
            expect(transcript.str().find("20 | POO") != string::npos, "Input validation");
            istringstream closed("");
            Console eofConsole(library, closed, transcript);
            eofConsole.run();
            output << "Check passed: catalog, search, stack, queue, list, BFS, Dijkstra and errors.\n";
            return 0;
        } catch (const exception& error) {
            output << "Check failed: " << error.what() << "\n";
            return 1;
        }
    }
}
