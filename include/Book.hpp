#pragma once
#include <string>

namespace Library {
    using BookIdentifier = int;
    class Book {
    public:        
        BookIdentifier id;
        std::string name;
        std::string author;

        static Book fromString(const std::string& data);
        std::string toString() const;
    };
}