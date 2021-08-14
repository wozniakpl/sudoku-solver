set(MODULE_NAME SudokuTests)

add_executable(
    ${MODULE_NAME}
    GridTests.cpp
    SubgridTests.cpp
    CellTests.cpp
    ConstraintsTests.cpp
)

target_link_libraries(
    ${MODULE_NAME}
    PRIVATE
        ${GTEST_BOTH_LIBRARIES}
        ${GMOCK_BOTH_LIBRARIES}
        pthread
        Sudoku
        TestUtils
)

add_test(Sudoku ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${MODULE_NAME})
