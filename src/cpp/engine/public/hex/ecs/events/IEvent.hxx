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

#ifndef HEX_ECS_I_EVENT_HXX
#define HEX_ECS_I_EVENT_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ecs::types
#ifndef HEX_ECS_TYPES_HPP
#include "../types/ecs_types.hpp"
#endif // !HEX_ECS_TYPES_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace hex
{

    namespace ecs
    {

        // -----------------------------------------------------------

        // ===========================================================
        // ecs::IEvent
        // ===========================================================

        /**
         * @brief
         * IEvent - Event-intarface.
         * 
         * @version 1.0
        */
        class IEvent
        {

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            virtual ~IEvent() ECS_NOEXCEPT
            {
            }

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns Type-ID.
             * 
             * @thread_safety - not required.
             * @throws - no exxceptions.
            **/
            virtual ecs_EventTypeID getTypeID() const noexcept = 0;

            /**
             * @brief
             * Retursn Event ID.
             * 
             * @thread_safety - not required.
             * @throws - no exceptions.
            **/
            virtual ecs_ObjectID getID() const noexcept = 0;

            /**
             * @brief
             * Returns 'true' if Event is handled.
             * 
             * @thread_safety - atomics used.
             * @throws - no exceptions.
            **/
            virtual bool isHandled() const ECS_NOEXCEPT = 0;

            // ===========================================================
            // METHODS
            // ===========================================================

            // -----------------------------------------------------------

        }; /// hex::ecs::IEvent

        // -----------------------------------------------------------

    } /// hex::ecs

} /// hex

using ecs_IEvent = hex::ecs::IEvent;
#define HEX_ECS_I_EVENT_DECL

// -----------------------------------------------------------

#endif // !HEX_ECS_I_EVENT_HXX