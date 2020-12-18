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

#ifndef HEX_ECS_EVENT_HPP
#define HEX_ECS_EVENT_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ecs::IEvent
#ifndef HEX_ECS_I_EVENT_HXX
#include "IEvent.hxx"
#endif // !HEX_ECS_I_EVENT_HXX

// Include ecs::atomic
#ifndef HEX_ECS_ATOMIC_HPP
#include "../types/ecs_atomic.hpp"
#endif // !HEX_ECS_ATOMIC_HPP

// Include ecs::vector
#ifndef HEX_ECS_VECTOR_HPP
#include "../types/ecs_vector.hpp"
#endif // !HEX_ECS_VECTOR_HPP

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

        // ===========================================================
        // ecs::Event
        // ===========================================================

        /**
         * @brief
         * Event - base Event class.
         * 
         * @version 1.0
        **/
        class Event : public ecs_IEvent
        {

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTANTS
            // ===========================================================

            /**
             * @brief
             * Boolean-flag ids.
             */
            static constexpr const unsigned int HANDLED_FLAG = 0;
            static constexpr const unsigned int HAS_ERROR_FLAG = 1;

            // -----------------------------------------------------------

        private:

            /** Initial flags bool-vector capacity. **/
            static constexpr const unsigned int DEFAULT_FLAGS_NUM = 2;

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** Common Access-Mutex. **/
            mutable ecs_mutex_t mMutex;

            /** Boolean-Flags. **/
            ecs_vector_t<bool> mFlags;

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            /**
             * @brief
             * Event constructor.
             * 
             * @param pTypeID - ECS Type-ID.
             * @param pFlags - amount of boolean-flags to allocate (bit-vector).
             * @throws - can throw exception:
             *           - bad_alloc;
             *           - mutex;
            **/
            explicit Event( const ecs_EventTypeID pTypeID, const unsigned char pFlags = DEFAULT_FLAGS_NUM );

            // ===========================================================
            // DELETED
            // ===========================================================

            Event( const Event& ) noexcept = delete;
            Event& operator=( const Event& ) noexcept = delete;
            Event( Event&& ) noexcept = delete;
            Event& operator=( Event&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTANTS
            // ===========================================================

            /** Event Type-ID. **/
            const ecs_EventTypeID mTypeID;

            /** Event ID. **/
            const ecs_ObjectID mID;

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * Event destructor.
             * 
             * @throws - no exceptions.
            **/
            virtual ~Event() ECS_NOEXCEPT;

            // ===========================================================
            // ecs::IEvent: GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns Type-ID.
             *
             * @thread_safety - not required.
             * @throws - no exxceptions.
            **/
            virtual ecs_EventTypeID getTypeID() const noexcept final;

            /**
             * @brief
             * Retursn Event ID.
             *
             * @thread_safety - not required.
             * @throws - no exceptions.
            **/
            virtual ecs_ObjectID getID() const noexcept final;

            /**
             * @brief
             * Returns 'true' if Event is handled.
             *
             * @thread_safety - atomics used.
             * @throws - no exceptions.
            **/
            virtual bool isHandled() const ECS_NOEXCEPT final;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief Get the Boolean Flag
             * 
             * @param pFlag - flag index.
             * @throws - can throw exception:
             *           - mutex;
             */
            bool getBooleanFlag( const unsigned int pFlag ) const;

            /**
             * @brief Set the Boolean Flag
             * 
             * @param pFlag - flag index/id
             * @param pValue - value
             * @throws - can throw exception:
             *           - mutex;
             *           - bad-alloc (vector);
             */
            void setBooleanFlag( const unsigned int pFlag, const bool pValue );

            // -----------------------------------------------------------

        }; /// hex::ecs::Event

        // -----------------------------------------------------------

    } /// hex::ecs

} /// hex

using ecs_Event = hex::ecs::Event;
#define HEX_ECS_EVENT_DECL

// -----------------------------------------------------------

#endif // !HEX_ECS_EVENT_HPP
