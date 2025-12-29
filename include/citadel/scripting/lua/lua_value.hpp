// File:       lua_value.hpp
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

#pragma once

#include <string>
#include <type_traits>
#include <variant>

#include "citadel/scripting/lua/lua_reference.hpp"
#include "citadel/scripting/lua/lua_state.hpp"
#include "citadel/scripting/lua/lua_thread.hpp"

namespace citadel {
	using lua_boolean = bool;
	using lua_integer = long long;
	using lua_number = double;
	using lua_string = std::string;
	using lua_table = lua_reference;
	using lua_function = lua_reference;
	using lua_userdata = lua_reference;
	using lua_lightuserdata = void*;

	using lua_value = std::variant<
		std::monostate,
		lua_boolean,
		lua_integer,
		lua_number,
		lua_string,
		lua_reference,
		lua_lightuserdata,
		lua_thread
	>;

	static_assert(!std::is_copy_constructible_v<lua_value>);
	static_assert(std::is_move_constructible_v<lua_value>);
}
