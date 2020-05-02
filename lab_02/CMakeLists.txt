cmake_minimum_required(VERSION 3.16)
project(list)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

ENABLE_TESTING()

INCLUDE_DIRECTORIES(lab)
ADD_SUBDIRECTORY(tests)