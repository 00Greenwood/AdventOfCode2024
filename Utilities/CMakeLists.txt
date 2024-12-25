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

# Create a macro for accessing the directory of input files.
target_compile_definitions(Utilities PUBLIC INPUTS_DIR="${CMAKE_SOURCE_DIR}/Inputs")
