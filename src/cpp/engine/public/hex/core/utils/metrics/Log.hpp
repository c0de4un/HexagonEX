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

#ifndef HEX_CORE_LOG_HPP
#define HEX_CORE_LOG_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

 // Include hex::log
#ifndef HEX_CORE_CONFIG_LOG_HPP
#include "../../configs/hex_log.hpp"
#endif // !HEX_CORE_CONFIG_LOG_HPP

// ===========================================================
// FORWARD-DECLARATION
// ===========================================================

// Forward-Declare hex::core::ILog
#ifndef HEX_CORE_I_LOG_DECL
#define HEX_CORE_I_LOG_DECL
namespace hex { namespace core { class ILog; } }
#endif // !HEX_CORE_I_LOG_DECL

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
         * Log - base Log.
         *
         * @version 1.0
        **/
        class Log final
        {

            // -----------------------------------------------------------

            // ===========================================================
            // META
            // ===========================================================

            HEX_CLASS

            // -----------------------------------------------------------
        
        private:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            static ILog* mInstance;

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            explicit Log();

            // ===========================================================
            // DELETED
            // ===========================================================

            Log(const Log&) noexcept = delete;
            Log& operator=(const Log&) noexcept = delete;
            Log(Log&&) noexcept = delete;
            Log& operator=(Log&&) = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            virtual ~Log() noexcept;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Sets ILog instance to use.
             *
             * @thread_safety - main thread only.
             * @param pInstance - ILog instance. Automatically deleted on #Terminate(void).
             * @throws - no exceptions.
            **/
            static void setInstance(ILog* const pInstance) noexcept;

            /**
             * @brief
             * Returns ILog instance.
             *
             * @thread_safety - not thread-safe.
             * @return ILog
             * @throws - no exceptions.
            **/
            static ILog* getInstance() noexcept;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Terminate Log instance.
             * 
             * @thread_safety - main thread only.
             * @throws - no exceptions.
            **/
            static void Terminate() noexcept;

            /**
             * @brief
             * Prints INFO (GOOD) Level Log-Message.
             * 
             * @thread_safety - thread-safe.
             * @param pMsg - log-message as c-string (UTF-8 multibyte supported).
             * @throws - no exceptions.
            **/
            static void printInfo( const char* const pMsg ) noexcept;

            /**
             * @brief
             * Prints DEBUG (NORMAL/VERBOSE) Level Log-Message.
             *
             * @thread_safety - thread-safe.
             * @param pMsg - log-message as c-string (UTF-8 multibyte supported).
             * @throws - no exceptions.
            **/
            static void printDebug(const char* const pMsg) noexcept;

            /**
             * @brief
             * Prints WARNING Level Log-Message.
             *
             * @thread_safety - thread-safe.
             * @param pMsg - log-message as c-string (UTF-8 multibyte supported).
             * @throws - no exceptions.
            **/
            static void printWarning(const char* const pMsg) noexcept;

            /**
             * @brief
             * Prints ERROR (FATAL/CRITICAL) Level Log-Message.
             *
             * @thread_safety - thread-safe.
             * @param pMsg - log-message as c-string (UTF-8 multibyte supported).
             * @throws - no exceptions.
            **/
            static void printError(const char* const pMsg) noexcept;

            // -----------------------------------------------------------

        }; /// hex::core::Log

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

#define HEX_CORE_LOG_DECL

using hex_Log = hex::core::Log;

// -----------------------------------------------------------

#endif // !HEX_CORE_LOG_HPP
