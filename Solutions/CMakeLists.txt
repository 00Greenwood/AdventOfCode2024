add_library(Solutions 
    Days.hxx    
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
)

target_include_directories(Solutions PRIVATE     
    "${PROJECT_SOURCE_DIR}/Solutions"
    "${PROJECT_SOURCE_DIR}/Utilities"
)

target_link_libraries(Solutions PUBLIC Utilities)
