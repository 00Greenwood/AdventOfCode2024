add_library(Solutions   
    Day.hxx
    Day.cxx
    Day0.hxx
    Day0.cxx
    Day1.hxx
    Day1.cxx
    Day2.hxx
    Day2.cxx
    Day3.hxx
    Day3.cxx
    Day4.hxx
    Day4.cxx
    Day5.hxx
    Day5.cxx
    Day6.hxx
    Day6.cxx
    Day7.hxx
    Day7.cxx
    Day8.hxx
    Day8.cxx
    Day9.hxx
    Day9.cxx
    Day10.hxx
    Day10.cxx
    Day11.hxx
    Day11.cxx
    Day12.hxx
    Day12.cxx
    Day13.hxx
    Day13.cxx
    Day14.hxx
    Day14.cxx
    Day15.hxx
    Day15.cxx
    Day16.hxx
    Day16.cxx
    Day17.hxx
    Day17.cxx
    Day18.hxx
    Day18.cxx
    Day19.hxx
    Day19.cxx
    Day20.hxx
    Day20.cxx
    Day21.hxx
    Day21.cxx
    Day22.hxx
    Day22.cxx
    Day23.hxx
    Day23.cxx
    Day24.hxx
    Day24.cxx
    Day25.hxx
    Day25.cxx
)

target_precompile_headers(Solutions PRIVATE precompiled.hxx)

target_compile_options(Solutions PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Werror -Wall -pedantic-errors -Wextra -Wconversion -Wsign-conversion>
     $<$<CXX_COMPILER_ID:MSVC>:
          /WX /W4>)

target_include_directories(Solutions PRIVATE     
    "${PROJECT_SOURCE_DIR}/Solutions"
    "${PROJECT_SOURCE_DIR}/Utilities"
)

target_link_libraries(Solutions PUBLIC Utilities)
