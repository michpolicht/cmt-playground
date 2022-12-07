project(toml-0 LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE tomlplusplus/include/toml++/toml.h)
target_include_directories(${PROJECT_NAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/tomlplusplus/include")
