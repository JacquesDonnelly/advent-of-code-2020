cmake_minimum_required(VERSION 2.8.12)
project(advent)
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
include_directories(src)
add_subdirectory(src)
add_subdirectory(tests)

