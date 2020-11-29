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

#ifndef HEX_CORE_BIT_MAP_HPP
#define HEX_CORE_BIT_MAP_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::map
#ifndef HEX_CONFIG_MAP_HPP
#include "../../configs/hex_map.hpp"
#endif // !HEX_CONFIG_MAP_HPP

// Include hex::core::BitVec
#ifndef HEX_CORE_BIT_VEC_HPP
#include "BitVec.hpp"
#endif // !HEX_CORE_BIT_VEC_HPP

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
         * BitMap - container to store associative collection of bits.
         * For example, to store IDs per Type-ID.
         * 
         * @version 1.0
        **/
        template <typename T>
        class BitMap
        {

        private:

            // -----------------------------------------------------------

            static constexpr const hex_size_t DEFAULT_CAPACITY = 24;

            // ===========================================================
            // TYPES
            // ===========================================================

            /**
             * @brief
             * BitVecInfo - struct to encapsulate mutex & bits-vector access.
            **/
            struct BitVecInfo final
            {

                // -----------------------------------------------------------

                // ===========================================================
                // FIELDS
                // ===========================================================

                BitVec mVec;

                BitVecInfo()
                    : mVec( DEFAULT_CAPACITY )
                {
                }

                // -----------------------------------------------------------

            };

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** Mutex **/
            mutable hex_Mutex mMutex;

            /** Bits Vectors **/
            hex_map_t<T, BitVecInfo> mBitVecs;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns Bit-Vector info-struct.
             * 
             * @thread_safety - thread-locks used.
             * @throws - can thro exception (mutex).
            **/
            BitVecInfo& getVecInfo( const T pKey )
            {
                hex_lock_t lock( &mMutex );

                return mBitVecs[pKey];
            }

            // ===========================================================
            // DELETED
            // ===========================================================

            BitMap( const BitMap& ) noexcept = delete;
            BitMap& operator=( const BitMap& ) noexcept = delete;
            BitMap( BitMap&& ) noexcept = delete;
            BitMap& operator=( BitMap&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * BitMap constructor.
             * 
             * @throws - can throw exception.
            **/
            explicit BitMap()
                : mMutex(),
                mBitVecs()
            {
            }

            /**
             * @brief
             * BitMap destructor.
             * 
             * @throws - no exceptions.
            **/
            ~BitMap() = default;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Get value.
             * 
             * @thread_safety - thread-locks used.
             * @param pKey - key.
             * @param pIndex - index.
             * @param pDefault - default-value.
             * @throws - can throw mutex-exception.
            **/
            bool get( const T pKey, const hex_size_t pIndex, const bool pDefault )
            {
                BitVecInfo& vecInfo = getVecInfo( pKey );

                return vecInfo.mVec.get( pIndex, pDefault );
            }

            /**
             * @brief
             * Set value.
             *
             * @thread_safety - thread-locks used.
             * @param pKey - key.
             * @param pIndex - index.
             * @throws - can throw mutex-exception.
            **/
            void set( const T pKey, const bool pValue )
            {
                BitVecInfo& vecInfo = getVecInfo( pKey );

                vecInfo.mVec.set( pIndex, pValue );
            }

            // ===========================================================
            // METHODS
            // ===========================================================

            // -----------------------------------------------------------

        }; /// hex::core::BitMap

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

template <typename T>
using hex_BitMap = hex::core::BitMap<T, hex_BitVec>;

#define HEX_CORE_BIT_MAP_DECL

// -----------------------------------------------------------

#endif // !HEX_CORE_BIT_MAP_HPP
