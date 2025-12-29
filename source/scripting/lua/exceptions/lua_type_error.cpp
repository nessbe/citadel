// File:       lua_type_error.cpp
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
#include "citadel/scripting/lua/exceptions/lua_type_error.hpp"

namespace citadel {
	lua_type_error::lua_type_error(int index, lua_type expected, lua_type actual)
		: lua_exception(formatter::format(
			"Lua type error at stack index {0}: expected '{1}', got '{2}'",
			index,
			lua_type_to_string(expected),
			lua_type_to_string(actual)
		))
	{ }
}
