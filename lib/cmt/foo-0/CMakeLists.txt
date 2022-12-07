project(cmt-foo-0 LANGUAGES CXX)

set(SOURCE_FILES
    include/cmt/foo/internal/platform.hpp
    include/cmt/foo/Plugin.hpp src/cmt/foo/Plugin.cpp
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

# Sample dependency
target_link_libraries(${PROJECT_NAME} PUBLIC cmt-testplugin-0)
# Dependency on cmt-0 could be commented out if cmt-testplugin-0 exposes cmt-0 as PUBLIC in target_link_libraries().
target_link_libraries(${PROJECT_NAME} PUBLIC cmt-0)
target_compile_definitions(${PROJECT_NAME} PRIVATE CMT_LIBRARY_BUILD)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
