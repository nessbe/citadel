// File:       lua_scripting_engine.hpp
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

#include "citadel/scripting/scripting_engine.hpp"

#include "citadel/scripting/lua/lua_state.hpp"

namespace citadel {
	class exported lua_scripting_engine final : public scripting_engine {
	public:
		lua_scripting_engine(const lua_scripting_engine&) = delete;
		lua_scripting_engine& operator=(const lua_scripting_engine&) = delete;

		nodisc lua_state& state() noexcept;

	private:
		lua_state state_;

	private:
		virtual void _bind() override;
		virtual void _unbind() override;

		nodisc virtual void* _native_handle() const noexcept override;
	};
}
