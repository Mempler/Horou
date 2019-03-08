include_directories("../../libhorou")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugins)

add_library(horou_core SHARED
        PluginEntry.cpp
        )

target_link_libraries(horou_core libhorou)
