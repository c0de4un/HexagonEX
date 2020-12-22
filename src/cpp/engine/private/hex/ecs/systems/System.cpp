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
#ifndef HEX_ECS_SYSTEM_HPP
#include "../../../../public/hex/ecs/systems/System.hpp"
#endif // !HEX_ECS_SYSTEM_HPP

// Include ecs::Enigne
#ifndef HEX_ECS_ENGINE_HPP
#include "../../../../public/hex/ecs/ECSEngine.hpp"
#endif // !HEX_ECS_ENGINE_HPP

// DEBUG
#if defined( DEBUG ) || defined( HEX_DEBUG )

// Include debug
#ifndef HEX_ECS_DEBUG_HPP
#include "../../../../public/hex/ecs/types/ecs_debug.hpp"
#endif // !HEX_ECS_DEBUG_HPP

#endif
// DEBUG

// ===========================================================
// hex::ecs::System
// ===========================================================

namespace hex
{

    namespace ecs
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        System::System( const ecs_TypeID pType )
            : mStateMutex(),
            mCurrentState( System::SYSTEM_STATE_NOT_STARTED ),
            mTypeID( pType ),
            mID( generateSystemID(pType) )
        {
        }

        System::~System() noexcept
        {
            Stop();
            releaseSystemID( mTypeID, mID );
        }

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        ecs_TypeID System::getTypeID() const noexcept
        { return mTypeID; }

        ecs_ObjectID System::getID() const noexcept
        { return mID; }

        // ===========================================================
        // METHODS
        // ===========================================================

        int System::Start()
        {
            int result( 0 );

            ecs_lock_t stateLock( &mStateMutex );

            if ( mCurrentState == SYSTEM_STATE_NOT_STARTED || mCurrentState == SYSTEM_STATE_STOPPED )
            {
                mCurrentState = SYSTEM_STATE_STARTING;
                stateLock.unlock();

                result = onStart();
            }
            else if ( mCurrentState == SYSTEM_STATE_PAUSED )
            {
                mCurrentState = SYSTEM_STATE_RESUMING;
                stateLock.unlock();

                result = onResume();

                stateLock.lock();
                mCurrentState = result == 0 ? SYSTEM_STATE_STARTED : SYSTEM_STATE_NOT_STARTED;
            }

            return result;
        }

        void System::Pause()
        {
            ecs_lock_t stateLock( &mStateMutex );

            if ( mCurrentState > SYSTEM_STATE_STARTED && mCurrentState < SYSTEM_STATE_PAUSING )
            {
                mCurrentState = SYSTEM_STATE_PAUSING;
                stateLock.unlock();

                onPause();

                stateLock.lock();
                mCurrentState = SYSTEM_STATE_PAUSED;
            }
        }

        void System::Stop() noexcept
        {
            ecs_lock_t stateLock( &mStateMutex );

            if ( mCurrentState > SYSTEM_STATE_NOT_STARTED
                && mCurrentState < SYSTEM_STATE_STOPPING )
                {
                    mCurrentState = SYSTEM_STATE_STOPPING;
                    stateLock.unlock();

                    onStop();

                    stateLock.lock();
                    mCurrentState = SYSTEM_STATE_STOPPED;
                }
        }

        ecs_ObjectID System::generateSystemID( const ecs_TypeID pType )
        { return ECSEngine::generateID( pType ); }

        void System::releaseSystemID( const ecs_TypeID pType, const ecs_ObjectID pID )
        { ECSEngine::releaseID( pType, pID ); }

        int System::onStart()
        {
            return 0;
        }

        int System::onResume()
        {
            return 0;
        }

        void System::onPause() noexcept
        {

        }

        void System::onStop() noexcept
        {

        }

        void System::onTerminate() noexcept
        {
        }

        // ===========================================================
        // ecs::ISystem: GETTERS & SETTERS
        // ===========================================================

        bool System::isStarted() const noexcept
        {
            ecs_lock_t lock( &mStateMutex );
            return mCurrentState > SYSTEM_STATE_NOT_STARTED && mCurrentState < SYSTEM_STATE_STOPPED;
        }

        bool System::isPaused() const noexcept
        {
            ecs_lock_t lock( &mStateMutex );
            return mCurrentState > SYSTEM_STATE_STARTED && mCurrentState != SYSTEM_STATE_RESUMING;
        }

        // -----------------------------------------------------------

    } /// hex::ecs

} /// hex

// -----------------------------------------------------------
