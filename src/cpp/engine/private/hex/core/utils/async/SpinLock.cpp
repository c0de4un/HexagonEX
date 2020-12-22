/**
 * Copyright � 2020 Denis Z. (code4un@yandex.ru) All rights reserved.
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

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#ifndef HEX_CORE_SPIN_LOCK_HPP
#include "../../../public/hex/core/utils/async/SpinLock.hpp"
#endif // !HEX_CORE_SPIN_LOCK_HPP

// DEBUG
#if defined( DEBUG ) || defined(HEX_DEBUG)

// Include hex::assert
#ifndef HEX_CORE_CONFIG_ASSERT_HPP
#include "../../../public/hex/core/configs/hex_assert.hpp"
#endif // !HEX_CORE_CONFIG_ASSERT_HPP
#endif

// DEBUG

// ===========================================================
// hex::core::SpinLock
// ===========================================================

namespace hex
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        SpinLock::SpinLock()
            : BaseLock()
        {
        }

        SpinLock::SpinLock( hex_IMutex* const pMutex )
            : BaseLock( pMutex )
        {
            lock();
        }

        SpinLock::~SpinLock() HEX_NOEXCEPT
        {
            unlock();
        }

        // ===========================================================
        // OVERRIDE: hex::core::BaseLock
        // ===========================================================

        bool SpinLock::try_lock( hex_IMutex* const pMutex )
        {
#ifdef HEX_DEBUG // DEBUG
            hex_assert( ( mMutex || pMutex ) && "SpinLock::try_lock - null mutex !" );
#endif // DEBUG

            if ( pMutex )
            {
                this->unlock();
                mMutex = pMutex;
            }

            for ( unsigned char i = 0; i < SPIN_LIMIT; i++ )
            {
                if ( !mMutex->isLocked() )
                {
                    break;
                }
            }

            return mMutex->try_lock();
        }

        void SpinLock::lock( hex_IMutex* const pMutex )
        {
#ifdef HEX_DEBUG // DEBUG
            hex_assert( ( mMutex || pMutex ) && "SpinLock::lock - null mutex !" );
#endif // DEBUG

            if ( pMutex )
            {
                this->unlock();
                mMutex = pMutex;
            }

            for ( unsigned char i = 0; i < SPIN_LIMIT; i++ )
            {
                if ( !mMutex->isLocked() )
                {
                    break;
                }
            }

            mMutex->lock();
        }

        void SpinLock::unlock() HEX_NOEXCEPT
        {
            if ( mMutex && mMutex->isLocked() )
                mMutex->unlock();
        }

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

// -----------------------------------------------------------
