project(cmt.testplugin.0 LANGUAGES CXX)

set(SOURCE_FILES
    include/cmt/testplugin/internal/platform.hpp
    include/cmt/testplugin/temp.hpp src/cmt/testplugin/temp.cpp
    include/cmt/testplugin/Plugin.hpp src/cmt/testplugin/Plugin.cpp
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} cmt.0)
target_compile_definitions(${PROJECT_NAME} PRIVATE CMT_LIBRARY_BUILD)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
