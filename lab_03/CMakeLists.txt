cmake_minimum_required(VERSION 3.16)
project(lab3)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -lpthread")


function(assign_source_group)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction(assign_source_group)


add_subdirectory(src)
include_directories(src)

set(LAB_EXECUTABLE_NAME "lab3")

add_executable(${LAB_EXECUTABLE_NAME} ${LAB_SRC})
assign_source_group(${LAB_SRC})

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

target_link_libraries(${LAB_EXECUTABLE_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)
set_target_properties(${LAB_EXECUTABLE_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)
