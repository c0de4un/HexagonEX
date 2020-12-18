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

#ifndef HEX_CORE_GRAPHICS_MANAGER_HPP
#define HEX_CORE_GRAPHICS_MANAGER_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::core::IGraphics
#ifndef HEX_CORE_I_GRAPHICS_HXX
#include "IGraphics.hxx"
#endif // !HEX_CORE_I_GRAPHICS_HXX

// Include ecs::System
#ifndef HEX_ECS_SYSTEM_HPP
#include "../../ecs/systems/System.hpp"
#endif // !HEX_ECS_SYSTEM_HPP

// Include hex::core::GraphicsSettings
#ifndef HEX_CORE_GRAPHICS_SETTINGS_HPP
#include "GraphicsSettings.hpp"
#endif // !HEX_CORE_GRAPHICS_SETTINGS_HPP

// Include hex::memory
#ifndef HEX_CORE_CONFIG_MEMORY_HPP
#include "../configs/hex_memory.hpp"
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
         * GraphicsManager - base Graphics-Manager class.
         * 
         * @version 1.0
        **/
        class GraphicsManager : public hex_IGraphics, public ecs_System
        {

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** IGraphics Instance **/
            static hex_sptr<GraphicsManager> mInstance;

            /** GraphicsSettings **/
            hex_GraphicsSettings* mGraphicsSettings;

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            /**
             * @brief
             * GraphicsManager constructor.
             * 
             * @throws - can throw exceptions.
            **/
            explicit GraphicsManager( hex_GraphicsSettings* const graphicsSettings  );

            // ===========================================================
            // DELETED
            // ===========================================================

            GraphicsManager( const GraphicsManager& ) noexcept = delete;
            GraphicsManager& operator=( const GraphicsManager& ) noexcept = delete;
            GraphicsManager( GraphicsManager&& ) noexcept = delete;
            GraphicsManager& operator=( GraphicsManager&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns current GraphicsSettings instance.
             *
             * @thread_safety - thread-safe.
             * @throws - no exceptions.
            **/
            virtual const hex_GraphicsSettings* getGraphicsSettings() const noexcept final;

            /**
             * @brief
             * Returns IGraphics instance, or null.
             * 
             * @thread_safety - thread-locks used.
             * @return IGraphics, or null.
             * @throws - no exceptions.
            **/
            static hex_sptr<GraphicsManager> getInstance() noexcept;

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * GraphicsManager destructor.
             * 
             * @throws - no exceptions.
            **/
            virtual ~GraphicsManager() HEX_NOEXCEPT;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Initialize GraphicsManager instance.
             * 
             * Facade-method for instance#Start().
             * 
             * @thread_safety - thread-lock used.
             * @return - 0 if OK, or error-code.
             * @throws - can throw exception.
            **/
            static int Initialize();

            /**
             * @brief
             * Terminate GraphicsManager instance.
             * 
             * (?) Facade-method for instance#Stop();
             * 
             * @thread_safety - thread-locks used.
             * @throws - no exceptions.
            **/
            static void Terminate() HEX_NOEXCEPT;

            // -----------------------------------------------------------

        }; /// hex::core::GraphicsManager

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

using hex_Graphics = hex::core::GraphicsManager;
#define HEX_CORE_GRAPHICS_MANAGER_DECL

// -----------------------------------------------------------

#endif // !HEX_CORE_GRAPHICS_MANAGER_HPP
