#pragma once

#include "DataSource.hpp"
#include <memory>
#include <vector>

namespace Library {
	/**
	 * @file LibraryService.hpp
	 * @brief Provides high-level utility functions for managing books in the library system.
	 *
	 * This class serves as a bridge between the application logic and the data source.
	 * It provides the CRUD capabilities and display.
	 * The time complexity of the operations depend on the data sources used.
	 * 
	 * For Debugging:
	 * Use "Logger::enableLogging()" to enable the logger. 
	 */
	class LibraryService {
	private:
		std::unique_ptr<DataSource> dataSource;
	public:
		LibraryService(std::unique_ptr<DataSource> ds);
		
		void addBook(const Book& book);

		/**
		* Design Decision: All the querying operations return references instead of objects.
		* Advantage: Operations are swifter as it does not require unnecessary copies.
		* Risk: The references might not be valid if the books were deleted.
		*/
		const Book& getBook(const BookIdentifier bookId) const;
		std::vector<std::reference_wrapper<const Book>> getBooksByName(const std::string& title) const;
		std::vector<std::reference_wrapper<const Book>> getBooksByAuthor(const std::string& author) const;

		void updateBook(BookIdentifier id, const std::string& fieldName, const std::string& value);
		void deleteBook(BookIdentifier id);

		void displayAll();
	};
}