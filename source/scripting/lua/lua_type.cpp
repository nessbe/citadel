// File:       lua_type.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#include "citadel/pch.hpp"
#include "citadel/scripting/lua/lua_type.hpp"

#include "citadel/scripting/lua.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_UNREACHABLE_CODE)

	native_lua_type lua_type_to_native(lua_type value) {
		switch (value) {
		case lua_type::nil:
			return LUA_TNIL;

		case lua_type::boolean:
			return LUA_TBOOLEAN;

		case lua_type::integer:
		case lua_type::number:
			return LUA_TNUMBER;

		case lua_type::string:
			return LUA_TSTRING;

		case lua_type::table:
			return LUA_TTABLE;

		case lua_type::function:
			return LUA_TFUNCTION;

		case lua_type::userdata:
			return LUA_TUSERDATA;

		case lua_type::lightuserdata:
			return LUA_TLIGHTUSERDATA;

		case lua_type::thread:
			return LUA_TTHREAD;

		default:
			CITADEL_PANIC("Unknown Lua type");
			return LUA_TNONE;
		}
	}

	lua_type lua_type_from_native(native_lua_type value) {
		switch (value) {
		case LUA_TNIL:
			return lua_type::nil;

		case LUA_TBOOLEAN:
			return lua_type::boolean;

		case LUA_TNUMBER:
			return lua_type::number;

		case LUA_TSTRING:
			return lua_type::string;

		case LUA_TTABLE:
			return lua_type::table;

		case LUA_TFUNCTION:
			return lua_type::function;

		case LUA_TUSERDATA:
			return lua_type::userdata;

		case LUA_TLIGHTUSERDATA:
			return lua_type::lightuserdata;

		case LUA_TTHREAD:
			return lua_type::thread;

		default:
			CITADEL_PANIC("Unknown native Lua type");
			return lua_type::none;
		}
	}

CITADEL_WARNING_IGNORE_POP

}
