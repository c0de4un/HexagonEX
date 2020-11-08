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

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#ifndef HEX_CORE_LOG_HPP
#include "../../../../../public/hex/core/utils/metrics/Log.hpp"
#endif // !HEX_CORE_LOG_HPP

// Include hex::core::ILog
#ifndef HEX_CORE_I_LOG_HXX
#include "../../../public/hex/core/utils/metrics/ILog.hxx"
#endif // !HEX_CORE_I_LOG_HXX

// DEBUG
#ifdef HEX_DEBUG

// Include hex::assert
#ifndef HEX_CORE_CONFIG_ASSERT_HPP
#include "../../../public/hex/core/configs/hex_assert.hpp"
#endif // !HEX_CORE_CONFIG_ASSERT_HPP
#endif

// DEBUG

// ===========================================================
// hex::core::Log
// ===========================================================

namespace hex
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // FIELDS
        // ===========================================================

        ILog* Log::mInstance(nullptr);

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        Log::Log() = default;

        Log::~Log() noexcept = default;

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        void Log::setInstance(ILog* const pInstance) noexcept
        {
            if (mInstance)
                return;

            mInstance = pInstance;
        }

        ILog* Log::getInstance() noexcept { return mInstance; }

        // ===========================================================
        // METHODS
        // ===========================================================

        void Log::Terminate() noexcept
        {
            delete mInstance;
            mInstance = nullptr;
        }

        void Log::printInfo(const char* const pMsg) noexcept
        {
#ifdef HEX_DEBUG // DEBUG
            assert(mInstance && "Log::printInfo: instance is null");
#endif // DEBUG
            mInstance->onInfo(pMsg);
        }

        void Log::printDebug(const char* const pMsg) noexcept
        {
#ifdef HEX_DEBUG // DEBUG
            assert(mInstance && "Log::printDebug: instance is null");
#endif // DEBUG
            mInstance->onDebug(pMsg);
        }

        void Log::printWarning(const char* const pMsg) noexcept
        {
#ifdef HEX_DEBUG // DEBUG
            assert(mInstance && "Log::printWarning: instance is null");
#endif // DEBUG
            mInstance->onWarning(pMsg);
        }

        void Log::printError(const char* const pMsg) noexcept
        {
#ifdef HEX_DEBUG // DEBUG
            assert(mInstance && "Log::printError: instance is null");
#endif // DEBUG
            mInstance->onError( pMsg );
        }

        // -----------------------------------------------------------

    } /// hex::win

} /// hex
