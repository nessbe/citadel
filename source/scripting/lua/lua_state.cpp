// File:       lua_state.cpp
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
#include "citadel/scripting/lua/lua_state.hpp"

#include "citadel/scripting/lua.hpp"

namespace citadel {
	lua_state::lua_state() {
		handle_ = luaL_newstate();
	}

	lua_state::~lua_state() {
		lua_close(handle_);
	}

	lua_State* lua_state::native_handle() const noexcept {
		return handle_;
	}
}
