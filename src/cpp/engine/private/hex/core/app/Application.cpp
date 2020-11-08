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

// Include hex::memory
#ifndef HEX_CORE_CONFIG_MEMORY_HPP
#include "../../../../public/hex/core/configs/hex_memory.hpp"
#endif // !HEX_CORE_CONFIG_MEMORY_HPP

// Include hex::ecs::ECSEngine
#ifndef HEX_ECS_ENGINE_HPP
#include "../../../../public/hex/ecs/ECSEngine.hpp"
#endif // HEX_ECS_ENGINE_HPP

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

        Application* Application::mInstance( nullptr );

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        Application::Application() = default;

        Application::~Application() noexcept = default;

        // ===========================================================
        // METHODS
        // ===========================================================

        void onInitialize()
        {

        }

        void Application::Terminate() noexcept
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            hexLog::printInfo( u8"Application::Terminate" );
#endif // DEBUG

            if ( mInstance )
                mInstance->onTerminate();

            mInstance = nullptr;
        }

        void Application::onInitialize()
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            hexLog::printInfo( u8"Application::onInitialize" );
#endif // DEBUG

            Application::onInitialize();
        }

        void Application::onTerminate() noexcept
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            hexLog::printInfo( u8"Application::onTerminate" );
#endif // DEBUG

            // Terminate Application
            hexMemory::Delete( mInstance );

            // Terminate ECS
            hexECS::Terminate();

            // Termiante MemoryManager
            hexMemory::Terminate();
        }

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

// -----------------------------------------------------------
