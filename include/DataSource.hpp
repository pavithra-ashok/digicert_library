#pragma once

#include "Book.hpp"
#include <string>
#include <vector>


namespace Library {
/**
 * @file DataSource.hpp
 * @brief Abstract interface for a data source in the library system.
 *
 * This class defines the interface for interacting with a data source that
 * stores and manages book records. Concrete implementations, such as
 * a file-based or database-backed data source, must inherit from this class
 * and implement the virtual functions.
 * 
 * The time complexity and space complexity of every operation needs to be defined by the concrete implementations.
 * Every concrete implementation should also define the trade-offs to help the client in deciding the applicability.
 * Use the following template:
 * 
 * Time-complexity of various operations:
 * Trade-offs:
 * 
 */

    class DataSource {
    public:
        // Querying
        virtual const Book& getBook(BookIdentifier id) const = 0;
        virtual std::vector<std::reference_wrapper<const Book>> getBooks(const std::string& fieldName, const std::string& newValue) const = 0;
        virtual std::vector<std::reference_wrapper<const Book>> getAllBooks() const = 0;
        // Modifiers
        virtual void addBook(const Book&) = 0;
        virtual void updateBook(BookIdentifier id, const std::string& fieldName, const std::string& newValue) = 0;
        virtual void deleteBook(BookIdentifier id) = 0;

        virtual ~DataSource() = default;
    };
}