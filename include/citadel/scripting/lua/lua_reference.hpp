// File:       lua_reference.hpp
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

#include "citadel/scripting/lua/lua_state.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported lua_reference {
	public:
		using reference_type = int;

	public:
		lua_reference(const reference<lua_state>& state, reference_type reference);
		lua_reference(const reference<lua_state>& state);

		~lua_reference();

		lua_reference(const lua_reference&) = delete;
		lua_reference& operator=(const lua_reference&) = delete;

		lua_reference(lua_reference&& other) noexcept;
		lua_reference& operator=(lua_reference&& other) noexcept;

		void reset(reference_type reference);
		void reset();

		nodisc lua_state& state() noexcept;
		nodisc reference_type native_handle() const noexcept;

		nodisc explicit operator bool() const noexcept;

	private:
		reference<lua_state> state_;
		reference_type reference_;
	};
}

CITADEL_WARNING_IGNORE_POP
