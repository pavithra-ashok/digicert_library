#pragma once

#include "Book.hpp"
#include <string>
#include <vector>


namespace Library {
    class DataSource {
    public:
        // Querying
        virtual const Book* getBook(BookIdentifier id) const = 0;
        virtual std::vector<const Book*> getBooks(const std::string& fieldName, const std::string& newValue) const = 0;
        virtual std::vector<const Book*> getAllBooks() const  = 0;
        // Modifiers
        virtual void addBook(const Book&) = 0;
        virtual void updateBook(BookIdentifier id, const std::string& fieldName, const std::string& newValue) = 0;
        virtual void deleteBook(BookIdentifier id) = 0;

        virtual ~DataSource() = default;
    };
}