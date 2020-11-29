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

#ifndef HEX_CORE_NUMERIC_HPP
#define HEX_CORE_NUMERIC_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include hex::api
#ifndef HEX_CORE_API_HPP
#include "hex_api.hpp"
#endif // !HEX_CORE_API_HPP

// Include STL numeric
#if defined( HEX_WINDOWS ) // Windows
#include <cstdint>
#include <limits>
#elif defined( HEX_LINUX ) // Linux
#include <cstdint>
#include <limits>
#elif defined( HEX_ANDROID ) // Android
#include <cstdint>
#include <limits> // Android NDK
#else
#error "hex_numeric.hpp - configuration required."
#endif

// ===========================================================
// TYPES
// ===========================================================

using hex_uint8_t    = std::uint8_t;
using hex_int8_t     = std::int8_t;
using hex_uint16_t   = std::uint16_t;
using hex_int16_t    = std::int16_t;
using hex_uint32_t   = std::uint32_t;
using hex_int32_t    = std::int32_t;
using hex_uint64_t   = std::uint64_t;
using hex_int64_t    = std::int64_t;
using hex_float_t    = double;
using hex_doube_t = double;

// -----------------------------------------------------------

#endif // !HEX_CORE_NUMERIC_HPP
