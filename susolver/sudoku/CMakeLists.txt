set(MODULE_NAME Sudoku)

add_library(
    ${MODULE_NAME}
    src/Grid.cpp
    src/Cell.cpp
    src/Subgrid.cpp
    src/Constraints.cpp
    src/Coordinates.cpp
)

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
