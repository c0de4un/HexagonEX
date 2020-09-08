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

#ifndef HEX_CORE_CONFIG_LOG_HPP
#define HEX_CORE_CONFIG_LOG_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::api
#ifndef HEX_CORE_API_HPP
#include "hex_api.hpp"
#endif // !HEX_CORE_API_HPP

// PLATFORM
#if defined( HEX_WINDOWS ) // WINDOWS

// Include hex::win::WinLog
#ifndef HEX_WIN_LOG_HPP
#include "../../windows/utils/metrics/WinLog.hpp"
#endif // !HEX_WIN_LOG_HPP

#elif defined( HEX_LINUX ) // LINUX

// Include hex::linux::LinuxLog
#ifndef HEX_LINUX_LOGGER_HPP
#include "../../linux/utils/metrics/LinuxLog.hpp"
#endif // !HEX_LINUX_LOGGER_HPP

#elif defined( HEX_ANDROID ) // ANDROID

// Include hex::android::AndroidLog
#ifndef HEX_ANDROID_LOGGER_HPP
#include "../../android/utils/metrics/AndroidLog.hpp"
#endif // !HEX_ANDROID_LOGGER_HPP

#else
#error "hex_log.hpp - configuration required"
#endif

// -----------------------------------------------------------

#endif // !HEX_CORE_CONFIG_LOG_HPP
