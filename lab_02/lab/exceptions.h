#pragma once

#include <exception>
#include <string>

class ListException : public std::exception {
 public:
    explicit ListException(const std::string &msg)
        : m_msg(msg) {}

    const char *what() const noexcept override {
        return m_msg.c_str();
    }
 private:
    std::string m_msg;
};

class MemmoryError : public ListException {
 public:
    MemmoryError()
        : ListException("Error occurred while reading from stream") {}
};

class InvalidListStream : public ListException {
 public:
    InvalidListStream()
        : ListException("Error occurred while reading from stream") {}
};

class ListOutOfBounds : public ListException {
 public:
    ListOutOfBounds()
        : ListException("List out of bound") {}
};

class EmptyList : public ListException {
 public:
    EmptyList()
        : ListException("Empty List!") {}
};

class IteratorCompareError : public ListException {
 public:
    IteratorCompareError()
        : ListException("Different iterators!") {}
};

class NotEnoughNodes : public ListException {
 public:
    NotEnoughNodes()
        : ListException("Not enough nodes for sort!") {}
};

class ConstructorBadArguments : public ListException {
 public:
    ConstructorBadArguments()
        : ListException("Not enough nodes for sort!") {}
};