#include "LibraryService.hpp"
#include "Logger.hpp"
#include <algorithm>
#include <iostream>

namespace Library {

    LibraryService::LibraryService(std::unique_ptr<DataSource> ds) : dataSource(std::move(ds)) {}

    void LibraryService::addBook(const Book& book) { 
        dataSource->addBook(book); 
    }
    const Book& LibraryService::getBook(const BookIdentifier id) const {
        return dataSource->getBook(id); 
    }
    std::vector<std::reference_wrapper<const Book>> LibraryService::getBooksByName(const std::string& title) const {
        return dataSource->getBooks("name", title);
    }
    std::vector<std::reference_wrapper<const Book>> LibraryService::getBooksByAuthor(const std::string& author) const {
        return dataSource->getBooks("author", author);
    }
    void LibraryService::updateBook(BookIdentifier id, const std::string& fieldName, const std::string& value) {
        dataSource->updateBook(id, fieldName, value);
    }
    void LibraryService::deleteBook(BookIdentifier id) {
        dataSource->deleteBook(id); 
    }
    void LibraryService::displayAll() {
        for (const auto& bookRef : dataSource->getAllBooks()) {
            std::cout << bookRef.get().toString() << std::endl;
        }
    }

}