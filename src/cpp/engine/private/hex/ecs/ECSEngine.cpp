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
#ifndef HEX_ECS_ENGINE_HPP
#include "../../../public/hex/ecs/ECSEngine.hpp"
#endif // !HEX_ECS_ENGINE_HPP

// Include ecs::EventsManager
#ifndef HEX_ECS_EVENTS_MANAGER_HPP
#include "../../../public/hex/ecs/events/EventsManager.hpp"
#endif // !HEX_ECS_EVENTS_MANAGER_HPP

// Include hex::ecs::memory
#ifndef HEX_ECS_DEBUG_HPP
#include "../../../public/hex/ecs/types/ecs_memory.hpp"
#endif // !HEX_ECS_DEBUG_HPP

// DEBUG
#if defined( DEBUG ) || defined( HEX_DEBUG )

// Include debug
#ifndef HEX_ECS_DEBUG_HPP
#include "../../../public/hex/ecs/types/ecs_debug.hpp"
#endif // !HEX_ECS_DEBUG_HPP

#endif
// DEBUG

// ===========================================================
// TYPES
// ===========================================================

namespace hex
{

    namespace ecs
    {

        // -----------------------------------------------------------

        // ===========================================================
        // FIELDS
        // ===========================================================

        ECSEngine* ECSEngine::mInstance( nullptr );

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        ECSEngine::ECSEngine()
            : mIDStoragesMutex(),
            mIDStorages()
        {
        }

        ECSEngine::~ECSEngine() noexcept = default;

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        ECSEngine::id_storages_t& ECSEngine::getIDStorage( const ecs_TypeID pTypeID )
        {
            ecs_lock_t lock( &mIDStoragesMutex );

            return mIDStorages[pTypeID];
        }

        // ===========================================================
        // METHODS
        // ===========================================================

        void ECSEngine::Initialize() noexcept
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            ecsLog::printInfo( u8"ECSEngine::Initialize" );
            ecsAssert( !mInstance && "ECS Instance already created, check logic" );
#endif // DEBUG

            // Initialize EventsManager
            ecs_Events::Initialize();
            
            if ( !mInstance )
                mInstance = ecsNew<ECSEngine>();
        }

        void ECSEngine::Terminate() noexcept
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            ecsLog::printInfo( u8"ECSEngine::Terminate" );
#endif // DEBUG

            // Terminate EventsManager
            ecs_Events::Terminate();

            ecsDelete( mInstance );
            mInstance = nullptr;
        }

        ecs_ObjectID ECSEngine::generateID( const ecs_TypeID pTypeID )
        {
            if ( mInstance )
            {
                id_storages_t& idStorage( mInstance->getIDStorage(pTypeID) );
                return idStorage.generateID();
            }

            return ECS_INVALID_OBJECT_ID;
        }

        void ECSEngine::releaseID( const ecs_TypeID pTypeID, const ecs_ObjectID pID ) noexcept
        {
            if ( mInstance )
            {
                id_storages_t& idStorage( mInstance->getIDStorage( pTypeID ) );
                idStorage.returnID( pID );
            }
        }

        // -----------------------------------------------------------

    }

}

// -----------------------------------------------------------
