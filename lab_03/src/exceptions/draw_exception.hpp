#pragma once

#include "base_exception.hpp"

class DrawerError : public BaseException {
   public:
    DrawerError(
        const std::string& filename,
        const std::string& classname,
        const int line,
        const char* time,
        const std::string& info = "Drawer wasn't set")
        : BaseException(filename, classname, line, time, info) {}
};

class CameraError : public BaseException {
   public:
    CameraError(
        const std::string& filename,
        const std::string& classname,
        const int line,
        const char* time,
        const std::string& info = "Camera wasn't set")
        : BaseException(filename, classname, line, time, info) {}
};
