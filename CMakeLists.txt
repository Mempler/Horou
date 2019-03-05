cmake_minimum_required(VERSION 3.10)
project(Horou CXX)

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
        src/handlers/bancho/HTTPHandler.cpp src/handlers/bancho/HTTPHandler.h
        src/io/network/http/Method.h
        src/io/buffer/BinaryBuffer.cpp src/io/buffer/BinaryBuffer.h
        src/io/packets/Packet.cpp src/io/packets/Packet.h
        src/io/packets/PacketId.h src/io/packets/server_packets/fun/Announce.cpp
        src/io/packets/server_packets/fun/Announce.h src/io/packets/server_packets/LoginResponse.cpp src/io/packets/server_packets/LoginResponse.h)

target_link_libraries(Horou pthread ${Boost_LIBRARIES})
