add_custom_target(
    ut
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND CTEST_OUTPUT_ON_FAILURE=1 ${CMAKE_CTEST_COMMAND}
    DEPENDS SudokuTests AlgorithmTests GeneratorTests
    # TODO: find a better way to ensure targets are built
)

add_subdirectory(utils)