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

#ifndef HEX_ECS_ENGINE_HPP
#define HEX_ECS_ENGINE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ecs::types
#ifndef HEX_ECS_TYPES_HPP
#include "types/ecs_types.hpp"
#endif // !HEX_ECS_TYPES_HPP

// Include hex::ecs::IDStorage
#ifndef HEX_ECS_ID_STORAGE_HPP
#include "utils/IDStorage.hpp"
#endif // !HEX_ECS_ID_STORAGE_HPP

// STATIC-DEBUG ONLY
#include "events/EventsManager.hpp"
// STATIC-DEBUG ONLY

// ===========================================================
// TYPES
// ===========================================================

namespace hex
{

    namespace ecs
    {

        /**
         * @brief
         * ECSEngine - ecs implementation adapter.
         * Allows to easilly change ECS implementation.
         * 
         * @version 0.1
        **/
        class ECSEngine final
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

            /** ECSEngine instance. **/
            static ECSEngine* mInstance;

            /** ID-Storages Mutex. **/
            ecs_mutex_t mIDStoragesMutex;

            /** IDStorages **/
            ecs_map_t<ecs_TypeID, id_storages_t> mIDStorages;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns ID-Storage.
             * 
             * @thread_safety - thread-lock used.
             * @param pTypeID - ECS Type-ID.
             * @throws - can throw exception (bad-alloc, mutex).
            **/
            id_storages_t& getIDStorage( const ecs_TypeID pTypeID );

            // ===========================================================
            // DELETED
            // ===========================================================

            ECSEngine( const ECSEngine& ) noexcept = delete;
            ECSEngine& operator=( const ECSEngine& ) noexcept = delete;
            ECSEngine( ECSEngine&& ) noexcept = delete;
            ECSEngine& operator=( ECSEngine&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * ECSEngine default constructor.
             *
             * @throws - can throw exception (mutex, bad-alloc).
            **/
            explicit ECSEngine();

            /**
             * @brief
             * ECSEngine destructor.
             * 
             * @throws - no exceptions.
            **/
            ~ECSEngine() noexcept;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Initialize ECS.
             *
             * @throws - no exceptions.
            **/
            static void Initialize() noexcept;

            /**
             * @brief
             * Terminate ECS.
             *
             * @throws - no exceptions.
            **/
            static void Terminate() noexcept;

            /**
             * @brief
             * Generates Object-ID.
             * 
             * @thread_safety - thread-locks used.
             * @param pTypeID - ECS Type-ID.
             * @returns - Object-ID.
             * @throws - can throw exception (mutex).
            **/
            static ecs_ObjectID generateID( const ecs_TypeID pTypeID );

            /**
             * @brief
             * Release ID for reusage.
             * 
             * @thread_safety - thread-locks used.
             * @param pTypeID - ECS Type-ID.
             * @param pID - ECS Object-ID.
             * @throws - no exceptions.
            **/
            static void releaseID( const ecs_TypeID pTypeID, const ecs_ObjectID pID ) noexcept;

            // -----------------------------------------------------------

        };

    } /// hex::ecs

} /// hex

using hex_ECS = hex::ecs::ECSEngine;

// -----------------------------------------------------------

#endif // !HEX_ECS_ENGINE_HPP
