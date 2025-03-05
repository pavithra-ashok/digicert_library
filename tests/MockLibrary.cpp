#include <iostream>
#include "LibraryService.hpp"
#include "FileDataSource.hpp"

namespace Library {
	namespace Test {
		/**
		* @file : MockLibrary
		* @brief : Shows the ideal,sample workflow using LibraryService
		*/
		class MockLibrary {
		private:
			LibraryService library;
		public:
			MockLibrary() : library(std::make_unique<FileDataSource>("library_data.txt")) {}
			void runWorkflow() {
				Book book1{ 1, "Sapien", "Yuval Noah Harari" };
				library.addBook(book1);

				auto& fetchedBook = library.getBook(1);
				std::cout << "Retrieved: " << fetchedBook.toString() << std::endl;
				std::cout << "Retrieve using Author: ";
				for (const auto& bookRef : library.getBooksByAuthor("Yuval Noah Harari")) {
					std::cout << bookRef.get().toString() << std::endl;
				}
				library.updateBook(1, "name", "Sapiens");
				std::cout << "Updated and retrieved using name:" << std::endl;
				for (const auto& bookRef : library.getBooksByName("Sapiens")) {
					std::cout << bookRef.get().toString() << std::endl;
				}
				

				library.deleteBook(1);
				std::cout << "All Books After Deletion:" << std::endl;
				library.displayAll();
			}
		};
	}
}