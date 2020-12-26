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
#ifndef HEX_CORE_GAME_HPP
#include "../../../../engine/public/hex/core/game/Game.hpp"
#endif // !HEX_CORE_GAME_HPP

// Include hex::core::ESystem
#ifndef HEX_CORE_E_SYSTEMS_HPP
#include "../../../../public/hex/core/utils/ecs/ESystem.hpp"
#endif // !HEX_CORE_E_SYSTEMS_HPP

// DEBUG
#if defined( DEBUG ) || defined( HEX_DEBUG )

// Include hex::log
#ifndef HEX_CORE_CONFIG_LOG_HPP
#include "../../../public/hex/core/configs/hex_log.hpp"
#endif // !HEX_CORE_CONFIG_LOG_HPP

// Include hex::assert
#ifndef HEX_CORE_CONFIG_ASSERT_HPP
#include "../../../public/hex/core/configs/hex_assert.hpp"
#endif // !HEX_CORE_CONFIG_ASSERT_HPP

#endif
// DEBUG

// ===========================================================
// hex::core::Game
// ===========================================================

namespace hex
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // FIELDS
        // ===========================================================

        hex_sptr<Game> Game::mInstance( nullptr );

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        Game::Game()
            : System( hex_ESystem::GAME )
        {
        }

        Game::~Game() noexcept = default;

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        hex_sptr<Game> Game::getInstance() noexcept
        { return mInstance; }

        // ===========================================================
        // OVERRIDE: ecs::System
        // ===========================================================

        int Game::onStart()
        {
#ifdef HEX_DEBUG // DEBUG
            hex_Log::printInfo( "Game::onStart" );
#endif // DEBUG

            return 0;
        }

        int Game::onResume()
        {
#ifdef HEX_DEBUG // DEBUG
            hex_Log::printInfo( "Game::onResume" );
#endif // DEBUG

            return 0;
        }

        void Game::onPause() noexcept
        {
#ifdef HEX_DEBUG // DEBUG
            hex_Log::printInfo( "Game::onPause" );
#endif // DEBUG
        }

        void Game::onStop() noexcept
        {
#ifdef HEX_DEBUG // DEBUG
            hex_Log::printInfo( "Game::onStop" );
#endif // DEBUG
        }

        void Game::onTerminate() noexcept
        {
#ifdef HEX_DEBUG // DEBUG
            hex_Log::printInfo( "Game::onTerminate" );
#endif // DEBUG
        }

        // ===========================================================
        // METHODS
        // ===========================================================

        hex_sptr<Game> Game::Initialize( hex_sptr<Game> pInstance )
        {
#ifdef HEX_DEBUG // DEBUG
            hex_Log::printInfo( "Game::Initialize" );
#endif // DEBUG

            hex_sptr<Game> instance( getInstance() );
            if ( instance == nullptr )
                mInstance = pInstance;

            return getInstance();
        }

        void Game::Terminate() noexcept
        {
#ifdef HEX_DEBUG // DEBUG
            hex_Log::printInfo( "Game::Terminate" );
#endif // DEBUG

            hex_sptr<Game> instance( getInstance() );
            if ( instance != nullptr )
                instance->onTerminate();
            
            mInstance = nullptr;
        }

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

// -----------------------------------------------------------
