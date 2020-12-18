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

#ifndef HEX_ECS_EVENTS_MANAGER_HPP
#define HEX_ECS_EVENTS_MANAGER_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ecs::mutex
#ifndef HEX_ECS_MUTEX_HPP
#include "../types/ecs_mutex.hpp"
#endif // !HEX_ECS_MUTEX_HPP

// Include ecs::types
#ifndef HEX_ECS_TYPES_HPP
#include "../types/ecs_types.hpp"
#endif // !HEX_ECS_TYPES_HPP

// Include hex::ecs::IDStorage
#ifndef HEX_ECS_ID_STORAGE_HPP
#include "../utils/IDStorage.hpp"
#endif // !HEX_ECS_ID_STORAGE_HPP

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// Forward-Declare hex:;ecs::IEvent
#ifndef HEX_ECS_I_EVENT_DECL
#define HEX_ECS_I_EVENT_DECL
namespace hex { namespace ecs { class IEvent; } }
using ecs_IEvent = hex::ecs::IEvent;
#endif // !HEX_ECS_I_EVENT_DECL

// ===========================================================
// TYPES
// ===========================================================

namespace hex
{

    namespace ecs
    {

        // -----------------------------------------------------------

        // ===========================================================
        // ecs::EventsManager
        // ===========================================================

        /**
         * @brief
         * EventsManager - manage events queues.
         * 
         * @version 1.0
        **/
        class EventsManager final
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // TYPES
            // ===========================================================

            using id_storages_t = ecs_IDStorage<ecs_ObjectID>;

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** EventsManager instance. **/
            static EventsManager* mInstance;

            /** ID-Storage Mutex. **/
            ecs_mutex_t mIDStorageMutex;

            /** IDStorages **/
            ecs_map_t<ecs_EventTypeID, id_storages_t> mIDStorages;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns ID-Storage.
             * 
             * @thread_safety - thread-lock used.
             * @param pTypeID - Event Type-ID.
             * @throws - can throw exception (bad-alloc, mutex).
            **/
            id_storages_t& getIDStorage( const ecs_EventTypeID pTypeID );

            // ===========================================================
            // DELETED
            // ===========================================================

            EventsManager( const EventsManager& ) noexcept = delete;
            EventsManager& operator=( const EventsManager& ) noexcept = delete;
            EventsManager( EventsManager&& ) noexcept = delete;
            EventsManager& operator=( EventsManager&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief 
             * EventsManager constructor.
             * 
             * @throws bad-alloc
             * @throws mutex
             */
            explicit EventsManager();

            /**
             * @brief
             * EventsManager destructor.
             * 
             * @throws - no exceptions.
             */
            ~EventsManager() ECS_NOEXCEPT;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns EventsManager instance, or null.
             * 
             * @thread_safety - not required.
             * @throws - no exceptions.
             */
            static EventsManager* getInstance() noexcept;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Initialize EventsManager instance.
             * 
             * @thread_safety - call only from main-thread.
             * @throws bad-alloc
             * @throws mutex
             */
            static void Initialize();

            /**
             * @brief
             * Terminate EventsManager instance.
             * 
             * @thread_safety - call only from main-thread.
             * @throws - no exceptions.
             */
            static void Terminate() noexcept;

            /**
             * @brief 
             * Generates unique Event-instance ID.
             * 
             * @thread_safety - thread-lock used.
             * @param pType Event Type-ID
             * @return ecs_ObjectID Event-ID.
             */
            static ecs_ObjectID generateEventID( const ecs_EventTypeID pType );

            /**
             * @brief 
             * Release Event-ID for reusage.
             * 
             * @param pType Event Type-ID
             * @param pID - Event-ID
             * @throws no exceptions
             */
            static void releaseEventID( const ecs_EventTypeID pType, const ecs_ObjectID pID ) noexcept;

            // -----------------------------------------------------------

        }; /// hex::ecs::EventsManager

        // -----------------------------------------------------------

    } /// hex::ecs

} /// hex

using ecs_Events = hex::ecs::EventsManager;
#define HEX_ECS_EVENTS_MANAGER_DECL

// -----------------------------------------------------------

#endif // !HEX_ECS_EVENTS_MANAGER_HPP