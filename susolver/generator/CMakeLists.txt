set(MODULE_NAME Generator)

add_library(${MODULE_NAME} src/Generation.cpp src/Permutations.cpp)

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME} PUBLIC Sudoku Algorithms)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
