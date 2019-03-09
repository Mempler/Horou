find_package(Boost 1.65.1 REQUIRED system)
find_package(OpenSSL REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(../libhorou)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Horou
        main.cpp managers/PluginManager.cpp handlers/bancho/HTTPHandler.cpp
        events/PacketManager.cpp)

target_link_libraries(Horou libhorou pthread ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})
