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
        class Application : public IApplication
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
            static Application* mInstance;

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            explicit Application();

            // ===========================================================
            // DELETED
            // ===========================================================

            Application(const Application&) noexcept = delete;
            Application& operator=(const Application&) noexcept = delete;
            Application(Application&&) noexcept = delete;
            Application& operator=(Application&&) noexcept = delete;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Called when Initialize called.
             *
             * @throws - no exceptions.
            **/
            virtual void onInitialize();

            /**
             * @brief
             * Called when Terminate called.
             * 
             * @throws - no exceptions.
            **/
            virtual void onTerminate() noexcept;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            virtual ~Application() noexcept;

            // ===========================================================
            // METHODS
            // ===========================================================

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

#define HEX_CORE_APPLICATION_DECL
using hexApp = hex::core::Application;

// -----------------------------------------------------------

#endif // !HEX_CORE_APPLICATION_HPP
