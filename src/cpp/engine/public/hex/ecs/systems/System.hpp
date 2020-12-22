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

#ifndef HEX_ECS_SYSTEM_HPP
#define HEX_ECS_SYSTEM_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::ecs::ISsystem
#ifndef HEX_ECS_I_SYSTEM_HXX
#include "ISystem.hxx"
#endif // !HEX_ECS_I_SYSTEM_HXX

// Include ecs::mutex
#ifndef HEX_ECS_MUTEX_HPP
#include "../types/ecs_mutex.hpp"
#endif // !HEX_ECS_MUTEX_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace hex
{

    namespace ecs
    {

        // -----------------------------------------------------------

        /**
         * @brief
         * System - base System class.
         *
         * @version 1.0
        **/
        class System : public ecs_ISystem
        {

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // TYPES
            // ===========================================================

            using system_state_t = unsigned char;

            // ===========================================================
            // CONSTANTS
            // ===========================================================

            static constexpr const system_state_t SYSTEM_STATE_NOT_STARTED = 0;
            static constexpr const system_state_t SYSTEM_STATE_STARTING = 1;
            static constexpr const system_state_t SYSTEM_STATE_STARTED = 2;
            static constexpr const system_state_t SYSTEM_STATE_PAUSING = 3;
            static constexpr const system_state_t SYSTEM_STATE_PAUSED = 4;
            static constexpr const system_state_t SYSTEM_STATE_RESUMING = 5;
            static constexpr const system_state_t SYSTEM_STATE_STOPPING = 6;
            static constexpr const system_state_t SYSTEM_STATE_STOPPED = 7;

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** State Mutex. **/
            mutable ecs_mutex_t mStateMutex;

            /** Current System State. **/
            system_state_t mCurrentState;

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            /**
             * @brief
             * System constructor.
             * 
             * @param pType - Type-ID.
             * @throws - can throw exception.
            **/
            explicit System( const ecs_TypeID pType );

            // ===========================================================
            // DELETED
            // ===========================================================

            System( const System& ) noexcept = delete;
            System& operator=( const System& ) noexcept = delete;
            System( System&& ) noexcept = delete;
            System& operator=( System&& ) noexcept = delete;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Called to Start.
             * 
             * @thread_safety - thread-lock used
             * @throws - can throw exception
             * @return - 0 if OK
            **/
            virtual int onStart();

            /**
             * @brief
             * Called to Resume.
             * 
             * @thread_safety - thread-lock used
             * @throws - can throw exception
             * @return - 0 if OK
            **/
            virtual int onResume();

            /**
             * @brief
             * Called to Pause.
             * 
             * @thread_safety - thread-lock used
             * @throws - no exceptions.
            **/
            virtual void onPause() noexcept;

            /**
             * @brief
             * Called to Stop.
             * 
             * @thread_safety - thread-lock used
             * @throws - no exceptions.
            **/
            virtual void onStop() noexcept;

            /**
             * @brief
             * Called on Termiation.
             * 
             * @thread_safety - thread-locks used.
             * @throws - no exceptions.
            **/
            virtual void onTerminate() noexcept;

            /**
             * @brief
             * Generates ID for instance of this ECS Type.
             * 
             * @thread_safety - thread-locks used.
             * @param pType - ECS Type-ID.
             * @returns - ID.
             * @throws - can throw exception.
            **/
            static ecs_ObjectID generateSystemID( const ecs_TypeID pType );

            /**
             * @brief
             * Release ID of instance.
             * 
             * @thread_safety - thread-locks used.
             * @param pType - ECS Type-ID.
             * @param pID - ECS Object-ID.
             * @throws - no exceptions.
            **/
            static void releaseSystemID( const ecs_TypeID pType, const ecs_ObjectID pID );

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTANTS
            // ===========================================================

            /** ECS Type-ID. **/
            const ecs_TypeID mTypeID;

            /** ECS Object-ID. **/
            const ecs_ObjectID mID;

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * System destructor.
             *
             * @throws - no exceptions.
            **/
            virtual ~System() noexcept;

            // ===========================================================
            // ecs::ISystem: GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns ECS Type-ID.
             *
             * @thread_safety - not required.
             * @throws - no exceptions.
            **/
            virtual ecs_TypeID getTypeID() const noexcept final;

            /**
             * @brief
             * Returns ECS Object-ID.
             *
             * @thread_safety - not required.
             * @throws - no exceptions.
            **/
            virtual ecs_ObjectID getID() const noexcept final;

            /**
             * @brief
             * Returns 'true' if System is Started (initialized).
             * 
             * @thread_safety - thread-locks or atomics are used.
             * @throws - no exceptions.
            **/
            virtual bool isStarted() const noexcept final;

            /**
             * @brief
             * Returns 'true' if System is Paused.
             * 
             * @thread_safety - thread-locks or atomics are used.
             * @throws - no exceptions.
            **/
            virtual bool isPaused() const noexcept final;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Start System.
             *
             * @thread_safety - thread-locks used.
             * @return - 0 if OK.
             * @throws - can throw exception.
            **/
            virtual int Start() final;

            /**
             * @brief
             * Pause System.
             * 
             * @thread_safety - thread-lock used.
             * @throws - can throw exception.
            **/
            virtual void Pause() final;

            /**
             * @brief
             * Stop System.
             *
             * @thread_safety - thread-locks used.
             * @throws - no exceptions.
            **/
            virtual void Stop() noexcept final;

            // -----------------------------------------------------------

        };

        // -----------------------------------------------------------

    } /// hex::ecs

} /// hex

using ecs_System = hex::ecs::System;
#define HEX_ECS_SYSTEM_DECL

// -----------------------------------------------------------

#endif // !HEX_ECS_SYSTEM_HPP
