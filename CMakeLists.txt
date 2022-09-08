cmake_minimum_required(VERSION 3.5)

project(CMT-Playground)

list(INSERT CMAKE_MODULE_PATH 0
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/macros"
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
)

include(subproject_dirs)

set(CMT_BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

subproject_dirs(SUBDIRS ${CMT_BIN_DIR})
foreach(SUBDIR ${SUBDIRS})
    message(STATUS "Adding subproject: ${SUBDIR}")
    add_subdirectory(${SUBDIR})
endforeach()

subproject_dirs(SUBDIRS ${CMT_LIB_DIR})
foreach(SUBDIR ${SUBDIRS})
    message(STATUS "Adding subproject: ${SUBDIR}")
    add_subdirectory(${SUBDIR})
endforeach()
