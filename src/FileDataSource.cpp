#include "FileDataSource.hpp"
#include "Logger.hpp" 

namespace Library {
    FileDataSource::FileDataSource(const std::string& file) : filename(file) {
        LOG_INFO("Initializing File Data Source with file:" + filename);
        loadFromFile();
    }

    void FileDataSource::loadFromFile() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            LOG_ERROR("Unable to open file " + filename);
            return;
        }

        books.clear();
        std::string line;
        while (std::getline(file, line)) {
            Book book = Book::fromString(line);
            books[book.id] = std::make_unique<Book>(book);
        }
        LOG_INFO("Loaded Files successfully");
        file.close();
    }

    void FileDataSource::saveToFile() {
        std::ofstream file(filename, std::ios::trunc);
        for (const auto& pair : books) {
            file << pair.second->toString() << "\n";
        }
        file.close();
        LOG_INFO("Updated data successfully");
    }

    void FileDataSource::addBook(const Book& book) {
        books[book.id] = std::make_unique<Book>(book);
        saveToFile();
        LOG_INFO("Added new Data" + book.toString());
    }



    const Book* FileDataSource::getBook(BookIdentifier id) const {
        auto it = books.find(id);
        if (it != books.end()) {
            return it->second.get();
        }
        LOG_ERROR("No book found with id: " + id);
        return nullptr;
    }

    std::vector<const Book*> FileDataSource::getBooks(const std::string& fieldName, const std::string& value) const {
        std::vector<const Book*> matchingBooks;
        for (const auto& pair : books) {
            if ((fieldName == "name" && pair.second->name == value) ||
                (fieldName == "author" && pair.second->author == value)) {
                matchingBooks.push_back(pair.second.get());
            }
        }
        if (matchingBooks.empty()) {
            LOG_ERROR("No book found with : " + fieldName + "  "+ value);
        }
        return matchingBooks;
    }

    std::vector<const Book*> FileDataSource::getAllBooks() const {
        std::vector<const Book*> allBooks;
        for (const auto& pair : books) {
            allBooks.push_back(pair.second.get());
        }
        if (allBooks.empty()) {
            LOG_ERROR("No books in datastore");
        }
        return allBooks;
    }

    void FileDataSource::updateBook(BookIdentifier id, const std::string& fieldName, const std::string& newValue) {
        auto it = books.find(id);
        if (it != books.end()) {
            if (fieldName == "name") it->second->name = newValue;
            else if (fieldName == "author") it->second->author = newValue;
            saveToFile();
        }
        else {
            LOG_ERROR("No book found with id: " + id);
        }
    }

    void FileDataSource::deleteBook(BookIdentifier id) {
        books.erase(id);
        saveToFile();
        LOG_INFO("Deleted book with id " + id);
    }

} // namespace Library