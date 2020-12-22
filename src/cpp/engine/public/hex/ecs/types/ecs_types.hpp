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

#ifndef HEX_ECS_TYPES_HPP
#define HEX_ECS_TYPES_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ecs::api
#ifndef HEX_ECS_API_HPP
#include "ecs_api.hpp"
#endif // !HEX_ECS_API_HPP

// Include hex::numeric
#ifndef HEX_CORE_NUMERIC_HPP
#include "../../core/configs/hex_numeric.hpp"
#endif // !HEX_CORE_NUMERIC_HPP

// Include hex::string
#ifndef HEX_CORE_STRING_HPP
#include "../../core/configs/hex_string.hpp"
#endif // !HEX_CORE_STRING_HPP

// ===========================================================
// TYPES
// ===========================================================

using ecs_uint8_t   = hex_uint8_t;
using ecs_int8_t    = hex_int8_t;
using ecs_uint16_t  = hex_uint16_t;
using ecs_int16_t   = hex_int16_t;
using ecs_uint32_t  = hex_uint32_t;
using ecs_int32_t   = hex_int32_t;
using ecs_uint64_t  = hex_uint64_t;
using ecs_int64_t   = hex_int64_t;
using ecs_float_t   = hex_float_t;

using ecs_TypeID = ecs_uint8_t;
using ecs_ObjectID = ecs_uint64_t;
using ecs_EventTypeID = ecs_uint32_t;

static const ecs_ObjectID ECS_INVALID_OBJECT_ID( 1 );

// #define ECS_INVALID_OBJECT_ID ecs_ObjectID(99999);

using ecs_string = hex_string;
using ecs_strings = hex_Strings;

// -----------------------------------------------------------

#endif // !HEX_ECS_TYPES_HPP
