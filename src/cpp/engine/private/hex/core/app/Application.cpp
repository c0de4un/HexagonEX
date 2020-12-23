/**
 * All rights reserved.
 * License: see LICENSE.txt
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must display the names 'Denis Zyamaev' and
 * in the credits of the application, if such credits exist.
 * The authors of this work must be notified via email (code4un@yandex.ru) in
 * this case of redistribution.
 * 3. Neither the name of copyright holders nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 **/

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#ifndef HEX_CORE_APPLICATION_HPP
#include "../../../../public/hex/core/app/Application.hpp"
#endif // !HEX_CORE_APPLICATION_HPP

// Include hex::core::Engine
#ifndef HEX_CORE_ENGINE_HPP
#include "../../../../public/hex/core/engine/Engine.hpp"
#endif // !HEX_CORE_ENGINE_HPP

// Include hex::ecs::ECSEngine
#ifndef HEX_ECS_ENGINE_HPP
#include "../../../../public/hex/ecs/ECSEngine.hpp"
#endif // HEX_ECS_ENGINE_HPP

// Include hex::core::GraphicsManager
#ifndef HEX_CORE_GRAPHICS_MANAGER_HPP
#include "../../../../public/hex/core/graphics/GraphicsManager.hpp"
#endif // !HEX_CORE_GRAPHICS_MANAGER_HPP

// Include hex::core::ESystem
#ifndef HEX_CORE_E_SYSTEMS_HPP
#include "../../../public/hex/core/utils/ecs/ESystem.hpp"
#endif // !HEX_CORE_E_SYSTEMS_HPP

// DEBUG
#if defined( DEBUG ) || defined( HEX_DEBUG )

// Include hex::log
#ifndef HEX_CORE_CONFIG_LOG_HPP
#include "../../../../public/hex/core/configs/hex_log.hpp"
#endif // !HEX_CORE_CONFIG_LOG_HPP

// Include hex::assert
#ifndef HEX_CORE_CONFIG_ASSERT_HPP
#include "../../../../public/hex/core/configs/hex_assert.hpp"
#endif // !HEX_CORE_CONFIG_ASSERT_HPP

#endif
// DEBUG

// ===========================================================
// hex::core::Application
// ===========================================================

namespace hex
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTANTS & FIELDS
        // ===========================================================

        hex_sptr<Application> Application::mInstance( nullptr );

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        Application::Application()
            : System( hex_ESystem::APPLICATION )
        {
        }

        Application::~Application() noexcept = default;

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        hex_sptr<Application> Application::getInstance() noexcept
        { return mInstance; }

        // ===========================================================
        // METHODS
        // ===========================================================

        hex_sptr<Application> Application::Initialize( hex_sptr<Application> pInstance )
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            hex_assert( pInstance != nullptr && "Application::Initialize - null argument !" );
            hex_Log::printInfo( "Application::Initialize" );
#endif // DEBUG

            hex_sptr<Application> instance( getInstance() );
            if ( instance == nullptr )
                mInstance = pInstance;

            return instance;
        }

        void Application::Terminate() noexcept
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            hex_Log::printInfo( "Application::Terminate" );
#endif // DEBUG

            hex_sptr<Application> instance( getInstance() );
            if ( instance != nullptr )
            {
                // @TODO: Terminate Game
                hex_Game::Terminate();

                // Terminate Engine
                hex_Engine::Terminate();

                // Terminate Application
                instance->onTerminate();
                mInstance = nullptr;

                // Terminate ECS
                hex_ECS::Terminate();

                // Terminate MemoryManager
                hex_Memory::Terminate();
            }
        }

            // ===========================================================
            // OVERRIDE: ecs::System
            // ===========================================================

            int Application::onStart()
            {
                // Get Engine instance.
                hex_sptr<Engine> engine( hex_Engine::getInstance() );

                // Get Game instance.
                hex_sptr<Game> game( hex_Game::getInstance() );

#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            hex_Log::printInfo( "Application::onStart" );
            hex_assert( engine != nullptr && "Application::onStart: Engine is null !" );
            hex_assert( game != nullptr && "Application::onStart: Game is null !" );
#endif // DEBUG

                // System-Response
                int response( 0 );

                // Start Engine
                response = engine->Start();

                // Check Engine State
                if ( response != 0 )
                {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
                    hex_Log::printError( "Application::onStart - failed to start Engine !" );
#endif // DEBUG

                    return response;
                }

                // Start Game
                response = game->Start();

                // Check Game State
                if ( response != 0 )
                {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
                    hex_Log::printError( "Application::onStart - failed to start Game !" );
#endif // DEBUG

                    return response;
                }

                return 0;
            }

            int Application::onResume()
            {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            hex_Log::printInfo( "Application::onResume" );
#endif // DEBUG

                return 0;
            }

            void Application::onPause() noexcept
            {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            hex_Log::printInfo( "Application::onPause" );
#endif // DEBUG
            }

            void Application::onStop() noexcept
            {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            hex_Log::printInfo( "Application::onStop" );
#endif // DEBUG
            }

            void Application::onTerminate() noexcept
            {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            hex_Log::printInfo( "Application::onTerminate" );
#endif // DEBUG
            }

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

// -----------------------------------------------------------
