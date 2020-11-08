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

#ifndef HEX_ECS_ENGINE_HPP
#define HEX_ECS_ENGINE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// ===========================================================
// TYPES
// ===========================================================

namespace hex
{

    namespace ecs
    {

        /**
         * @brief
         * ECSEngine - ecs implementation adapter.
         * Allows to easilly change ECS implementation.
         * 
         * @version 0.1
        **/
        class ECSEngine final
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** ECSEngine instance. **/
            static ECSEngine* mInstance;

            // ===========================================================
            // DELETED
            // ===========================================================

            ECSEngine( const ECSEngine& ) noexcept = delete;
            ECSEngine& operator=( const ECSEngine& ) noexcept = delete;
            ECSEngine( ECSEngine&& ) noexcept = delete;
            ECSEngine& operator=( ECSEngine&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * ECSEngine default constructor.
             *
             * @throws - no exceptions.
            **/
            explicit ECSEngine() noexcept;

            /**
             * @brief
             * ECSEngine destructor.
             * 
             * @throws - no exceptions.
            **/
            ~ECSEngine() noexcept;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Initialize ECS.
             *
             * @throws - no exceptions.
            **/
            static void Initialize() noexcept;

            /**
             * @brief
             * Terminate ECS.
             *
             * @throws - no exceptions.
            **/
            static void Terminate() noexcept;

            // -----------------------------------------------------------

        };

    } /// hex::ecs

} /// hex

using hexECS = hex::ecs::ECSEngine;

// -----------------------------------------------------------

#endif // !HEX_ECS_ENGINE_HPP
