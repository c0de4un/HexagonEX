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

#ifndef HEX_CORE_ENUM_HPP
#define HEX_CORE_ENUM_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// ===========================================================
// TYPES
// ===========================================================

namespace hex
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // hex::core::Enum
        // ===========================================================

        /**
         * @brief
         * Enum - base enum-class.
         * 
         * (?)
         * Allows to encapsulate & extend (derive) funcitonality.
         * Used to avoid combining enum-class with wrappers, or using malformat
         * naming if C-enums with static-utilities.
         * 
         * @version 1.0
        **/
        template <typename T>
        class Enum
        {

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            /**
             * @brief
             * Enum constructor.
             * 
             * @throws - can throw exception.
            **/
            explicit Enum();

            // ===========================================================
            // DELETED
            // ===========================================================

            Enum( const Enum& ) noexcept = delete;
            Enum& operator=( const Enum& ) noexcept = delete;
            Enum( Enum&& ) noexcept = delete;
            Enum& operator=( Enum&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * Enum destructor.
             * 
             * @throws - no exceptions.
            **/
            virtual ~Enum() noexcept;

            // -----------------------------------------------------------

        }; /// hex::core::Enum

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

template <typename T>
using hex_Enum = hex::core::Enum<T>;

#define HEX_CORE_ENUM_DECL

// -----------------------------------------------------------

#endif // !HEX_CORE_ENUM_HPP
