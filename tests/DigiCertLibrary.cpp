// DigiCertLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MockLibrary.cpp"
#include "Logger.hpp"

void testMockLibrary() {
    std::string fileName = "books.txt";
    Library::Test::MockLibrary mockLibrary("library_data.txt");
    mockLibrary.runWorkflow();
}

void testMockLibraryWithLogging() {
    std::string fileName = "books.txt";
    Library::Logger::enableLogging();
    Library::Test::MockLibrary mockLibrary("library_data.txt");
    mockLibrary.runWorkflow();
}

int main()
{
    std::cout << "Hello World!\n";
    testMockLibrary();
    testMockLibraryWithLogging();
    return 0;
}
