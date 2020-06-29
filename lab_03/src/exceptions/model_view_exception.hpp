#pragma once

#include "base_exception.hpp

class ModelOutOfRangeError : public BaseException {
   public:
    ModelOutOfRangeError(
        const std::string& filename,
        const std::string& classname,
        const int line,
        const char* time,
        const std::string& info = "Model is out of range")
        : BaseException(filename, classname, line, time, info) {}
};
