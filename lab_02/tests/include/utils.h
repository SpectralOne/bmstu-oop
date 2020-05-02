#pragma once

#include "list.hpp"
#include "exceptions.h"

#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>


namespace fs = std::filesystem;

extern fs::path glob_test_dir;

template <typename T>
using ListData = std::vector<T>;

template <typename T>
ListData<T> createListData(std::istream& is) {

    if (!is) {
        throw std::runtime_error("ListData reading failed");
    }

    if (is.peek() == std::ifstream::traits_type::eof()) {
        throw std::runtime_error("ListData reading failed");
    }

    ListData<T> list_data;
    T arg;
    while (is >> arg) {
        list_data.push_back(arg);
    }
    
    if (!is.eof()) {
        throw std::runtime_error("ListData reading failed");
    }

  return list_data;
}

template <typename T>
bool operator==(const List<T>& list, const ListData<T>& list_data) {
    return list.to_vect() == list_data;
}

template <typename T>
bool operator==(const ListData<T>& list_data, const List<T>& list) {
    return list_data == list.to_vect();
}