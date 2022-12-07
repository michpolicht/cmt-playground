project(cmt-0 LANGUAGES CXX)

set(SOURCE_FILES
    include/cmt/internal/platform.hpp
    include/cmt/temp.hpp src/cmt/temp.cpp
    include/cmt/macros.hpp
    include/cmt/Plugin.hpp
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

set(CMT_BOOST_ROOT "C:\\Boost" CACHE PATH "Boost root directory")
if (NOT DEFINED BOOST_ROOT)
    set(BOOST_ROOT ${CMT_BOOST_ROOT})
endif()
find_package(Boost 1.80 COMPONENTS filesystem system)
if(Boost_FOUND)
    message(STATUS ${Boost_INCLUDE_DIR})
    target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})
    target_link_directories(${PROJECT_NAME} PUBLIC ${Boost_LIBRARY_DIRS})
else()
    message(FATAL_ERROR "Boost package not found, please set CMT_BOOST_ROOT variable or provide hint to FindBoost module.")
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE CMT_LIBRARY_BUILD)
target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_LIBRARIES} toml-0)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
