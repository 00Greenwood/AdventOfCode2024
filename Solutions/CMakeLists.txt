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
)

target_include_directories(Solutions PRIVATE     
    "${PROJECT_SOURCE_DIR}/Solutions"
    "${PROJECT_SOURCE_DIR}/Utilities"
)

target_link_libraries(Solutions PUBLIC Utilities)
