cmake_minimum_required(VERSION 3.5)

project(Geometry)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/module)

set(BOOST_ROOT "D:/C++ Library/boost_1_67_0")
find_package(Boost 1.67.0 REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories("D:/C++ Library/eigen3")
include_directories("D:/Github/Catch2/single_include")

include("D:/Github/Catch2/contrib/Catch.cmake")


set(CORE_TARGET ${PROJECT_NAME}_core)
set(TEST_TARGET ${PROJECT_NAME}_test)


add_subdirectory(core)
add_subdirectory(test)
