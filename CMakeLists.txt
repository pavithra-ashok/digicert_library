cmake_minimum_required(VERSION 3.10)
project(LibrarySystem)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/Book.cpp
    src/FileDataSource.cpp
    src/LibraryService.cpp
    src/Logger.cpp
)

# Library
add_library(LibraryCore STATIC ${SOURCES})

# Mock Library for testing
set(TEST_SOURCES
    tests/MockLibrary.cpp
    tests/TestLibrary.cpp
    tests/InMemoryDataSource.cpp
    tests/DigicertLibrary.cpp
)

# Test executable
add_executable(LibraryTests ${TEST_SOURCES})
target_link_libraries(LibraryTests PRIVATE LibraryCore)
