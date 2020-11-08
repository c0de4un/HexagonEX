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
# OPTIONS
# =================================================================================

# Root.Dir
if ( NOT DEFINED HEX_ROOT_DIR )
    message ( FATAL_ERROR "${PROJECT_NAME} - root dir for engine is not defined. Set <HEX_ROOT_DIR>." )
endif ( NOT DEFINED HEX_ROOT_DIR )

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "hexEngine" )

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

include ( "cmake/configs.cmake" )

# =================================================================================
# MODULES
# =================================================================================

# ECS
set ( HEX_ECS_HEADERS_EXPORT "" )
set ( HEX_ECS_SOURCES_EXPORT "" )
add_subdirectory ( "ecs" )

# CORE
add_subdirectory ("core")

# WINDOWS
if ( WINDOWS OR WIN64 OR WIN32 OR MSVC OR MINGW OR MINGW64 )
    add_subdirectory ( "windows" )
endif ( WINDOWS OR WIN64 OR WIN32 OR MSVC OR MINGW OR MINGW64 )

# ------------------------------------------------------------------------------
