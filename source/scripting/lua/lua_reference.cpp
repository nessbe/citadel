// File:       lua_reference.cpp
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
#include "citadel/scripting/lua/lua_reference.hpp"

#include "citadel/scripting/lua.hpp"

namespace citadel {
	lua_reference::lua_reference(const reference<lua_state>& state, reference_type reference)
		: state_(state), reference_(reference)
	{
		CITADEL_ASSERT(state, "The given state is null");
	}

	lua_reference::lua_reference(const reference<lua_state>& state)
		: lua_reference(state, LUA_NOREF) { }

	lua_reference::~lua_reference() {
		reset();
	}

	lua_reference::lua_reference(lua_reference&& other) noexcept {
		*this = std::move(other);
	}

	lua_reference& lua_reference::operator=(lua_reference&& other) noexcept {
		if (this != &other) {
			reset();

			state_ = other.state_;
			reference_ = other.reference_;

			other.reset();
		}
		return *this;
	}

	void lua_reference::reset(reference_type reference) {
		if (reference_ != LUA_NOREF) {
			luaL_unref(state_->native_handle(), LUA_REGISTRYINDEX, reference_);
		}
		reference_ = reference;
	}

	void lua_reference::reset() {
		reset(LUA_NOREF);
	}

	bool lua_reference::valid() const noexcept {
		return reference_ != LUA_NOREF;
	}

	lua_state& lua_reference::state() noexcept {
		return *state_;
	}

	lua_reference::reference_type lua_reference::native_handle() const noexcept {
		return reference_;
	}

	lua_reference::operator bool() const noexcept {
		return valid();
	}
}
