cmake_minimum_required(VERSION 3.5)

project(cmt.cement LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC
    src/cmt/cement/main.cpp
)

set(INCLUDE
)

add_executable(${PROJECT_NAME} ${INCLUDE} ${SRC})
