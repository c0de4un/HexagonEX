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
#ifndef MAIN_HPP
#include "../../../public/hex/windows/main.hpp"
#endif // !MAIN_HPP

// Include hex::win::WinApp
#ifndef HEX_WIN_APP_HPP
#include "../../../../engine/public/hex/windows/app/WinApp.hpp"
#endif // !HEX_WIN_APP_HPP

// Include hex::ecs::Engine
#ifndef HEX_ECS_ENGINE_HPP
#include "../../../../engine/public/hex/ecs/ECSEngine.hpp"
#endif // !HEX_ECS_ENGINE_HPP

// Include hex::win::WinGraphics
#ifndef HEX_WIN_GRAPHICS_HPP
#include "../../../../engine/public/hex/windows/graphics/WinGraphics.hpp"
#endif // !HEX_WIN_GRAPHICS_HPP

// Include hexgame::core::HexGame
#ifndef HEXGAME_CORE_HEXGAME_HPP
#include "../../../public/hex/core/game/HexGame.hpp"
#endif // !HEXGAME_CORE_HEXGAME_HPP

// @TODO: Include hex::gl::GLRenderManager

// @TODO: Include hex::win::WinAudio

// @TODO: Include hex::win::WinInput

// DEBUG
#if defined(DEBUG) || defined(HEX_DEBUG)

// Include hex::log
#ifndef HEX_CORE_CONFIG_LOG_HPP
#include "../../engine/public/hex/core/configs/hex_log.hpp"
#endif // !HEX_CORE_CONFIG_LOG_HPP

#endif // DEBUG

// ===========================================================
// METHODS
// ===========================================================

void init() noexcept
{
    try {
        // Initialize Logger
#if defined(DEBUG) || defined(HEX_DEBUG) // DEBUG
        hex::win::WinLog::Initialize();
        hex_Log::printInfo( "HexagonEX.Windows: starting . . ." );
#endif // DEBUG

        // Initialize MemoryManager
        hex_Memory::Initialize();

        // Initialize ECS
        hex_ECS::Initialize();

        // Initialize Application
        hex_WinApp* const winApp( hex_New<hex_WinApp>() );
        hex_sptr<hex_App> app( static_cast<hex_App*>(winApp) );

        // Initialize Graphics

        // Initialize Engine

        // Initialize Game
        hexgame::core::HexGame* const hexGame( hex_New<hexgame::core::HexGame>() );
        hex_sptr<hex_Game> game( static_cast<hex_Game*>(hexGame) );

        // Start Application
        if ( const int start_result = app->Start() != 0 )
        {
#if defined(DEBUG) || defined(HEX_DEBUG) // DEBUG
            hex_string errMsg( "HexagonEX.Windows: failed to start with code: " );
            errMsg += hex_Strings::to_string<int>( start_result );
            hex_Log::printError( errMsg.c_str() );
#endif // DEBUG

            return;
        }
    }
    catch (const std::exception& pException) { }
    catch (...) { }
}

void cleanUp() noexcept
{
#if defined(DEBUG) || defined(HEX_DEBUG) // DEBUG
    hex_Log::printInfo( "HexagonEX.Windows: stopping . . ." );
#endif // DEBUG

    // Terminate Game, Engine, Application, ECS, MemoryManager
    hex_App::Terminate();

    // Terminate Logger
#if defined(DEBUG) || defined(HEX_DEBUG) // DEBUG
    hex_Log::Terminate();
#endif // DEBUG
}

int main()
{
    // Print
    // std::cout << u8"HexagonEX.Windows: Hello World !\n";

    // Start
    init();

    // Stop
    cleanUp();

    // Wait
#if defined(DEBUG) || defined(HEX_DEBUG) // DEBUG
    std::cin.get();
#endif // DEBUG

    return 0;
}

// -----------------------------------------------------------
