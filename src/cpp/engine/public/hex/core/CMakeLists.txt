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
set ( PRIVATE_DIR "../../../private/hex/" )

# =================================================================================
# HEADERS
# =================================================================================

set ( HEX_CORE_HEADERS
    # CONFIGS
    "${PUBLIC_DIR}configs/hex_api.hpp"
    # APPLICATION
    "${PUBLIC_DIR}app/IApplication.hxx"
    "${PUBLIC_DIR}app/Application.hpp"
    # GRAPHICS
    # ENGINE
    # RENDER
    # ASYNC
    # ASSETS
    # INPUT
    # UTILS
    "${PUBLIC_DIR}hex.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( HEX_CORE_SOURCES
    # APPLICATION
    "${PRIVATE_DIR}core/app/Application.cpp"
    # GRAPHICS
    # ENGINE
    # RENDER
    # ASYNC
    # ASSETS
    # INPUT
    # UTILS
    "${PRIVATE_DIR}core/hex.cpp" )

# =================================================================================
# BUILD
# =================================================================================

# Add STATIC Library Object
add_library ( hexEngine.Core ${HEX_CORE_HEADERS} ${HEX_CORE_SOURCES} )

# ------------------------------------------------------------------------------
