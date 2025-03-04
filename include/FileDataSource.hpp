#pragma once
#include "DataSource.hpp"
#include <fstream>
#include <sstream>
#include <unordered_map>

namespace Library {

    class FileDataSource : public DataSource {
    private:
        std::string filename;
        std::unordered_map<BookIdentifier, std::unique_ptr<Book>> books;
        void loadFromFile();
        void saveToFile();
    public:
        FileDataSource(const std::string& file);
        void addBook(const Book&) override;
        const Book* getBook(BookIdentifier id) const override;
        std::vector<const Book*> getBooks(const std::string& fieldName, const std::string& newValue) const override;
        std::vector<const Book*> getAllBooks() const override;
        void updateBook(BookIdentifier id, const std::string& fieldName, const std::string& newValue) override;
        void deleteBook(BookIdentifier id) override;
    };


} // namespace Library