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

#ifndef HEX_CORE_I_MUTEX_HXX
#define HEX_CORE_I_MUTEX_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::api
#ifndef HEX_CORE_API_HPP
#include "../../configs/hex_api.hpp"
#endif // !HEX_CORE_API_HPP

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
         * IMutex - mutex interface. Used to describe mutex basic behavior,
         * with STL-mutex compatability in mind.
        **/
        class IMutex
        {

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * IMutex destructor.
             *
             * @throws - no exceptions.
            **/
            virtual ~IMutex() HEX_NOEXCEPT
            {
            }

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Check if this mutex is locked.
             *
             * @thread_safety - thread-safe (atomic, not thread-lock).
             * @throws - no exceptions.
            **/
            virtual bool isLocked() const HEX_NOEXCEPT = 0;

            /**
             * @brief
             * Returns native handler.
             *
             * @thread_safety - not thread-safe.
             * @throws - no exceptions.
            **/
            virtual void* native_handle() HEX_NOEXCEPT = 0;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Tries to lock this mutex.
             *
             * @thread_safety - thread-safe (atomic, not thread-lock).
             * @returns - 'true' if locked, 'false' if failed.
             * @throws - (!) no exceptions
            **/
            virtual bool try_lock() HEX_NOEXCEPT = 0;

            /**
             * @brief
             * Lock this mutex.
             *
             * @thread_safety - thread-safe (atomic, no locks).
             * @throws - can throw exception (self-lock, etc).
            **/
            virtual void lock() = 0;

            /**
             * @brief
             * Unlock this mutex.
             *
             * @thread_safety - thread-safe (atomics, no locks).
             * @throws - no exceptions.
            **/
            virtual void unlock() HEX_NOEXCEPT = 0;

            // -----------------------------------------------------------

        }; /// hex::core::IMutex

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

#define HEX_CORE_I_MUTEX_DECL
using hex_IMutex = hex::core::IMutex;

// -----------------------------------------------------------

#endif // !HEX_CORE_I_MUTEX_HXX
