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

#ifndef HEX_CORE_ENGINE_HPP
#define HEX_CORE_ENGINE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::core::IEngine
#ifndef HEX_CORE_I_ENGINE_HXX
#include "IEngine.hxx"
#endif // !HEX_CORE_I_ENGINE_HXX

// Include ecs::System
#ifndef HEX_ECS_SYSTEM_HPP
#include "../../ecs/systems/System.hpp"
#endif // !HEX_ECS_SYSTEM_HPP

// Include hex::mutex
#ifndef HEX_CORE_CONFIG_MUTEX_HPP
#include "../configs/hex_mutex.hpp"
#endif // !HEX_CORE_CONFIG_MUTEX_HPP

// Include hex::memory
#ifndef HEX_CORE_CONFIG_MEMORY_HPP
#include "../configs/hex_memory.hpp"
#endif // !HEX_CORE_CONFIG_MEMORY_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace hex
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // hex::core::Engine
        // ===========================================================

        /**
         * @brief
         * Engine - base engine class.
         * 
         * @version 1.0
        **/
        class Engine : public hex_IEngine, public ecs_System
        {

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** Engine instance. **/
            static hex_sptr<Engine> mInstance;

            // ===========================================================
            // GETTERS & SETTERS: hex::ecs::System
            // ===========================================================

            // ===========================================================
            // OVERRIDE: hex::ecs::System
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
            void onTerminate() noexcept;

            // ===========================================================
            // DELETED
            // ===========================================================

            Engine(const Engine&) noexcept = delete;
            Engine& operator=(const Engine&) noexcept = delete;
            Engine(Engine&&) noexcept = delete;
            Engine& operator=(Engine&&) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * Engine constructor.
             * 
             * @throws - can throw exception.
            **/
            explicit Engine();

            /**
             * @brief
             * Engine destructor.
             * 
             * @throws - no exception.
            **/
            virtual ~Engine() noexcept;

            // ===========================================================
            // GETTERS & SETTERS: hex::core::IEngine
            // ===========================================================

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns Engine instance.
             * 
             * @thread_safety - atomics used.
             * @throws - no exceptions.
            **/
            static hex_sptr<Engine> getInstance() noexcept;

            // ===========================================================
            // OVERRIDE: hex::core::IEngine
            // ===========================================================

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Initialize Engine.
             * 
             * @thread_safety - main thread only
             * @param pInstance - IEngine instance
             * @return IEngine
            **/
            static hex_sptr<Engine> Initialize( hex_sptr<Engine> pInstance );

            /**
             * @brief
             * Terminate Engine instance.
             * 
             * @thread_safety - not thread-safe
             * @throws - no exceptions
            **/
            static void Terminate() noexcept;

            // -----------------------------------------------------------

        }; /// hex::core::Engine

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

using hex_Engine = hex::core::Engine;

#define HEX_CORE_ENGINE_DECL

// -----------------------------------------------------------

#endif // !HEX_CORE_ENGINE_HPP
