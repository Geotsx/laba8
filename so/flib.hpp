#ifndef FILELIB_H
#define FILELIB_H

#include <string>
#include <vector>

class FileLib {
public:
    static bool writeToFile(const std::string& filename, const std::string& content);
    static std::vector<std::string> readFromFile(const std::string& filename);
    static bool modifyLineInFile(const std::string& filename, int lineNumber, const std::string& newContent);
    static bool deleteLineInFile(const std::string& filename, int lineNumber);
};

#endif // FILELIB_H

