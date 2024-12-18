cmake_minimum_required(VERSION 3.20.4)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(AdventOfCode2024)

add_executable(AdventOfCode2024 main.cxx)

target_precompile_headers(AdventOfCode2024 PRIVATE precompiled.hxx)

target_include_directories(AdventOfCode2024 PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/Solutions"
    "${PROJECT_SOURCE_DIR}/Utilities"
)

add_subdirectory(Solutions)
add_subdirectory(Utilities)

target_link_libraries(AdventOfCode2024 PUBLIC Solutions)

