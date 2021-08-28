set(MODULE_NAME AlgorithmTests)

add_executable(${MODULE_NAME} UtilsTests.cpp)

target_link_libraries(
    ${MODULE_NAME}
    PRIVATE
        ${GTEST_BOTH_LIBRARIES}
        ${GMOCK_BOTH_LIBRARIES}
        pthread
        Algorithms
        TestUtils
)

add_test(Algorithms ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${MODULE_NAME})
