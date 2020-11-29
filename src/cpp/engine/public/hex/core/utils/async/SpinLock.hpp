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

#ifndef HEX_CORE_SPIN_LOCK_HPP
#define HEX_CORE_SPIN_LOCK_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::core::BaseLock
#ifndef HEX_CORE_BASE_LOCK_HPP
#include "BaseLock.hpp"
#endif // !HEX_CORE_BASE_LOCK_HPP

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
         * SpinLock - simple spin-lock.
         * 
         * @version 1.4
        **/
        class SpinLock final : public hex_BaseLock
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // DELETED
            // ===========================================================

            SpinLock( const SpinLock& ) noexcept = delete;
            SpinLock& operator=( const SpinLock& ) noexcept = delete;
            SpinLock( SpinLock&& ) noexcept = delete;
            SpinLock& operator=( SpinLock&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            /** Spin limit. **/
            static unsigned char const constexpr SPIN_LIMIT = 2;

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * SpinLock constructor.
             *
             * @throws - can throw exception:
             * - mutex exception;
             * - out-of-memory exception;
            **/
            explicit SpinLock();

            /**
             * @brief
             * SpinLock constructor with mutex to lock.
             *
             * @param pMutex - IMutex (not managed by instance).
             * @throws - can throw exception:
             * - mutex exception;
             * - out-of-memory exception;
            **/
            explicit SpinLock( hex_IMutex* const pMutex );

            /**
             * @brief
             * SpinLock destructor.
             * 
             * @throws - no exceptions.
            **/
            virtual ~SpinLock() HEX_NOEXCEPT;

            // ===========================================================
            // OVERRIDE: hex::core::BaseLock
            // ===========================================================

            /**
             * @brief
             * Try lock.
             *
             * @param pMutex - mutex to use (switch to).
             * @returns - 'true' if locked, 'false' if failed.
             * @throws - can throw exception.
            **/
            virtual bool try_lock( hex_IMutex* const pMutex = nullptr ) final;

            /**
             * @brief
             * Lock.
             *
             * @param pMutex - mutex to use (switch to).
             * @throws - can throw exception.
            **/
            virtual void lock( hex_IMutex* const pMutex = nullptr ) final;

            /**
             * @brief
             * Unlock.
             *
             * @throws - can throw exception.
            **/
            virtual void unlock() HEX_NOEXCEPT final;

            // -----------------------------------------------------------

        }; /// hex::core::SpinLock

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

using hex_SpinLock = hex::core::SpinLock;

// -----------------------------------------------------------

#endif // !HEX_CORE_SPIN_LOCK_HPP
