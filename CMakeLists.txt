cmake_minimum_required(VERSION 3.10)
project(LibrarySystem)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/Book.cpp
    src/FileDataSource.cpp
    src/LibraryUtility.cpp
    src/Logger.cpp
)

# Executable
add_executable(LibrarySystem ${SOURCES})

# Mock Library for testing
set(TEST_SOURCES
    tests/MockLibrary.cpp
    tests/DigicertLibrary.cpp
)

# Test executable
add_executable(LibraryTests ${TEST_SOURCES})
target_link_libraries(LibraryTests PRIVATE LibrarySystem)
