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
#ifndef HEX_ECS_SYSTEMS_MANAGER_HPP
#include "../../../../public/hex/ecs/systems/SystemsManager.hpp"
#endif // !HEX_ECS_SYSTEMS_MANAGER_HPP

// Include hex::ecs::memory
#ifndef HEX_ECS_DEBUG_HPP
#include "../../../public/hex/ecs/types/ecs_memory.hpp"
#endif // !HEX_ECS_DEBUG_HPP

// DEBUG
#if defined( DEBUG ) || defined( HEX_DEBUG )

// Include debug
#ifndef HEX_ECS_DEBUG_HPP
#include "../../../../public/hex/ecs/types/ecs_debug.hpp"
#endif // !HEX_ECS_DEBUG_HPP

#endif
// DEBUG

// ===========================================================
// ecs::SystemsManager
// ===========================================================

namespace hex
{

    namespace ecs
    {

        // -----------------------------------------------------------

        // ===========================================================
        // FIELDS
        // ===========================================================

        SystemsManager* SystemsManager::mInstance( nullptr );

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        SystemsManager::SystemsManager()
        {
        }

        SystemsManager::~SystemsManager() noexcept = default;

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        SystemsManager* SystemsManager::getInstance() noexcept
        { return mInstance; }

        // ===========================================================
        // METHODS
        // ===========================================================

        void SystemsManager::Initialize()
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
                ecsLog::printInfo( "SystemsManager::Initialize" );
#endif // DEBUG

            if ( !mInstance )
                mInstance = ecsNew<SystemsManager>();
        }

        void SystemsManager::Terminate() noexcept
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
                ecsLog::printInfo( "SystemsManager::Terminate" );
#endif // DEBUG

            ecsDelete( mInstance );
            mInstance = nullptr;
        }

        // -----------------------------------------------------------

    } /// hex::ecs

} /// hex

// -----------------------------------------------------------