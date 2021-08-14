set(MODULE_NAME TestUtils)

add_library(${MODULE_NAME} src/String.cpp)

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)
