
#include "DataSource.hpp"
#include <memory>
#include <vector>

namespace Library {
class LibraryUtility {
private:
    std::unique_ptr<DataSource> dataSource;
public:
    LibraryUtility(std::unique_ptr<DataSource> ds);
    void addBook(const Book& book);

    const Book* getBook(const BookIdentifier bookId) const;
    //std::vector<Book*> getBook(const std::string& fieldName, const std::string& value);
    std::vector<const Book*> getBooksByName(const std::string& title) const;
    std::vector<const Book*> getBooksByAuthor(const std::string& author) const;

    void updateBook(BookIdentifier id, const std::string& fieldName, const std::string& value);
    void deleteBook(BookIdentifier id);

    void displayAll();
};
}