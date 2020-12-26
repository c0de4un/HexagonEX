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

#ifndef HEXGAME_CORE_HEXGAME_HPP
#define HEXGAME_CORE_HEXGAME_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::core::Game
#ifndef HEX_CORE_GAME_HPP
#include "../../../../../engine/public/hex/core/game/Game.hpp"
#endif // !HEX_CORE_GAME_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace hexgame
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // hexgame::core::HexGame
        // ===========================================================

        /**
         * @brief
         * HexGame - HexagonEX mian game class.
         * 
         * @version 1.0
        **/
        class HexGame final : public hex_Game
        {

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // OVERRIDE: ecs::System
            // ===========================================================

            /**
             * @brief
             * Called to Start.
             * 
             * @thread_safety - thread-lock used
             * @throws - can throw exception
             * @return - 0 if OK
            **/
            virtual int onStart() final;

            /**
             * @brief
             * Called to Resume.
             * 
             * @thread_safety - thread-lock used
             * @throws - can throw exception
             * @return - 0 if OK
            **/
            virtual int onResume() final;

            /**
             * @brief
             * Called to Pause.
             * 
             * @thread_safety - thread-lock used
             * @throws - no exceptions.
            **/
            virtual void onPause() noexcept final;

            /**
             * @brief
             * Called to Stop.
             * 
             * @thread_safety - thread-lock used
             * @throws - no exceptions.
            **/
            virtual void onStop() noexcept final;

            /**
             * @brief
             * Called on Termiation.
             * 
             * @thread_safety - thread-locks used.
             * @throws - no exceptions.
            **/
            virtual void onTerminate() noexcept final;

            // ===========================================================
            // DELETED
            // ===========================================================

            HexGame( const HexGame& ) noexcept = delete;
            HexGame& operator=( const HexGame& ) noexcept = delete;
            HexGame( HexGame&& ) noexcept = delete;
            HexGame& operator=( HexGame&& ) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * HexGame constructor.
             * 
             * @throws - can throw exception.
            **/
            explicit HexGame();

            /**
             * @brief
             * HexGame destructor.
             * 
             * @throws - no exceptions.
            **/
            virtual ~HexGame() noexcept;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            // ===========================================================
            // METHODS
            // ===========================================================

            // -----------------------------------------------------------

        }; /// hexgame::core::HexGame

        // -----------------------------------------------------------

    } /// hexgame::core

} /// hex

#define HEXGAME_CORE_HEXGAME_DECL

// -----------------------------------------------------------

#endif // !HEXGAME_CORE_HEXGAME_HPP