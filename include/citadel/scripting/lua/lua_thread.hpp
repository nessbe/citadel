// File:       lua_thread.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/scripting/lua/lua_reference.hpp"
#include "citadel/scripting/lua/lua_state.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported lua_thread {
	public:
		using status_type = int;

	public:
		lua_thread(lua_reference handle, const reference<lua_state>& state);

		lua_thread(const lua_thread&) = delete;
		lua_thread& operator=(const lua_thread&) = delete;

		lua_thread(lua_thread&&) = default;
		lua_thread& operator=(lua_thread&&) = default;

		status_type resume(const reference<lua_state>& parent, int argument_count = 0);
		nodisc status_type status() const noexcept;

		nodisc bool yielded() const noexcept;
		nodisc bool finished() const noexcept;
		nodisc bool error() const noexcept;

		nodisc bool valid() const noexcept;

		nodisc const lua_reference& handle() const noexcept;
		nodisc lua_state& state() noexcept;

		nodisc explicit operator bool() const noexcept;

	private:
		lua_reference handle_;
		reference<lua_state> state_;
		status_type status_;
	};
}

CITADEL_WARNING_IGNORE_POP
