#pragma once

#include "base_exception.hpp"

class MemError : public BaseException {
   public:
    MemError(
        const std::string& filename,
        const std::string& classname,
        const int line,
        const char* time,
        const std::string& info = "A memory allocation error")
        : BaseException(filename, classname, line, time, info) {}
};

class RangeError : public BaseException {
   public:
    RangeError(
        const std::string& filename,
        const std::string& classname,
        const int line,
        const char* time,
        const std::string& info = "Out of range error")
        : BaseException(filename, classname, line, time, info) {}
};
