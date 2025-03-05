#pragma once
#include "DataSource.hpp"
#include <fstream>
#include <sstream>
#include <unordered_map>

namespace Library {
	/**
	 * @file FileDataSource.hpp
	 * @brief Concrete implementation of DataSource using file storage.
	 *
	 * This class provides a file-based implementation of the DataSource interface.
	 * Uses an in-memory map  to support efficient lookups.
	 * 
	 * Trade-offs:
	 * Good for querying based on identifiers
	 * All modifying operations are linear time since it requires a file update.
	 * 
	 * Potential Optimisations:
	 * Update the file after 'k' operations.
	 * 
	 */

	class FileDataSource : public DataSource {
	private:
		std::string filename;
		std::unordered_map<BookIdentifier, Book> books;
		void loadFromFile();
		void saveToFile();
	public:
		
		FileDataSource(const std::string& file);
		// Time Complexity: O(n)
		/**
		* Adds the book
		* Note: If the book is already present, the book gets updated.
		*/
		void addBook(const Book&) override;
		// Time Complexity: O(1)
		const Book& getBook(BookIdentifier id) const override;
		// Time Complexity: O(n)
		std::vector<std::reference_wrapper<const Book>> getBooks(const std::string& fieldName, const std::string& newValue) const override;
		// Time Complexity : O(n)
		std::vector<std::reference_wrapper<const Book>> getAllBooks() const override;
		// Time Complexity : O(n)
		void updateBook(BookIdentifier id, const std::string& fieldName, const std::string& newValue) override;
		// Time Complexity : O(n)
		void deleteBook(BookIdentifier id) override;
	};


} // namespace Library