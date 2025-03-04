#include <iostream>
#include "LibraryUtility.hpp"
#include "FileDataSource.hpp"

namespace Library {
	namespace Test {
		class MockLibrary {
		private:
			LibraryUtility library;
		public:
			MockLibrary(const std::string& file) : library(std::make_unique<FileDataSource>(file)) {}
			void runWorkflow() {
                Book book1{ 1, "The Great Gatsby", "F. Scott Fitzgerald" };
                library.addBook(book1);

                const Book* fetchedBook = library.getBook(1);
                if (fetchedBook) std::cout << "Retrieved: " << fetchedBook->toString() << std::endl;

                library.updateBook(1, "name", "The Greatest Gatsby");

                std::cout << "All Books After Update:" << std::endl;
                library.displayAll();

                library.deleteBook(1);
                std::cout << "All Books After Deletion:" << std::endl;
				library.displayAll();
			}
		};
	}
}