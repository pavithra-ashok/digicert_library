#include "DataSource.hpp"
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

namespace Library {
    namespace Test {
        /**
        * @file : InMemoryDataSource
        * @brief : Primarily used for testing.
        * Does not contain persistent storage.
        * All the operations are constant time.
        * Provides a clean starting point for tests.
        */
        class InMemoryDataSource : public DataSource {
        private:
            std::unordered_map<BookIdentifier, Book> books;
        public:

            void addBook(const Book& book) {
                books[book.id] = book;
            }

            const Book& getBook(BookIdentifier id) const {
                auto it = books.find(id);
                if (it != books.end()) {
                    return it->second;
                }
                throw std::runtime_error("Book not found with ID: " + std::to_string(id));
            }

            std::vector<std::reference_wrapper<const Book>> getBooks(const std::string& fieldName, const std::string& value) const {
                std::vector<std::reference_wrapper<const Book>> matchingBooks;
                for (const auto& pair : books) {
                    if ((fieldName == "name" && pair.second.name == value) ||
                        (fieldName == "author" && pair.second.author == value)) {
                        matchingBooks.push_back(std::cref(pair.second));
                    }
                }
                
                return matchingBooks;
            }


            std::vector<std::reference_wrapper<const Book>> getAllBooks() const {
                std::vector<std::reference_wrapper<const Book>> allBooks;
                allBooks.reserve(books.size());
                for (const auto& pair : books) {
                    allBooks.push_back(std::cref(pair.second));
                }


                return allBooks;
            }

            void updateBook(BookIdentifier id, const std::string& fieldName, const std::string& newValue) {
                auto it = books.find(id);
                if (it != books.end()) {
                    if (fieldName == "name") it->second.name = newValue;
                    else if (fieldName == "author") it->second.author = newValue;
                }
            }

            void deleteBook(BookIdentifier id) {
                books.erase(id);
            }

        };
    }
}// namespace Library