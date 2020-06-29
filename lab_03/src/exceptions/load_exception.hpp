#pragma once

#include "base_exception.hpp"

class OpenStreamError : public BaseException {
   public:
    OpenStreamError(
        const std::string& filename,
        const std::string& classname,
        const int line,
        const char* time,
        const std::string& info = "Error while opening stream") 
        : BaseException(filename, classname, line, time, info) {}
};

class ReadStreamError : public BaseException {
   public:
    ReadStreamError(
        const std::string& filename,
        const std::string& classname,
        const int line,
        const char* time,
        const std::string& info = "Error while reading stream") 
        : BaseException(filename, classname, line, time, info) {}
};

class FileFormatError : public BaseException {
   public:
    FileFormatError(
        const std::string& filename,
        const std::string& classname,
        const int line,
        const char* time,
        const std::string& info = "Wrong format of file") 
        : BaseException(filename, classname, line, time, info) {}
};
