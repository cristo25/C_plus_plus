// Entry point: configure the store and connect service and interface.
// Compile from the project root with the README.md command. --self-test runs the check.
#include "ui/Console.h"
#include "testing/SelfCheck.h"
#include <exception>
#include <filesystem>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <shellapi.h>
#endif

using namespace std;
using namespace project;

namespace {
    vector<filesystem::path> readArguments(int argc, char* argv[]) {
        vector<filesystem::path> result;
#ifdef _WIN32
        // Native wide arguments preserve Unicode paths that narrow argv can lose.
        (void)argc;
        (void)argv;
        int count = 0;
        unique_ptr<wchar_t*, decltype(&LocalFree)> arguments(
            CommandLineToArgvW(GetCommandLineW(), &count), &LocalFree);
        if (!arguments) {
            throw runtime_error("Could not read command-line arguments");
        }
        for (int index = 0; index < count; ++index) {
            result.emplace_back(arguments.get()[index]);
        }
#else
        for (int index = 0; index < argc; ++index) {
            result.emplace_back(argv[index]);
        }
#endif
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
            store = make_unique<MemoryStore>(move(initial));
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
