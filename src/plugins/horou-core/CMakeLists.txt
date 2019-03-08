include_directories("../../libhorou")

add_library(horou_core SHARED
        PluginEntry.cpp
        )

target_link_libraries(horou_core libhorou)
