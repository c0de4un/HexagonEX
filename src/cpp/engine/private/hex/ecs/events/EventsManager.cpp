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
#ifndef HEX_ECS_EVENTS_MANAGER_HPP
#include "../../../../public/hex/ecs/events/EventsManager.hpp"
#endif // !HEX_ECS_EVENTS_MANAGER_HPP

// Include ecs::IEvent
#ifndef HEX_ECS_I_EVENT_HXX
#include "../../../../public/hex/ecs/events/IEvent.hxx"
#endif // !HEX_ECS_I_EVENT_HXX

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
// hex::ecs::EventsManager
// ===========================================================

namespace hex
{

    namespace ecs
    {

        // -----------------------------------------------------------

        // ===========================================================
        // FIELDS
        // ===========================================================

        EventsManager* EventsManager::mInstance( nullptr );

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        EventsManager::EventsManager()
            : mIDStorageMutex(),
            mIDStorages()
        {
        }

        EventsManager::~EventsManager() ECS_NOEXCEPT = default;

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        EventsManager* EventsManager::getInstance() noexcept
        { return mInstance; }

        EventsManager::id_storages_t& EventsManager::getIDStorage( const ecs_EventTypeID pTypeID )
        {
            ecs_lock_t lock( &mIDStorageMutex );
            return mIDStorages[pTypeID];
        }

        // ===========================================================
        // METHODS
        // ===========================================================

        void EventsManager::Initialize()
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
                ecsLog::printInfo( "EventsManager::Initialize" );
#endif // DEBUG

            if ( !mInstance )
                mInstance = ecsNew<EventsManager>();
        }

        void EventsManager::Terminate() noexcept
        {
#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
                ecsLog::printInfo( "EventsManager::Terminate" );
#endif // DEBUG

            ecsDelete( mInstance );
            mInstance = nullptr;
        }

        ecs_ObjectID EventsManager::generateEventID( const ecs_EventTypeID pType )
        {
            EventsManager* const instance( getInstance() );

#if defined( DEBUG ) || defined( HEX_DEBUG ) // DEBUG
            ecsAssert( instance && "EventsManager::generateEventID: not initialized !" );
#endif // DEBUG

            if ( instance )
            {
                ecs_lock_t lock( &instance->mIDStorageMutex );
                id_storages_t& idStorage( instance->getIDStorage(pType) );
                return idStorage.generateID();
            }

            return ECS_INVALID_OBJECT_ID;
        }

        void EventsManager::releaseEventID( const ecs_EventTypeID pType, const ecs_ObjectID pID ) noexcept
        {
            EventsManager* const instance( getInstance() );

            if ( instance )
            {
                ecs_lock_t lock( &instance->mIDStorageMutex );
                id_storages_t& idStorage( instance->getIDStorage(pType) );
                idStorage.returnID( pID );
            }
        }

        // -----------------------------------------------------------

    }

}

// -----------------------------------------------------------
