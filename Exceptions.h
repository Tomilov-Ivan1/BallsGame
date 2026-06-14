#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InputException : public std::runtime_error {
public:
    explicit InputException(const std::string& message)
        : std::runtime_error(message) {}
};

class FileException : public std::runtime_error {
public:
    explicit FileException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif