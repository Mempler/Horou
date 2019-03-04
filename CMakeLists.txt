cmake_minimum_required(VERSION 3.10)
project(Horou)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.65.1 REQUIRED system)

include_directories(${Boost_INCLUDE_DIR})

add_executable(Horou src/main.cpp
        src/io/network/http/Server.cpp src/io/network/http/Server.h
        src/io/buffer/Buffer.cpp src/io/buffer/Buffer.h
        src/io/buffer/TextBuffer.cpp src/io/buffer/TextBuffer.h
        src/io/network/http/Request.cpp src/io/network/http/Request.h
        src/io/network/http/Response.cpp src/io/network/http/Response.h
        src/utils/StringUtils.cpp src/utils/StringUtils.h
        src/handlers/HTTPHandler.cpp src/handlers/HTTPHandler.h src/io/network/http/Method.h src/io/buffer/BinaryBuffer.cpp src/io/buffer/BinaryBuffer.h)

target_link_libraries(Horou pthread ${Boost_LIBRARIES})
