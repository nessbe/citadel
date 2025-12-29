// File:       lua_type_error.hpp
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

#include "citadel/exceptions.hpp"

#include "citadel/scripting/lua/lua_type.hpp"

#include "citadel/scripting/lua/exceptions/lua_exception.hpp"

namespace citadel {
	class lua_type_error final : public lua_exception {
	public:
		lua_type_error(int index, lua_type expected, lua_type actual);
	};
}

#define CITADEL_CHECK_STACK_TYPE(state, index, expected) CITADEL_THROW_IF(     \
	::citadel::lua_type_from_native(::lua_type(state, index)) != expected, \
	::citadel::lua_type_error,                                             \
	index,                                                                 \
	expected,                                                              \
	::citadel::lua_type_from_native(::lua_type(state, index))              \
)
