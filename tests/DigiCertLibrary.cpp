// DigiCertLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MockLibrary.cpp"
#include "TestLibrary.cpp"
#include "Logger.hpp"

void testMockLibrary() {
    std::string fileName = "books.txt";
    Library::Test::MockLibrary mockLibrary;
    mockLibrary.runWorkflow();
}

void testMockLibraryWithLogging() {
    std::string fileName = "books.txt";
    Library::Logger::enableLogging();
    Library::Test::MockLibrary mockLibrary;
    mockLibrary.runWorkflow();
}

void runTests() {
    Library::Test::TestLibrary testLibrary;
    testLibrary.runTests();
}
int main()
{
    std::cout << "Hello World!\n";
    testMockLibrary();
    //testMockLibraryWithLogging();
    runTests();
    return 0;
}
