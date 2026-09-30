// Entry point: configure the store and connect service and interface.
//
// We will build a campus library and route application. From a menu we add books, search by id,
// organize deliveries and inspect routes. We divide the work: Console talks to the user, Library
// applies rules, the DAO stores books and CampusMap calculates routes. We reuse course headers to
// connect classes, lists, stacks, queues, searches and graphs. We can follow a request from entry
// to recording; each file handles part of that journey. The project guide explains the pieces with
// code fragments.
//

#include "ui/Console.h"
#include "testing/SelfCheck.h"
// We catch errors through exception and read their message with what().
#include <exception>
// We handle paths, folders and file renaming.
#include <filesystem>
#include <iostream>
// We use unique_ptr to release its managed object automatically.
#include <memory>
// We report errors with messages, such as invalid_argument for an invalid value.
#include <stdexcept>
// We store and work with text using string.
#include <string>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace project;

namespace {
    vector<filesystem::path> readArguments(int argc, char* argv[]) {
        vector<filesystem::path> result;
        for (int index = 0; index < argc; ++index) {
            result.emplace_back(filesystem::u8path(argv[index]));
        }
        return result;
    }
}

int main(int argc, char* argv[]) {
    try {
        const auto arguments = readArguments(argc, argv);
        bool demo = false;
        bool checking = false;
        filesystem::path dataFile = "data/catalog.txt";
        bool customFile = false;
        for (size_t index = 1; index < arguments.size(); ++index) {
            const string option = arguments.at(index).u8string();
            if (option == "--self-test") {
                checking = true;
            } else if (option == "--demo") {
                demo = true;
            } else if (option == "--data" && index + 1 < arguments.size()) {
                ++index;
                dataFile = arguments.at(index);
                customFile = true;
            } else if (option == "--help") {
                cout << "Usage: library.exe [--demo | --data PATH | --self-test]\n";
                return 0;
            } else {
                throw invalid_argument("Unknown option or missing path after --data");
            }
        }
        if ((demo && customFile) || (checking && (demo || customFile))) {
            throw invalid_argument("Use only one mode: normal, --demo, --data or --self-test");
        }
        if (checking) {
            return selfCheck(cout);
        }

        // The base pointer owns one of two implementations; virtual selects load/save at runtime.
        unique_ptr<CatalogStore> store;
        if (demo) {
            BookDAO initial;
            if (!initial.create({10, "C++ fundamentals"}) || !initial.create({30, "Data structures"}) ||
                !initial.create({20, "Object-oriented programming"})) {
                throw logic_error("Could not prepare the demonstration catalog");
            }
            store = make_unique<MemoryStore>(initial);
            cout << "Demo mode: the catalog lives in memory.\n";
        } else {
            store = make_unique<FileStore>(dataFile);
            cout << "Catalog file: " << dataFile.u8string() << "\n";
        }
        // Declare the store first so it is destroyed last; borrowed references remain valid.
        Library library(*store);
        Console console(library, cin, cout);
        console.run();
        return 0;
    } catch (const exception& error) {
        cerr << "Error: " << error.what() << "\n";
        return 1;
    }
}
