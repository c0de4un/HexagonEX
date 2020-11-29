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

#ifndef HEX_CORE_BIT_VEC_HPP
#define HEX_CORE_BIT_VEC_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::vector
#ifndef HEX_CONFIG_VECTOR_HPP
#include "../../configs/hex_vector.hpp"
#endif // !HEX_CONFIG_VECTOR_HPP

// Include hex::mutex
#ifndef HEX_CORE_CONFIG_MUTEX_HPP
#include "../../configs/hex_mutex.hpp"
#endif // !HEX_CORE_CONFIG_MUTEX_HPP

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
         * BitVec - container to bit-flags.
         * Basically just an adapter for STL vector, with mutex in design.
         * 
         * @version 1.0
        **/
        class BitVec
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** Mutex **/
            mutable hex_Mutex mMutex;

            /** Vector **/
            hex_vector_t<bool> mVec;

            // ===========================================================
            // DELETED
            // ===========================================================

            BitVec( const BitVec& ) noexcept = delete;
            BitVec& operator=( const BitVec& ) noexcept = delete;
            BitVec( BitVec&& ) noexcept = delete;
            BitVec& operator=( BitVec&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * BitVec constructor.
             * 
             * @param pCapacity - initial capacity. 0 for default.
             * @throws - can throw exception.
            **/
            explicit BitVec( const hex_size_t pCapacity = 0 )
                : mMutex(),
                mVec()
            {
                if ( pCapacity > 0  )
                    mVec.reserve( pCapacity );
            }

            /**
             * @brief
             * BitVec destructor.
             * 
             * @throws - no exceptions.
            **/
            ~BitVec() noexcept = default;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Return boolean (bit) value.
             * 
             * @thread_safety - thread-locks used.
             * @param pIndex - offset.
             * @param pDefault - default = false.
             * @throws - can throw exception (mutex).
            **/
            bool get( const hex_size_t pIndex, bool pDefault = false ) const
            {
                hex_lock_t lock( &mMutex );

                if ( mVec.size() < pIndex + 1 )
                {
                    mVec.reserve( pIndex + 1 );
                    mVec[pIndex] = pDefault;
                    return pDefault;
                }

                return mVec[pIndex];
            }

            /**
             * @brief
             * Sets bit (boolean) value.
             *
             * @thread_safety - thread-locks used.
             * @param pIndex - bit (boolean) offset.
             * @param pValue - value.
             * @throws - can throw exception (mutex).
            **/
            void set( const hex_size_t pIndex, const bool pValue )
            {
                hex_lock_t lock( &mMutex );

                if ( mVec.size() < pIndex + 1 )
                    mVec.reserve( pIndex + 1 );

                mVec[pIndex] = pValue;
            }

            // -----------------------------------------------------------

        }; /// hex::core::BitVec

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

using hex_BitVec = hex::core::BitVec;

#define HEX_CORE_BIT_VEC_DECL

// -----------------------------------------------------------

#endif // !HEX_CORE_BIT_VEC_HPP
