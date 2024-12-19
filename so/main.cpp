#include <iostream>
#include "flib.hpp"

int main() {
    FileLib::writeToFile("example.txt", "Hello World!");
    
    auto lines = FileLib::readFromFile("example.txt");
    
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }

    FileLib::modifyLineInFile("example.txt", 0, "Hello C++!");
    
    FileLib::deleteLineInFile("example.txt", 0);

    return 0;
}

