add_custom_target(
    format_cmake
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND gersemi -i ./susolver/ CMakeLists.txt cmake/
)

add_custom_target(
    format_cmake_check
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND gersemi -i ./susolver/ CMakeLists.txt cmake/ --check
)

add_custom_target(
    format_python
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND black .
)

add_custom_target(
    format_python_check
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND black . --check
)

add_custom_target(
    format_cpp
    COMMAND find ${PROJECT_SOURCE_DIR} -name '*pp' | xargs clang-format -i
)

# TODO: format_cpp_check

add_custom_target(format DEPENDS format_cmake format_cpp format_python)
add_custom_target(format_check DEPENDS format_cmake_check format_python_check)
