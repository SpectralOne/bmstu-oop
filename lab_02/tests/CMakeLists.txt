FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES("${GTEST_INCLUDE_DIRS}")

FIND_PACKAGE(Threads REQUIRED)

INCLUDE_DIRECTORIES(include)

ADD_EXECUTABLE(
        tests
        src/main.cpp src/testing_operators.cpp
        src/testing_neg.cpp src/testing_constructors.cpp
        src/testing_append_methods.cpp
        src/testing_methods.cpp src/testing_iterators.cpp
        
)
TARGET_LINK_LIBRARIES(tests ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} stdc++fs)

ADD_TEST(
        NAME Testing
        COMMAND tests ${CMAKE_SOURCE_DIR}/tests/data --gtest_filter=-*Extra*
)
