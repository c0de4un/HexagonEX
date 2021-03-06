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

#ifndef HEX_ECS_SYSTEMS_MANAGER_HPP
#define HEX_ECS_SYSTEMS_MANAGER_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// ===========================================================
// TYPES
// ===========================================================

namespace hex
{

    namespace ecs
    {

        // -----------------------------------------------------------

        // ===========================================================
        // ecs::SystemsManager
        // ===========================================================

        /**
         * @brief
         * SystemsManager - handles System instances.
         * 
         * @version 1.5
        **/
        class SystemsManager final
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** SystemsManager instance. **/
            static SystemsManager* mInstance;

            // ===========================================================
            // DELETED
            // ===========================================================

            SystemsManager( const SystemsManager& ) noexcept = delete;
            SystemsManager& operator=( const SystemsManager& ) noexcept = delete;
            SystemsManager( SystemsManager&& ) noexcept = delete;
            SystemsManager& operator=( SystemsManager&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * SystemsManager constructor.
             * 
             * @throws bad_alloc
             * @throws mutex
            **/
            explicit SystemsManager();

            /**
             * @brief
             * SystemsManager destructor.
             * 
             * @throws - no exceptions.
            **/
            ~SystemsManager() noexcept;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns SystemsManager instance, or null.
             * 
             * @thread_safety - not required.
             * @throws - no exceptions.
            **/
            static SystemsManager* getInstance() noexcept;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Initialize SystemsManager.
             * 
             * @thread_safety - main thread only.
             * @throws - bad_alloc.
             * @throws - mutex.
            **/
            static void Initialize();

            /**
             * @brief
             * Terminate SystemsManager instance.
             * 
             * @thread_safety - not thread-safe.
             * @throws - no exceptions.
            **/
            static void Terminate() noexcept;

            // -----------------------------------------------------------

        }; /// hex::ecs::SystemsManager

        // -----------------------------------------------------------

    } /// hex::ecs

} /// hex

using ecs_Systems = hex::ecs::SystemsManager;

#define HEX_ECS_SYSTEMS_MANAGER_DECL

// -----------------------------------------------------------

#endif // !HEX_ECS_SYSTEMS_MANAGER_HPP
