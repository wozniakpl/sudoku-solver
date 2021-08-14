add_custom_target(
    coverage
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND gcovr -r . -e '.*tests/.*' -d
    DEPENDS susolver ut
)
