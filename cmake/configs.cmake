# HexEngine Root Dir
set ( HEX_ROOT_DIR "${CMAKE_SOURCE_DIR}/src/cpp/engine" )

# Detect Debug
if ( AUTO_DETECT_DEBUG )
    if ( ${CMAKE_BUILD_TYPE} STREQUAL Debug )
        set ( DEBUG ON )
        set ( HEX_DEBUG ON )
        add_definitions ( -DHEX_DEBUG=1 )
    endif ( ${CMAKE_BUILD_TYPE} STREQUAL Debug )
else ( AUTO_DETECT_DEBUG )
    if ( DEBUG )
        set ( HEX_DEBUG ON )
        add_definitions ( -DDEBUG=1 )
        add_definitions ( -DHEX_DEBUG=1 )
    endif ( DEBUG )
endif ( AUTO_DETECT_DEBUG )

# C++ Version
if ( NOT CXX_VERSION )
    message ( FATAL_ERROR "${PROJECT_NAME} - C++ Verion not set !" )
endif ( NOT CXX_VERSION )