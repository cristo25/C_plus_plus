#include "ui/Console.h"
#include <exception>
#include <limits>
#include <optional>
#include <sstream>
#include <string>

namespace project {
    using namespace std;

    namespace {
        // Read a whole line: 12abc is not accepted as 12, and EOF ends the session.
        optional<int> readNumber(istream& input, ostream& output, const string& prompt,
                                 int minimum, int maximum) {
            string line;
            while (true) {
                output << prompt << flush;
                if (!getline(input, line)) {
                    return nullopt;
                }
                istringstream row(line);
                int value = 0;
                if (row >> value && (row >> ws).eof() && value >= minimum && value <= maximum) {
                    return value;
                }
                output << "Enter a complete integer within the specified range.\n";
            }
        }

        optional<string> readTitle(istream& input, ostream& output) {
            string line;
            output << "Title (maximum 200 bytes): " << flush;
            if (!getline(input, line)) {
                return nullopt;
            }
            return line;
        }

        void showBooks(const Library& library, ostream& output) {
            const auto view = library.booksSorted();
            if (view.empty()) {
                output << "Empty catalog. Use add book.\n";
            }
            for (const Book* book : view) {
                output << book->id << " | " << book->title << "\n";
            }
        }

        void showRoute(const Route& route, const CampusMap& map, ostream& output) {
            for (size_t index = 0; index < route.stops.size(); ++index) {
                if (index != 0) {
                    output << " -> ";
                }
                output << map.names().at(route.stops.at(index));
            }
            output << " | " << route.minutes << " minutes\n";
        }
    }

    Console::Console(Library& library, istream& input, ostream& output)
        : library(library), input(input), output(output) {
    }

    void Console::run() {
        output << "CAMPUS LIBRARY AND ROUTES\nCatalog changes are saved when committed. Deliveries and history last for this session.\n";
        while (true) {
            output << "\n1 Catalog | 2 Find ID | 3 Add book\n"
                   << "4 Rename book | 5 Remove book | 6 Undo change\n"
                   << "7 Request delivery | 8 Process next | 9 View pending\n"
                   << "10 History | 11 Map and BFS | 0 Exit\n";
            const auto choice = readNumber(input, output, "Option: ", 0, 11);
            if (!choice || *choice == 0) {
                output << "Session ended.\n";
                return;
            }
            try {
                switch (*choice) {
                case 1:
                    showBooks(library, output);
                    break;
                case 2: {
                    const auto id = readNumber(input, output, "ID: ", 1, numeric_limits<int>::max());
                    if (!id) {
                        return;
                    }
                    const Book* book = library.findById(*id);
                    if (book != nullptr) {
                        output << book->id << " | " << book->title << "\n";
                    } else {
                        output << "Book not found.\n";
                    }
                    break;
                }
                case 3:
                case 4: {
                    const auto id = readNumber(input, output, "ID: ", 1, numeric_limits<int>::max());
                    if (!id) {
                        return;
                    }
                    const auto title = readTitle(input, output);
                    if (!title) {
                        return;
                    }
                    if (*choice == 3) {
                        library.addBook(Book{*id, *title});
                    } else {
                        library.renameBook(*id, *title);
                    }
                    output << "Change committed.\n";
                    break;
                }
                case 5: {
                    const auto id = readNumber(input, output, "ID: ", 1, numeric_limits<int>::max());
                    if (!id) {
                        return;
                    }
                    library.removeBook(*id);
                    output << "Change committed.\n";
                    break;
                }
                case 6:
                    if (library.undoLast()) {
                        output << "Change committed.\n";
                    } else {
                        output << "There are no changes to undo.\n";
                    }
                    break;
                case 7: {
                    const auto id = readNumber(input, output, "ID: ", 1, numeric_limits<int>::max());
                    if (!id) {
                        return;
                    }
                    for (size_t index = 0; index < library.map().names().size(); ++index) {
                        output << index << " | " << library.map().names().at(index) << "\n";
                    }
                    const int maximum = static_cast<int>(library.map().names().size()) - 1;
                    const auto source = readNumber(input, output, "Source building: ", 0, maximum);
                    if (!source) {
                        return;
                    }
                    const auto target = readNumber(input, output, "Target building: ", 0, maximum);
                    if (!target) {
                        return;
                    }
                    library.requestDelivery(*id, static_cast<size_t>(*source), static_cast<size_t>(*target));
                    output << "Request added to the queue.\n";
                    break;
                }
                case 8: {
                    const auto result = library.processDelivery();
                    if (!result) {
                        output << "There are no pending deliveries.\n";
                        break;
                    }
                    output << result->delivery.book.title << "\n";
                    showRoute(result->route, library.map(), output);
                    break;
                }
                case 9: {
                    const auto pending = library.pendingDeliveries();
                    if (pending.empty()) {
                        output << "There are no pending deliveries.\n";
                    }
                    for (const Delivery& delivery : pending) {
                        output << delivery.book.id << " | " << delivery.book.title << " | "
                               << library.map().names().at(delivery.source) << " -> "
                               << library.map().names().at(delivery.target) << "\n";
                    }
                    break;
                }
                case 10: {
                    const auto reverseOrder = readNumber(input, output, "Order: 0 chronological, 1 reverse: ", 0, 1);
                    if (!reverseOrder) {
                        return;
                    }
                    const auto events = library.history(*reverseOrder == 1);
                    if (events.empty()) {
                        output << "Empty history.\n";
                    }
                    for (const string& message : events) {
                        output << message << "\n";
                    }
                    break;
                }
                case 11: {
                    const auto& map = library.map();
                    for (size_t source = 0; source < map.names().size(); ++source) {
                        output << source << " | " << map.names().at(source) << ": ";
                        for (const auto& edge : map.map().neighbors(source)) {
                            output << edge.destination << " (" << edge.weight << " minutes) ";
                        }
                        output << "\n";
                    }
                    output << "BFS from Library: ";
                    for (size_t index : map.reachable(0)) {
                        output << index << ' ';
                    }
                    output << "\n";
                    break;
                }
                }
            } catch (const exception& error) {
                // The session continues after invalid data or a save failure; the service layer protects the catalog.
                output << "Error: " << error.what() << "\n";
            }
        }
    }
}
