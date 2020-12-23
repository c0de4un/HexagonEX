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

#ifndef HEX_CORE_APPLICATION_HPP
#define HEX_CORE_APPLICATION_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::core::IApplication
#ifndef HEX_CORE_I_APPLICATION_HXX
#include "IApplication.hxx"
#endif // !HEX_CORE_I_APPLICATION_HXX

// Include ecs::System
#ifndef HEX_ECS_SYSTEM_HPP
#include "../../ecs/systems/System.hpp"
#endif // !HEX_ECS_SYSTEM_HPP

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

        /**
         * @brief
         * Application - base application class.
         * 
         * @version 1.0
        **/
        class Application : public IApplication, public ecs_System
        {

            // -----------------------------------------------------------

            // ===========================================================
            // META
            // ===========================================================

            HEX_CLASS

            // -----------------------------------------------------------

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTANTS & FIELDS
            // ===========================================================

            /** Application instance. **/
            static hex_sptr<Application> mInstance;

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            /**
             * @brief
             * Application constructor.
             * 
             * @throws - can throw exception.
            **/
            explicit Application();

            // ===========================================================
            // DELETED
            // ===========================================================

            Application(const Application&) noexcept = delete;
            Application& operator=(const Application&) noexcept = delete;
            Application(Application&&) noexcept = delete;
            Application& operator=(Application&&) noexcept = delete;

            // ===========================================================
            // OVERRIDE: ecs::System
            // ===========================================================

            /**
             * @brief
             * Called to Start.
             * 
             * @thread_safety - thread-lock used
             * @throws - can throw exception
             * @return - 0 if OK
            **/
            virtual int onStart() override;

            /**
             * @brief
             * Called to Resume.
             * 
             * @thread_safety - thread-lock used
             * @throws - can throw exception
             * @return - 0 if OK
            **/
            virtual int onResume() override;

            /**
             * @brief
             * Called to Pause.
             * 
             * @thread_safety - thread-lock used
             * @throws - no exceptions.
            **/
            virtual void onPause() noexcept override;

            /**
             * @brief
             * Called to Stop.
             * 
             * @thread_safety - thread-lock used
             * @throws - no exceptions.
            **/
            virtual void onStop() noexcept override;

            /**
             * @brief
             * Called on Termiation.
             * 
             * @thread_safety - thread-locks used.
             * @throws - no exceptions.
            **/
            virtual void onTerminate() noexcept override;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            virtual ~Application() noexcept;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns Application instance.
             * 
             * @thread_safety - not required.
             * @throws - no exceptions.
            **/
            static hex_sptr<Application> getInstance() noexcept;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Initialize Application instance.
             * 
             * @thread_safety - main thread only.
             * @param pInstance - Application instance to apply.
             * @return current Application instance.
            **/
            static hex_sptr<Application> Initialize( hex_sptr<Application> pInstance );

            /**
             * @brief
             * Terminate Application isntance.
             * 
             * (?)
             * All sub-systems (Graphics, Audio, Input, Threading) terminated along,
             * doesn't terminates log-susytem though.
             * 
             * @throws - no exceptions.
            **/
            static void Terminate() noexcept;

            // -----------------------------------------------------------

        }; /// hex::core::Application

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

using hex_App = hex::core::Application;

#define HEX_CORE_APPLICATION_DECL

// -----------------------------------------------------------

#endif // !HEX_CORE_APPLICATION_HPP
