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
#ifndef HEX_ECS_EVENT_HPP
#include "../../../../public/hex/ecs/events/Event.hpp"
#endif // !HEX_ECS_EVENT_HPP

// Include ecs::EventsManager
#ifndef HEX_ECS_EVENTS_MANAGER_HPP
#include "../../../../public/hex/ecs/events/EventsManager.hpp"
#endif // !HEX_ECS_EVENTS_MANAGER_HPP

// DEBUG
#if defined( DEBUG ) || defined( HEX_DEBUG )

// Include debug
#ifndef HEX_ECS_DEBUG_HPP
#include "../../../../public/hex/ecs/types/ecs_debug.hpp"
#endif // !HEX_ECS_DEBUG_HPP

#endif
// DEBUG

// ===========================================================
// ecs::Event
// ===========================================================

namespace hex
{

    namespace ecs
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        Event::Event( const ecs_EventTypeID pTypeID, const unsigned char pFlags )
            : mMutex(),
            mFlags(),
            mTypeID( pTypeID ),
            mID( ecs_Events::generateEventID(pTypeID) )

        {
            if ( pFlags > 0 )
                mFlags.reserve( pFlags );
        }

        Event::~Event() ECS_NOEXCEPT
        {
            ecs_Events::releaseEventID( mTypeID, mID );
        }

        // ===========================================================
        // ecs::IEvent: GETTERS & SETTERS
        // ===========================================================

        ecs_EventTypeID Event::getTypeID() const noexcept
        { return mTypeID; }

        ecs_ObjectID Event::getID() const noexcept
        { return mID; }

        bool Event::isHandled() const ECS_NOEXCEPT
        { return getBooleanFlag( Event::HANDLED_FLAG ); }

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        bool Event::getBooleanFlag( const unsigned int pFlag ) const
        {// @TODO: add assertions
            ecs_lock_t lock( &mMutex );
            return mFlags[pFlag];
        }

        void Event::setBooleanFlag( const unsigned int pFlag, const bool pValue )
        {// @TODO: add assertions
            ecs_lock_t lock( &mMutex );
            mFlags[pFlag] = pValue;
        }

        // -----------------------------------------------------------

    }

}

// -----------------------------------------------------------