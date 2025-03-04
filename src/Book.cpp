#include "Book.hpp"

#include <sstream>

namespace Library {

    Book Book::fromString(const std::string& data) {
        std::istringstream stream(data);
        Book book;
        stream >> book.id;
        std::getline(stream, book.name, ',');
        std::getline(stream, book.author);
        return book;
    }

    std::string Book::toString() const {
        return std::to_string(id) + "," + name + "," + author;
    }
}