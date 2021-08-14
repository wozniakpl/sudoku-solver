add_custom_target(
    format_cmake
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND gersemi -i .
)

add_custom_target(
    format_python
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND black .
)

add_custom_target(
    format_cpp
    COMMAND find ${CMAKE_SOURCE_DIR} -name '*pp' | xargs clang-format -i
)

add_custom_target(format DEPENDS format_cmake format_cpp format_python)
