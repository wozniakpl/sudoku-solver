add_subdirectory(sudoku)
add_subdirectory(algorithm)
add_subdirectory(generator)

add_executable(susolver Main.cpp)
target_link_libraries(susolver ${Boost_LIBRARIES} Sudoku Algorithms Generator)

install(TARGETS susolver DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
