// File:       lua_script.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2026 nessbe
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

#include "citadel/io/random_access_stream.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/scripting/script.hpp"

#include "citadel/scripting/lua/lua_stack.hpp"
#include "citadel/scripting/lua/lua_state.hpp"

namespace citadel {
	class exported lua_script final : public script {
	public:
		explicit lua_script(const reference<random_access_stream>& stream);

		nodisc lua_state& state() noexcept;
		nodisc lua_stack& stack() noexcept;

	private:
		reference<lua_state> state_;
		lua_stack stack_;

	private:
		nodisc virtual bool _can_reload() const noexcept override;
		virtual void _reload() override;
	};
}
