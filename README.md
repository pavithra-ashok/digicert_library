# digicert_library
A command-line utility in C++ to simulate a fictional public library

# Functional Requirements
* Provide ability to:
	* List all Books - Display all books in the library with relevant details (e.g., title, author, genre, availability).	
	* Add a Book - Allow users to add a new book.
	* View Book Details - Retrieve and display detailed information about a specific book.
	* Update a Book - Modify book details such as title, author, or availability.
	* Delete a Book - Remove a book from the library database.
* Support different storage options (a file or external storage)

# Non-Functional Requirements
* Performance - Utility needs to be fast and responsive.
* Reliability - Ensure data consistency and prevent corruption.
* Usability - Simple command-line interface with intuitive commands.
* Extensibility - Support multi-threading/multi -processing environments in the future. 
* Maintainability - Modular and well-structured C++ code for future enhancements.
* Portability - Should run on major operating systems (Windows, Linux, macOS).
* Testability - Modular code to support testability at various granularity like unit, integration and system tests.

# Open Questions:
* Will the utility be used in a multi-threaded/multi-processor environment?
* Will the utility be run as a service for distributed systems?

# Design Decisions:
* The Library utility will be intialized with a data source.
* The data source is configurable for a library instance.
* The data source will define the actions based on the storage it supports.
 

## Assumptions
* Single threaded, Single process environment
	* The data source would need to handle consistency requirements in multithreaded or multi-process environments.
	* The Logger needs to be updated if this assumption is void.

# Architecture
```mermaid
classDiagram

direction RL
namespace Library {
     class Book {
        Identifier id;
        String name;
        String author;

    }
     class DataSource {
        <<Abstract>>
      + addBook()
      + getBook(BookID id)
      + updateBook(BookID id, fieldName, value)
      + deleteBook(BookID id)
    }
    
    class RedisDataSource {

    }
    class FileDataSource {

    }
    class LibraryService {
      + addBook()
      + getBook(BookID id)
      + getBookByName(title)
      + getBookByAuthor(author)
      + updateBook(BookID id, fieldName, value)
      + deleteBook(BookID id)
    }
   
}
DataSource <|-- FileDataSource
DataSource <|-- RedisDataSource
LibraryService  o-- DataSource
DataSource *-- "many" Book

namespace Tester {
 class InMemoryDataSource {

    }
    class MockLibrary {

    }
    class TestClient {

    }
}
InMemoryDataSource --|> DataSource
MockLibrary *-- LibraryService
MockLibrary .. InMemoryDataSource
TestClient -- MockLibrary

```


