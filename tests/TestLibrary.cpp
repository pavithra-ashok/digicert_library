#include <iostream>
#include "LibraryService.hpp"
#include "InMemoryDataSource.cpp"
#include <cassert>

namespace Library {
	namespace Test {
		/**
		* @file : TestLibrary
		* @brief : Contains the tests for LibraryService
		*/
		class TestLibrary {
		private:
			LibraryService library;
		public:
			TestLibrary() : library(std::make_unique<InMemoryDataSource>()) {}

			void runAddBookTests() {
				// Basic case
				std::cout << "Test basic case" << std::endl;
				Book book1{ 1, "Sapiens", "Yuval Noah Harari" };
				library.addBook(book1);
				std::cout << "Added a single book successfully" << std::endl;

				// Duplicate book
				std::cout << "Test duplicate book" << std::endl;
				Book book2{ 1, "Homo Deus", "Yuval Noah Harari" };
				library.addBook(book2);
				auto& book = library.getBook(1);
				assert(book.name == "Homo Deus");
				std::cout << "Tested duplicate book addition" << std::endl;

				// Pending cases
				// Incomplete book details
			}

			void runTests() {
				std::cout << "Running tests for adding a book" << std::endl;
				runAddBookTests();
			}
		};
	}
}