#include "data/CatalogStore.h"
// We read and save files using ifstream and ofstream.
#include <fstream>
// We report errors with messages, such as invalid_argument for an invalid value.
#include <stdexcept>
// We check file-operation failures using error_code.
#include <system_error>
// We use move to transfer data or responsibility for releasing it.
#include <utility>

namespace project {
    using namespace std;
    namespace fs = filesystem;

    MemoryStore::MemoryStore(BookDAO initial) : saved(move(initial)) {
    }

    BookDAO MemoryStore::load() const {
        return saved;
    }

    void MemoryStore::save(const BookDAO& dao) {
        saved = dao;
    }

    FileStore::FileStore(fs::path file) : file(move(file)) {
        if (this->file.empty() || this->file.filename().empty()) {
            throw invalid_argument("Invalid catalog path");
        }
    }

    BookDAO FileStore::load() const {
        fs::path source = file;
        fs::path backup = file;
        backup += ".bak";
        // If replacement was interrupted between renames, the backup retains the previous catalog.
        if (!fs::exists(source) && fs::exists(backup)) {
            source = backup;
        }
        if (!fs::exists(source)) {
            return {};
        }
        if (!fs::is_regular_file(source)) {
            throw runtime_error("The catalog must be a regular file");
        }
        ifstream input(source);
        BookDAO result;
        if (!input || !result.load(input)) {
            throw runtime_error("Invalid catalog: the file is preserved for inspection");
        }
        input >> ws;
        if (!input.eof() || input.bad()) {
            throw runtime_error("The catalog contains extra data or a read error");
        }
        return result;
    }

    void FileStore::save(const BookDAO& dao) {
        // ponytail: we write from one running program; for several simultaneous writers we use a
        // database that coordinates changes.
        if (!file.parent_path().empty()) {
            fs::create_directories(file.parent_path());
        }
        if (fs::exists(file) && !fs::is_regular_file(file)) {
            throw runtime_error("The catalog must be a regular file");
        }
        fs::path temporary = file;
        temporary += ".tmp";
        fs::path backup = file;
        backup += ".bak";
        // Write and close a complete snapshot before touching the previous catalog.
        ofstream output(temporary, ios::trunc);
        if (!output || !dao.save(output)) {
            throw runtime_error("Could not write the temporary catalog");
        }
        output.close();
        if (!output) {
            throw runtime_error("Could not close the temporary catalog");
        }

        const bool hadPrevious = fs::exists(file);
        if (hadPrevious) {
            fs::remove(backup);
            fs::rename(file, backup);
        }
        try {
            fs::rename(temporary, file);
        } catch (...) {
            if (hadPrevious) {
                error_code error;
                fs::rename(backup, file, error);
                if (error) {
                    throw runtime_error("Replacement failed; the previous catalog remains in the .bak file");
                }
            }
            throw;
        }
        // The new catalog is installed; an undeletable backup does not invalidate the save.
        error_code error;
        fs::remove(backup, error);
    }
}
