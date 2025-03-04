#include "LibraryUtility.hpp"
#include "Logger.hpp"
#include <algorithm>
#include <iostream>

namespace Library {

    LibraryUtility::LibraryUtility(std::unique_ptr<DataSource> ds) : dataSource(std::move(ds)) {}

    void LibraryUtility::addBook(const Book& book) { 
        dataSource->addBook(book); 
    }
    const Book* LibraryUtility::getBook(const BookIdentifier id) const {
        return dataSource->getBook(id); 
    }
    std::vector<const Book*> LibraryUtility::getBooksByName(const std::string& title) const {
        return dataSource->getBooks("Name", title);
    }
    std::vector<const Book*> LibraryUtility::getBooksByAuthor(const std::string& author) const {
        return dataSource->getBooks("Author", author);
    }
    void LibraryUtility::updateBook(BookIdentifier id, const std::string& fieldName, const std::string& value) {
        dataSource->updateBook(id, fieldName, value);
    }
    void LibraryUtility::deleteBook(BookIdentifier id) {
        dataSource->deleteBook(id); 
    }
    void LibraryUtility::displayAll() {
        auto allBooks = dataSource->getAllBooks();
        std::for_each(allBooks.begin(), allBooks.end(), [](auto book) {
            std::cout << book->toString() << std::endl;
            });
    }

}