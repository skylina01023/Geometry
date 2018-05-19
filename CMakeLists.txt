cmake_minimum_required(VERSION 3.5)

project(Geometry)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/module)

include_directories("D:/C++ Library/eigen3")

add_subdirectory(core)