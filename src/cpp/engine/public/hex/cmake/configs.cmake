# =================================================================================
# CONFIGS
# =================================================================================

# Debug
if ( DEBUG OR ${CMAKE_BUILD_TYPE} STREQUAL Debug )
    add_definitions ( -DHEX_DEBUG=1 )
endif ( DEBUG OR ${CMAKE_BUILD_TYPE} STREQUAL Debug )
