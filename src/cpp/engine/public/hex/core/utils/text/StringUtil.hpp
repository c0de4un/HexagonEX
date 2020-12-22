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

#ifndef HEX_CORE_STRING_UTIL_HPP
#define HEX_CORE_STRING_UTIL_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::string
#ifndef HEX_CORE_STRING_HPP
#include "../../configs/hex_string.hpp"
#endif // !HEX_CORE_STRING_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace hex
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // hex::core::StringUtil
        // ===========================================================

        /**
         * @brief
         * StringUtil - string utility.
         * 
         * @version 1.1
        **/
        class StringUtil final
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            /**
             * @brief
             * StringUtil constructor.
             * 
             * @throws - bad_alloc.
            **/
            explicit StringUtil() = default;

            // ===========================================================
            // DELETED
            // ===========================================================

            StringUtil( const StringUtil& ) noexcept = delete;
            StringUtil& operator=( const StringUtil& ) noexcept = delete;
            StringUtil( StringUtil&& ) noexcept = delete;
            StringUtil& operator=( StringUtil&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * StringUtil destructor.
             * 
             * @throws - no exceptions.
            **/
            ~StringUtil() noexcept = default;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            // ===========================================================
            // METHODS
            // ===========================================================

            template <typename T>
            static hex_string to_string( const T pValue )
            {
                return std::to_string( pValue );
            }

            // -----------------------------------------------------------

        }; /// hex::core::StringUtil

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

using hex_Strings = hex::core::StringUtil;

// -----------------------------------------------------------

#endif // !HEX_CORE_STRING_UTIL_HPP
