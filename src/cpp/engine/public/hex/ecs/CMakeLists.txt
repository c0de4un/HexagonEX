# ------------------------------------------------------------------------------

# // ------------------------------------------------------------------------------
#
# hexEngine - open-source Game Engine. Designed for 2D Puzzle Games rapid development.
# ECS - Entity Component System.
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
set ( PROJECT_NAME "hexEngine.ECS" )

# Project Version
set ( PROJECT_VERSION 0.0.1 )

# Project Description
set ( PROJECT_DESCRIPTION "hexEngine ECS Module" )

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

set ( PUBLIC_DIR "${HEX_ROOT_DIR}/public/hex/ecs/" )
set ( PRIVATE_DIR "${HEX_ROOT_DIR}/private/hex/ecs/" )

# =================================================================================
# HEADERS
# =================================================================================

set ( HEX_ECS_HEADERS
    "${PUBLIC_DIR}types/ecs_memory.hpp"
    "${PUBLIC_DIR}types/ecs_api.hpp"
    "${PUBLIC_DIR}types/ecs_atomic.hpp"
    "${PUBLIC_DIR}types/ecs_mutex.hpp"
    "${PUBLIC_DIR}types/ecs_types.hpp"
    "${PUBLIC_DIR}types/ecs_thread.hpp"
    "${PUBLIC_DIR}types/ecs_map.hpp"
    "${PUBLIC_DIR}types/ecs_vector.hpp"
    # EVENTS
    "${PUBLIC_DIR}events/IEvent.hxx"
    "${PUBLIC_DIR}events/Event.hpp"
    "${PUBLIC_DIR}events/EventsManager.hpp"
    # COMPONENTS
    "${PUBLIC_DIR}components/Component.hpp"
    "${PUBLIC_DIR}components/ComponentsManager.hpp"
    # ENTITIES
    "${PUBLIC_DIR}entities/IEntity.hxx"
    "${PUBLIC_DIR}entities/Entity.hpp"
    "${PUBLIC_DIR}entities/EntitiesManager.hpp"
    # SYSTEMS
    "${PUBLIC_DIR}systems/ISystem.hxx"
    "${PUBLIC_DIR}systems/System.hpp"
    "${PUBLIC_DIR}systems/SystemsManager.hpp"
    # CORE
    "${PUBLIC_DIR}ECSEngine.hpp"
    # UTILS
    "${PUBLIC_DIR}utils/IDStorage.hpp" )

# DEBUG
if ( DEBUG OR HEX_DEBUG )
    set ( HEX_ECS_HEADERS ${HEX_ECS_HEADERS}
    "${PUBLIC_DIR}types/ecs_debug.hpp" )
endif ( DEBUG OR HEX_DEBUG )

# =================================================================================
# SOURCES
# =================================================================================

set ( HEX_ECS_SOURCES
    # CONFIGS
    "${PRIVATE_DIR}types/ecs_types.cpp"
    # EVENTS
    "${PRIVATE_DIR}events/Event.cpp"
    "${PRIVATE_DIR}events/EventsManager.cpp"
    # COMPONENTS
    "${PRIVATE_DIR}components/Component.cpp"
    "${PRIVATE_DIR}components/ComponentsManager.cpp"
    # ENTITIES
    "${PRIVATE_DIR}entities/Entity.cpp"
    "${PRIVATE_DIR}entities/EntitiesManager.cpp"
    # SYSTEMS
    "${PRIVATE_DIR}systems/System.cpp"
    "${PRIVATE_DIR}systems/SystemsManager.cpp"
    # CORE
    "${PRIVATE_DIR}ECSEngine.cpp" )

# =================================================================================
# EXPORT
# =================================================================================

if ( NOT DEFINED HEX_ECS_HEADERS_EXPORT OR NOT DEFINED HEX_ECS_SOURCES_EXPORT )
    message( FATAL_ERROR "${PROJECT_NAME} - export list not defined" )
endif ( NOT DEFINED HEX_ECS_HEADERS_EXPORT OR NOT DEFINED HEX_ECS_SOURCES_EXPORT )

set ( HEX_ECS_HEADERS_EXPORT ${HEX_ECS_HEADERS} PARENT_SCOPE )
set ( HEX_ECS_SOURCES_EXPORT ${HEX_ECS_SOURCES} PARENT_SCOPE )

# ------------------------------------------------------------------------------
