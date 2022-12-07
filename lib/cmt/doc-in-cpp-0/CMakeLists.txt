project(cmt-doc-in-cpp-0 LANGUAGES CXX)

set(SOURCE_FILES
    include/cmt/doc/in/cpp/internal/platform.hpp
    include/cmt/doc/in/cpp/Plugin.hpp src/cmt/doc/in/cpp/Plugin.cpp
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

# LLVM
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake from: ${LLVM_DIR}")

target_include_directories(${PROJECT_NAME} PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${LLVM_DEFINITIONS})
set(CMAKE_LIBRARY_PATH "${LLVM_LIBRARY_DIRS};${CMAKE_LIBRARY_PATH}")

find_library(LIB_CLANG_ANALYSIS clangAnalysis REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_ANALYSIS})

find_library(LIB_CLANG_AST clangAst REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_AST})

find_library(LIB_CLANG_BASIC clangBasic REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_BASIC})

find_library(LIB_CLANG_DRIVER clangDriver REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_DRIVER})

find_library(LIB_CLANG_EDIT clangEdit REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_EDIT})

find_library(LIB_CLANG_FRONTEND clangFrontend REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_FRONTEND})

find_library(LIB_CLANG_LEX clangLex REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_LEX})

find_library(LIB_CLANG_PARSE clangParse REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_PARSE})

find_library(LIB_CLANG_SEMA clangSema REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_SEMA})

find_library(LIB_CLANG_SERIALIZATION clangSerialization REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_SERIALIZATION})

find_library(LIB_CLANG_TOOLING clangTooling REQUIRED)
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIB_CLANG_TOOLING})

llvm_map_components_to_libnames(LLVM_LIBS
    frontendOpenMP
    option
    support
    windowsDriver
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LLVM_LIBS})

# Version
if(WIN32)
    # Note: shared library alternative for Version.lib is Api-ms-win-core-version-l1-1-0.dll.
    target_link_libraries(${PROJECT_NAME} PRIVATE Version)
endif()

# Lib common
target_link_libraries(${PROJECT_NAME} PUBLIC cmt-0)
target_compile_definitions(${PROJECT_NAME} PRIVATE CMT_LIBRARY_BUILD)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
