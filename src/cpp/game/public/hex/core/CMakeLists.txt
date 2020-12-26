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
set ( PROJECT_NAME "HexagonEX.Core" )

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
set ( PRIVATE_DIR "../../../private/hex/core/" )

# =================================================================================
# HEADERS
# =================================================================================

set ( HEX_GAME_CORE_HEADERS
    # GAME
    "${PUBLIC_DIR}game/HexGame.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( HEX_GAME_CORE_SOURCES
    "${PRIVATE_DIR}game/HexGame.cpp" )

# =================================================================================
# BUILD
# =================================================================================

# Add STATIC Library
add_library ( HexagonEX.Core ${HEX_GAME_CORE_HEADERS} ${HEX_GAME_CORE_SOURCES} )

# Link
target_include_directories ( HexagonEX.Core PUBLIC "../../../../engine/public" )
target_link_libraries ( HexagonEX.Core hexEngine.Core )
#target_include_directories ( hexEngine.Windows PUBLIC "../core" )
#target_include_directories ( hexEngine.Windows PUBLIC "../ecs" )
#target_link_libraries ( hexEngine.Windows hexEngine.Core )

# ------------------------------------------------------------------------------
