cmake_minimum_required(VERSION 3.20.4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(AdventOfCode2024)

add_executable(Main Main.cxx)

target_include_directories(Main PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/Solutions"
    )

add_subdirectory(Solutions)

target_link_libraries(Main PUBLIC Solutions)

