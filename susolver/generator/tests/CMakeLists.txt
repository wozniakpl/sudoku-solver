set(MODULE_NAME GeneratorTests)

add_executable(${MODULE_NAME} PermutationTests.cpp)

target_link_libraries(
    ${MODULE_NAME}
    PRIVATE ${GTEST_BOTH_LIBRARIES} ${GMOCK_BOTH_LIBRARIES} pthread Generator
)

add_test(Generator ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${MODULE_NAME})
