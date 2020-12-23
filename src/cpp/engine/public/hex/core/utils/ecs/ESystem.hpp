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

#ifndef HEX_CORE_E_SYSTEMS_HPP
#define HEX_CORE_E_SYSTEMS_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::core::Enum
#ifndef HEX_CORE_ENUM_HPP
#include "../lng/Enum.hpp"
#endif // !HEX_CORE_ENUM_HPP

// Include ecs::types
#ifndef HEX_ECS_TYPES_HPP
#include "../../../ecs/types/ecs_types.hpp"
#endif // !HEX_ECS_TYPES_HPP

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
         * ESystem - enum-class adapter for encapsulated functionality support
         * & easy-extensible.
         *
         * @version 1.0
        **/
        class ESystem : public hex_Enum<ecs_TypeID>
        {

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // DELETED
            // ===========================================================

            ESystem( const ESystem& ) noexcept = delete;
            ESystem& operator=( const ESystem& ) noexcept = delete;
            ESystem( ESystem&& ) noexcept = delete;
            ESystem& operator=( ESystem&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTANTS
            // ===========================================================

            static constexpr const ecs_TypeID RENDER = 1;
            static constexpr const ecs_TypeID AUDIO = 2;
            static constexpr const ecs_TypeID INPUT = 3;
            static constexpr const ecs_TypeID THREADING = 4;
            static constexpr const ecs_TypeID PHYSICS = 5;
            static constexpr const ecs_TypeID NET = 6;
            static constexpr const ecs_TypeID BATCHING = 7;
            static constexpr const ecs_TypeID GRAPHICS = 8;
            static constexpr const ecs_TypeID PARTICLES = 9;
            static constexpr const ecs_TypeID ENGINE = 10;
            static constexpr const ecs_TypeID APPLICATION = 11;
            static constexpr const ecs_TypeID GAME = 12;

            static constexpr const ecs_TypeID ESystem_MAX = 99;

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * ESystem constructor.
             * 
             * @throws - can throw exception.
            **/
            explicit ESystem();

            /**
             * @brief
             * ESystem destructor.
             * 
             * @throws - no exceptions.
            **/
            virtual ~ESystem() noexcept;

            // -----------------------------------------------------------

        }; /// hex::core::ESystems

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

using hex_ESystem = hex::core::ESystem;

#define HEX_CORE_E_SYSTEMS_DECL

// -----------------------------------------------------------

#endif // !HEX_CORE_E_SYSTEMS_HPP
