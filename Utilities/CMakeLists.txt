add_library(Utilities 
    parse.hxx
    parse.cxx
    Position.hxx
    Position.cxx
    PositionAndDirection.hxx
    PositionAndDirection.cxx
    Direction.hxx
    Direction.cxx
)

target_include_directories(Utilities PRIVATE .)

target_compile_options(Utilities PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Werror -Wall -pedantic-errors -Wextra -Wconversion -Wsign-conversion>
     $<$<CXX_COMPILER_ID:MSVC>:
          /WX /W4>)

# Create a macro for accessing the directory of input files.
target_compile_definitions(Utilities PUBLIC INPUTS_DIR="${CMAKE_SOURCE_DIR}/Inputs")
