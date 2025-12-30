// File:       lua_stack.hpp
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

#include "citadel/memory/reference.hpp"

#include "citadel/scripting/lua/lua_state.hpp"
#include "citadel/scripting/lua/lua_value.hpp"

namespace citadel {
	class exported lua_stack {
	public:
		using size_type = int;

	public:
		static const size_type top;

	public:
		lua_stack(const reference<lua_state>& state);

		void push_nil();
		void push_boolean(lua_boolean value);

		void push_integer(lua_integer value);
		void push_number(lua_number value);

		void push_string(const lua_string& value);
		void push_reference(const lua_reference& value);

		void push_table(const lua_table& value);
		void push_function(const lua_function& value);

		void push_userdata(const lua_userdata& value);
		void push_lightuserdata(lua_lightuserdata value);

		void push_thread(const lua_thread& value);

		void push(lua_value value);

		void get_nil(size_type index);
		nodisc lua_boolean get_boolean(size_type index);

		nodisc lua_integer get_integer(size_type index);
		nodisc lua_number get_number(size_type index);

		nodisc lua_string get_string(size_type index);
		nodisc lua_reference get_reference(size_type index);

		nodisc lua_table get_table(size_type index);
		nodisc lua_function get_function(size_type index);

		nodisc lua_userdata get_userdata(size_type index);
		nodisc lua_lightuserdata get_lightuserdata(size_type index);

		nodisc lua_thread get_thread(size_type index);

		nodisc lua_value get(size_type index);

		void pop_nil();
		nodisc lua_boolean pop_boolean();

		nodisc lua_integer pop_integer();
		nodisc lua_number pop_number();

		nodisc lua_string pop_string();
		nodisc lua_reference pop_reference();

		nodisc lua_table pop_table();
		nodisc lua_function pop_function();

		nodisc lua_userdata pop_userdata();
		nodisc lua_lightuserdata pop_lightuserdata();

		nodisc lua_thread pop_thread();

		nodisc lua_value pop();

		nodisc size_type size() const;

		nodisc lua_state& state() noexcept;

	private:
		reference<lua_state> state_;
	};
}
