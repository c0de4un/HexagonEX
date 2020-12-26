/**
 * Copyright © 2020 Denis Z. (code4un@yandex.ru) All rights reserved.
 * Authors: Denis Z. (code4un@yandex.ru)
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
 */

#ifndef HEX_CORE_I_LOCK_HXX
#define HEX_CORE_I_LOCK_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::core::IMutex
#ifndef HEX_CORE_I_MUTEX_HXX
#include "IMutex.hxx"
#endif // !HEX_CORE_I_MUTEX_HXX

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
         * ILock - thread-lock interface.
         * 
         * @version 1.2
        **/
        class ILock
        {

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * ILock destructor.
             * 
             * @throws - no exceptions.
            **/
            virtual ~ILock() HEX_NOEXCEPT = default;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Check if this lock is locked.
             *
             * @thread_safety - atomic-flag used.
             * @throws - no exceptions.
            **/
            virtual bool isLocked() HEX_NOEXCEPT = 0;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Try lock.
             *
             * @param pMutex - mutex to use (switch to).
             * @returns - 'true' if locked, 'false' if failed.
             * @throws - can throw exception.
            **/
            virtual bool try_lock( hex_IMutex* const pMutex = nullptr ) = 0;

            /**
             * @brief
             * Lock.
             *
             * @param pMutex - mutex to use (switch to).
             * @throws - can throw exception.
            **/
            virtual void lock( hex_IMutex* const pMutex = nullptr ) = 0;

            /**
             * @brief
             * Unlock.
             *
             * @throws - can throw exception.
            **/
            virtual void unlock() HEX_NOEXCEPT = 0;

            // -----------------------------------------------------------

        }; /// hex::core::ILock

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

#define HEX_CORE_I_LOCK_DECL

// -----------------------------------------------------------

#endif // !HEX_CORE_I_LOCK_HXX
