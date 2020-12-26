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

#ifndef HEX_CORE_MEMORY_MANAGER_HPP
#define HEX_CORE_MEMORY_MANAGER_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::memory
#ifndef HEX_CORE_CONFIG_MEMORY_HPP
#include "../../configs/hex_memory.hpp"
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
         * MemoryManager - entry point for all allocate/deallocate & construct&destruct
         * calls.
         * 
         * Allows to easely switch memory-management schemata.
         * 
         * @version 0.0
        **/
        class MemoryManager final
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            /**
             * @brief
             * MemoryManager constructor.
             * 
             * @throws - no exceptions.
            **/
            explicit MemoryManager() noexcept;

            // ===========================================================
            // DELETED
            // ===========================================================

            MemoryManager( const MemoryManager& ) noexcept = delete;
            MemoryManager& operator=( const MemoryManager& ) noexcept = delete;
            MemoryManager( MemoryManager&& ) noexcept = delete;
            MemoryManager& operator=( MemoryManager&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * MemoryManager destructor.
             * 
             * @throws - no exceptions.
            **/
            ~MemoryManager() noexcept;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Initialize MemoryManager.
             * 
             * @throws - no exceptions.
            **/
            static void Initialize() noexcept;

            /**
             * @brief
             * Terminate MemoryManager.
             * 
             * @throws - no exceptions.
            **/
            static void Terminate() noexcept;

            template <typename T>
            static T* New()
            { return new T(); }

            template <typename T, typename... _Types>
            static T* New( _Types&&... _Args )
            { return new T( _Args... ); }

            template <typename T>
            static void Delete( T* const pInstance )
            { delete pInstance; }

            template <typename T = void>
            static void Delete( const T* const pInstance )
            { delete pInstance; }

            template <typename T>
            static T* NewArray( const size_t pSize )
            { return new T[pSize]; }

            template <typename T = void>
            static void DeleteArray( T* const pArray )
            { delete[] pArray; }

            template <typename T = void>
            static void DeleteArray( const T* const pArray )
            { delete[] pArray; }

            template <typename T, typename... _Types>
            static std::shared_ptr<T> MakeShared( _Types&&... _Args )
            { return std::make_shared<T>( _Args... ); }

            template <typename T>
            static std::shared_ptr<T> MakeShared( T* const pValue )
            { return std::shared_ptr<T>( pValue ); }

            template <typename T, typename V>
            static std::shared_ptr<V> SharedCast( std::shared_ptr<T> pValue )
            {
                return std::static_pointer_cast<T, V>( pValue );
            }

            // -----------------------------------------------------------

        }; /// hex::core::MemoryManager

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

using hex_Memory = hex::core::MemoryManager;

// -----------------------------------------------------------

#endif // !HEX_CORE_MEMORY_MANAGER_HPP
