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

#ifndef HEX_CORE_I_GRAPHICS_HXX
#define HEX_CORE_I_GRAPHICS_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::api
#ifndef HEX_CORE_API_HPP
#include "../configs/hex_api.hpp"
#endif // !HEX_CORE_API_HPP

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// Forward-Declare hex::core::GraphicsSettings
#ifndef HEX_CORE_GRAPHICS_SETTINGS_DECL
#define HEX_CORE_GRAPHICS_SETTINGS_DECL
namespace hex { namespace core { struct GraphicsSettings; } }
using hex_GraphicsSettings = hex::core::GraphicsSettings;
#endif // !HEX_CORE_GRAPHICS_SETTINGS_DECL

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
         * IGraphics - graphics manager interface.
         * 
         * @version 1.0
        **/
        class IGraphics
        {

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * IGraphics destructor.
             * 
             * @throws - no exceptions.
            **/
            virtual ~IGraphics() HEX_NOEXCEPT
            {
            }

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
            virtual const hex_GraphicsSettings* getGraphicsSettings() const noexcept = 0;

            // ===========================================================
            // METHODS
            // ===========================================================

            // -----------------------------------------------------------

        }; /// hex::core::IGraphics

        // -----------------------------------------------------------

    } /// hex::core

} /// hex

#define HEX_CORE_I_GRAPHICS_DECL
using hex_IGraphics = hex::core::IGraphics;

// -----------------------------------------------------------

#endif // !HEX_CORE_I_GRAPHICS_HXX
