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
            // FIELDS
            // ===========================================================

            

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
            static void releaseSystemID( const ecs_TypeID pType, const ecs_ObjectID pID ) ECS_NOEXCEPT;

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
            virtual ~System() ECS_NOEXCEPT;

            // ===========================================================
            // GETTERS & SETTERS
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
             * Stop System.
             *
             * @thread_safety - thread-locks used.
             * @throws - no exceptions.
            **/
            virtual void Stop() ECS_NOEXCEPT final;

            // -----------------------------------------------------------

        };

        // -----------------------------------------------------------

    } /// hex::ecs

} /// hex

using ecs_System = hex::ecs::System;
#define HEX_ECS_SYSTEM_DECL

// -----------------------------------------------------------

#endif // !HEX_ECS_SYSTEM_HPP
