# ------------------------------------------------------------------------------

# // ------------------------------------------------------------------------------
#
# hexEngine - open-source Game Engine. Designed for 2D Puzzle Games rapid development.
#
# License: see "LICENSE" file.
#
# // ------------------------------------------------------------------------------

# =================================================================================
# CMake Meta-Data
# =================================================================================

# CMake-Version
cmake_minimum_required ( VERSION 3.6 FATAL_ERROR ) # QT & Android

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "hexEngine.CORE" )

# Project Version
set ( PROJECT_VERSION 0.0.1 )

# Project Description
set ( PROJECT_DESCRIPTION "Puzzle Game Engine" )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION} LANGUAGES C CXX )

# C++ Version
set ( CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# =================================================================================
# CONFIGS
# =================================================================================

set ( PUBLIC_DIR "" )
set ( PRIVATE_DIR "../../../private/hex/core/" )

# =================================================================================
# HEADERS
# =================================================================================

set ( HEX_CORE_HEADERS
    # CONFIGS
    "${PUBLIC_DIR}configs/hex_platform.hpp"
    "${PUBLIC_DIR}configs/hex_api.hpp"
    "${PUBLIC_DIR}configs/hex_atomic.hpp"
    "${PUBLIC_DIR}configs/hex_assert.hpp"
    "${PUBLIC_DIR}configs/hex_memory.hpp"
    # APPLICATION
    "${PUBLIC_DIR}app/IApplication.hxx"
    "${PUBLIC_DIR}app/Application.hpp"
    # GRAPHICS
    # ENGINE
    # RENDER
    # ASYNC
    "${PUBLIC_DIR}utils/async/IMutex.hxx"
    "${PUBLIC_DIR}utils/async/Mutex.hpp"
    # ASSETS
    # INPUT
    # MEMORY
    "${PUBLIC_DIR}utils/memory/MemoryManager.hpp"
    # UTILS
    "${PUBLIC_DIR}hex.hpp" )

# DEBUG
if ( DEBUG OR HEX_DEBUG )
    set ( HEX_CORE_HEADERS ${HEX_CORE_HEADERS}
        "${PUBLIC_DIR}configs/hex_assert.hpp"
        "${PUBLIC_DIR}utils/metrics/ILog.hxx"
        "${PUBLIC_DIR}utils/metrics/Log.hpp"
        "${PUBLIC_DIR}configs/hex_log.hpp" )
endif ( DEBUG OR HEX_DEBUG )

# =================================================================================
# SOURCES
# =================================================================================

set ( HEX_CORE_SOURCES
    # APPLICATION
    "${PRIVATE_DIR}app/Application.cpp"
    # GRAPHICS
    # ENGINE
    # RENDER
    # ASYNC
    "${PRIVATE_DIR}utils/async/Mutex.cpp"
    # ASSETS
    # INPUT
    # MEMORY
    "${PRIVATE_DIR}utils/memory/MemoryManager.cpp"
    # UTILS
    "${PRIVATE_DIR}hex.cpp" )

# DEBUG
if ( DEBUG OR HEX_DEBUG )
    set ( HEX_CORE_SOURCES ${HEX_CORE_SOURCES}
        "${PRIVATE_DIR}utils/metrics/Log.cpp" )
endif ( DEBUG OR HEX_DEBUG )

# =================================================================================
# MODULES
# =================================================================================

# ECS
set ( HEX_CORE_HEADERS ${HEX_CORE_HEADERS} ${HEX_ECS_HEADERS_EXPORT} )
set ( HEX_CORE_SOURCES ${HEX_CORE_SOURCES} ${HEX_ECS_SOURCES_EXPORT} )
message( STATUS "${PROJECT_NAME} - HEADERS: ${HEX_CORE_HEADERS}\r\nSOURCES: ${HEX_CORE_SOURCES}" )

# =================================================================================
# BUILD
# =================================================================================

# Add STATIC Library Object
add_library ( hexEngine.Core ${HEX_CORE_HEADERS} ${HEX_CORE_SOURCES} )

# ------------------------------------------------------------------------------
