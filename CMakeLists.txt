cmake_minimum_required(VERSION 3.10)
project(Horou CXX)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src/libhorou)
add_subdirectory(src/horou)

add_subdirectory(src/plugins/horou-core)