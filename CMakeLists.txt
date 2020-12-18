# ------------------------------------------------------------------------------

# // ------------------------------------------------------------------------------
#
# HexagonEX - 2D puzzle game.
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
# OPTIONS
# =================================================================================

set ( CXX_VERSION 11 )

include ( "cmake/options.cmake" )

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "HexagonEX" )

# Project Version
set ( PROJECT_VERSION 0.0.1 )

# Project Description
set ( PROJECT_DESCRIPTION "Puzzle 2D Game" )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION} LANGUAGES C CXX )

# C++ Version
set ( CMAKE_CXX_STANDARD ${CXX_VERSION} )
#set ( CMAKE_CXX_STANDARD 17 ) # Android stdlibc++ 14+
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set Flags
# Flags:
# -fexceptions - enable C++ exceptions (GCC & MSVC), fcxx-exceptions (Clang);
set ( CMAKE_CXX_FLAGS "-fexceptions -fcxx-exceptions" ${CMAKE_CXX_FLAGS} )

# =================================================================================
# CONFIGS
# =================================================================================

include ( "cmake/configs.cmake" )

# =================================================================================
# MODULES
# =================================================================================

# Engine
add_subdirectory ( "src/cpp/engine/public/hex" )

# Game
add_subdirectory ( "src/cpp/game/public/hex" )

# ------------------------------------------------------------------------------
