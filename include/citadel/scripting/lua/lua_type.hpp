// File:       lua_type.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	using native_lua_type = int;
	enum class lua_type : native_lua_type {
		none = 0,
		nil,
		boolean,
		number,
		integer,
		string,
		table,
		function,
		userdata,
		lightuserdata,
		thread,
	};

	nodisc exported native_lua_type lua_type_to_native(lua_type value);
	nodisc exported lua_type lua_type_from_native(native_lua_type value);
	nodisc exported std::string lua_type_to_string(lua_type value);
}
