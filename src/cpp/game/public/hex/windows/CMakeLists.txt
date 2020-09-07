# ------------------------------------------------------------------------------

# // ------------------------------------------------------------------------------
#
# Tutorial Project for memory-managment methods.
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
set ( PROJECT_NAME "HexagonEX.Windows" )

# Project Version
set ( PROJECT_VERSION 0.0.1 )

# Project Description
set ( PROJECT_DESCRIPTION "Puzzle 2D Game Client" )

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
set ( PRIVATE_DIR "../../../private/" )

# =================================================================================
# HEADERS
# =================================================================================

set ( HEX_GAME_WINDOWS_HEADERS
    "main.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( HEX_GAME_WINDOWS_SOURCES
    "${PRIVATE_DIR}hex/windows/main.cpp" )

# =================================================================================
# RESOURCES
# =================================================================================

set ( HEX_GAME_WINDOWS_RESOURCES "${CMAKE_SOURCE_DIR}/res/win/win_res.rc" )

# =================================================================================
# BUILD
# =================================================================================

# Add Executable Object
add_executable ( hexGame ${HEX_GAME_WINDOWS_HEADERS} ${HEX_GAME_WINDOWS_SOURCES} ${HEX_GAME_WINDOWS_RESOURCES} )

# Configure Executable
# Configure Executable-Object
set_target_properties ( hexGame PROPERTIES
    VERSION ${PROJECT_VERSION}
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" )

# Link Executable

# ------------------------------------------------------------------------------
