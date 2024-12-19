#include "flib.hpp"
#include <fstream>

bool FileLib::writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream out(filename);
    if (!out.is_open()) return false;
    out << content;
    out.close();
    return true;
}

std::vector<std::string> FileLib::readFromFile(const std::string& filename) {
    std::ifstream in(filename);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        lines.push_back(line);
    }
    in.close();
    return lines;
}

bool FileLib::modifyLineInFile(const std::string& filename, int lineNumber, const std::string& newContent) {
    auto lines = readFromFile(filename);
    if (lineNumber < 0 || lineNumber >= lines.size()) return false;
    
    lines[lineNumber] = newContent;

    std::ofstream out(filename);
    for (const auto& l : lines) {
        out << l << "\n";
    }
    out.close();
    return true;
}

bool FileLib::deleteLineInFile(const std::string& filename, int lineNumber) {
    auto lines = readFromFile(filename);
    if (lineNumber < 0 || lineNumber >= lines.size()) return false;

    lines.erase(lines.begin() + lineNumber);

    std::ofstream out(filename);
    for (const auto& l : lines) {
        out << l << "\n";
    }
    out.close();
    return true;
}

