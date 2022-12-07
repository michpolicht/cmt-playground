cmake_minimum_required(VERSION 3.5)

project(CMT-Playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden) # This should typically result in setting `-fvisibility=hidden` flag on POSIX.

list(INSERT CMAKE_MODULE_PATH 0
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/macros"
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
)

include(recurse_subproject_dirs)

set(CMT_BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/bin)

recurse_subproject_dirs(SUBDIRS ${CMT_BIN_DIR})
foreach(SUBDIR ${SUBDIRS})
    message(STATUS "Adding subproject: ${SUBDIR}")
    add_subdirectory(${SUBDIR})
endforeach()

recurse_subproject_dirs(SUBDIRS ${CMT_LIB_DIR})
foreach(SUBDIR ${SUBDIRS})
    message(STATUS "Adding subproject: ${SUBDIR}")
    add_subdirectory(${SUBDIR})
endforeach()
