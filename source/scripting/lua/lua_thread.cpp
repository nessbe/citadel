// File:       lua_thread.cpp
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
#include "citadel/scripting/lua/lua_thread.hpp"

#include "citadel/scripting/lua.hpp"

namespace citadel {
	lua_thread::lua_thread(lua_reference handle, const reference<lua_state>& state)
		: handle_(std::move(handle)), state_(state)
	{
		CITADEL_ASSERT(state_, "The given state is null");
	}

	lua_thread::status_type lua_thread::resume(const reference<lua_state>& parent, int argument_count) {
		CITADEL_ASSERT(valid(), "Attempting to resume an invalid Lua thread");
		CITADEL_CHECK_ARGUMENT(parent, parent == nullptr);

		status_ = lua_resume(state_->native_handle(), parent->native_handle(), argument_count, NULL);
		return status_;
	}

	lua_thread::status_type lua_thread::status() const noexcept {
		return status_;
	}

	bool lua_thread::yielded() const noexcept {
		return status_ == LUA_YIELD;
	}

	bool lua_thread::finished() const noexcept {
		return status_ == LUA_OK;
	}

	bool lua_thread::error() const noexcept {
		return status_ != LUA_OK && status_ != LUA_YIELD;
	}

	bool lua_thread::valid() const noexcept {
		return handle_.valid();
	}

	const lua_reference& lua_thread::handle() const noexcept {
		return handle_;
	}

	lua_state& lua_thread::state() noexcept {
		return *state_;
	}

	lua_thread::operator bool() const noexcept {
		return valid();
	}
}
