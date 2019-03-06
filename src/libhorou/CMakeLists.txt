find_package(Boost 1.65.1 REQUIRED system)
find_package(OpenSSL REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${OPENSSL_INCLUDE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(libhorou SHARED
        io/network/http/Server.cpp
        io/buffer/Buffer.cpp
        io/buffer/TextBuffer.cpp
        io/network/http/Request.cpp
        io/network/http/Response.cpp
        utils/StringUtils.cpp
        io/buffer/BinaryBuffer.cpp
        io/packets/Packet.cpp
        io/packets/server_packets/fun/Announce.cpp
        io/packets/server_packets/LoginResponse.cpp
)

target_link_libraries(libhorou pthread ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})
set_target_properties(libhorou PROPERTIES PREFIX "")
