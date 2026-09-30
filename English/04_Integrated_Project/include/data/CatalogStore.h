#ifndef PROJECT_CATALOG_STORE_H
#define PROJECT_CATALOG_STORE_H

// We handle paths, folders and file renaming.
#include <filesystem>
#include "../../../02_OOP/09_DAO/BookDAO.h"

namespace project {
    using namespace std;
    using namespace course;

    // Two actual variants: an in-memory demonstration session and a persistent file catalog.
    class CatalogStore {
    public:
        virtual ~CatalogStore() = default;
        virtual BookDAO load() const = 0;
        virtual void save(const BookDAO& dao) = 0;
    };

    class MemoryStore : public CatalogStore {
        BookDAO saved;
    public:
        explicit MemoryStore(const BookDAO& initial = {});
        BookDAO load() const override;
        void save(const BookDAO& dao) override;
    };

    class FileStore : public CatalogStore {
        filesystem::path file;
    public:
        explicit FileStore(const filesystem::path& file);
        BookDAO load() const override;
        void save(const BookDAO& dao) override;
    };
}

#endif
