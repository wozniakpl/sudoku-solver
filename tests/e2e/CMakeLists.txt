add_custom_target(
    e2e
    COMMAND
        python3 -m pytest ${CMAKE_CURRENT_SOURCE_DIR} --build-dir ../../ # TODO
    DEPENDS susolver
)