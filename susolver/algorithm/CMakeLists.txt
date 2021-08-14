set(MODULE_NAME Algorithms)

add_library(${MODULE_NAME} src/BruteForce.cpp src/Utils.cpp)

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME} PUBLIC Sudoku)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
