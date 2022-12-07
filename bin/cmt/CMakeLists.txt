project(cmt LANGUAGES CXX)

set(SOURCE_FILES
    src/cmt/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} cmt-0)
