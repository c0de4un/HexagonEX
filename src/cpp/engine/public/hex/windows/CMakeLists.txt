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
set ( PROJECT_NAME "hexEngine.Windows" )

# Project Version
set ( PROJECT_VERSION 0.0.1 )

# Project Description
set ( PROJECT_DESCRIPTION "Puzzle Game Engine" )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION} LANGUAGES C CXX )

# C++ Version
#set ( CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# =================================================================================
# CONFIGS
# =================================================================================

set ( PUBLIC_DIR "" )
set ( PRIVATE_DIR "../../../private/hex/windows/" )

# =================================================================================
# HEADERS
# =================================================================================

set ( HEX_WIN_HEADERS ""
    # ASYNC
    "${PUBLIC_DIR}utils/async/WinMutex.hpp"
    # GRAPHICS
    "${PUBLIC_DIR}graphics/WinGraphics.hpp"
    # APPLICATION
    "${PUBLIC_DIR}app/WinApp.hpp" )

# DEBUG
if ( DEBUG OR HEX_DEBUG )
    set ( HEX_WIN_HEADERS ${HEX_WIN_HEADERS}
    "${PUBLIC_DIR}utils/metrics/WinLog.hpp" )
endif ( DEBUG OR HEX_DEBUG )

# =================================================================================
# SOURCES
# =================================================================================

set ( HEX_WIN_SOURCES ""
    # ASYNC
    "${PRIVATE_DIR}utils/async/WinMutex.cpp"
    # GRAPHICS
    "${PRIVATE_DIR}graphics/WinGraphics.cpp"
    # APPLICATION
    "${PRIVATE_DIR}app/WinApp.cpp" )

# DEBUG
if ( DEBUG OR HEX_DEBUG )
    set ( HEX_WIN_SOURCES ${HEX_WIN_SOURCES}
    "${PRIVATE_DIR}utils/metrics/WinLog.cpp" )
endif ( DEBUG OR HEX_DEBUG )

# =================================================================================
# BUILD
# =================================================================================

# Add STATIC Library
add_library ( hexEngine.Windows ${HEX_WIN_HEADERS} ${HEX_WIN_SOURCES} )

# Link
target_include_directories ( hexEngine.Windows PUBLIC "../core" )
target_include_directories ( hexEngine.Windows PUBLIC "../ecs" )
target_link_libraries ( hexEngine.Windows hexEngine.Core )

# ------------------------------------------------------------------------------
