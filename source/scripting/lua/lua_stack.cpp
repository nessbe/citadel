// File:       lua_stack.cpp
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
#include "citadel/scripting/lua/lua_stack.hpp"

#include "citadel/scripting/lua.hpp"

#include "citadel/scripting/lua/exceptions/lua_type_error.hpp"

namespace citadel {
	const lua_stack::size_type lua_stack::top = -1;

	lua_stack::lua_stack(const reference<lua_state>& state)
		: state_(state)
	{
		CITADEL_ASSERT(state, "The given state is null");
	}

	void lua_stack::push_nil() {
		lua_pushnil(state_->native_handle());
	}

	void lua_stack::push_boolean(lua_boolean value) {
		lua_pushboolean(state_->native_handle(), value);
	}

	void lua_stack::push_integer(lua_integer value) {
		lua_pushinteger(state_->native_handle(), value);
	}

	void lua_stack::push_number(lua_number value) {
		lua_pushnumber(state_->native_handle(), value);
	}

	void lua_stack::push_string(const lua_string& value) {
		lua_pushlstring(state_->native_handle(), value.data(), value.size());
	}

	void lua_stack::push_reference(const lua_reference& value) {
		lua_rawgeti(state_->native_handle(), LUA_REGISTRYINDEX, value.native_handle());
	}

	void lua_stack::push_table(const lua_table& value) {
		push_reference(value);
	}

	void lua_stack::push_function(const lua_function& value) {
		push_reference(value);
	}

	void lua_stack::push_userdata(const lua_userdata& value) {
		push_reference(value);
	}

	void lua_stack::push_lightuserdata(lua_lightuserdata value) {
		lua_pushlightuserdata(state_->native_handle(), value);
	}

	void lua_stack::push_thread(const lua_thread& value) {
		push_reference(value.handle());
	}

	void lua_stack::push(lua_value value) {
		std::visit([this](auto&& visited_value) {
			using T = std::decay_t<decltype(visited_value)>;

			if constexpr (std::is_same_v<T, std::monostate>) {
				push_nil();
			}
			else if constexpr (std::is_same_v<T, lua_boolean>) {
				push_boolean(visited_value);
			}
			else if constexpr (std::is_same_v<T, lua_integer>) {
				push_integer(visited_value);
			}
			else if constexpr (std::is_same_v<T, lua_number>) {
				push_number(visited_value);
			}
			else if constexpr (std::is_same_v<T, lua_string>) {
				push_string(visited_value);
			}
			else if constexpr (std::is_same_v<T, lua_reference>) {
				push_reference(visited_value);
			}
			else if constexpr (std::is_same_v<T, lua_table>) {
				push_table(visited_value);
			}
			else if constexpr (std::is_same_v<T, lua_function>) {
				push_function(visited_value);
			}
			else if constexpr (std::is_same_v<T, lua_userdata>) {
				push_userdata(visited_value);
			}
			else if constexpr (std::is_same_v<T, lua_lightuserdata>) {
				push_lightuserdata(visited_value);
			}
			else if constexpr (std::is_same_v<T, lua_thread>) {
				push_thread(visited_value);
			}
		}, value);
	}

	void lua_stack::get_nil(size_type index) {
		if (!lua_isnil(state_->native_handle(), index)) {
			CITADEL_CHECK_STACK_TYPE(state_->native_handle(), index, lua_type::nil);
		}
	}

	lua_boolean lua_stack::get_boolean(size_type index) {
		if (!lua_isboolean(state_->native_handle(), index)) {
			CITADEL_CHECK_STACK_TYPE(state_->native_handle(), index, lua_type::boolean);
		}
		return static_cast<lua_boolean>(lua_toboolean(state_->native_handle(), index));
	}

	lua_integer lua_stack::get_integer(size_type index) {
		if (!lua_isinteger(state_->native_handle(), index)) {
			CITADEL_CHECK_STACK_TYPE(state_->native_handle(), index, lua_type::integer);
		}
		return lua_tointeger(state_->native_handle(), index);;
	}

	lua_number lua_stack::get_number(size_type index) {
		if (!lua_isnumber(state_->native_handle(), index)) {
			CITADEL_CHECK_STACK_TYPE(state_->native_handle(), index, lua_type::number);
		}
		return lua_tonumber(state_->native_handle(), index);
	}

	lua_string lua_stack::get_string(size_type index) {
		if (!lua_isstring(state_->native_handle(), index)) {
			CITADEL_CHECK_STACK_TYPE(state_->native_handle(), index, lua_type::string);
		}

		const char* buffer = lua_tostring(state_->native_handle(), index);
		return std::string(buffer);
	}

	lua_reference lua_stack::get_reference(size_type index) {
		lua_pushvalue(state_->native_handle(), index);
		lua_reference::reference_type reference = luaL_ref(state_->native_handle(), LUA_REGISTRYINDEX);
		return lua_reference(state_, reference);
	}

	lua_table lua_stack::get_table(size_type index) {
		return get_reference(index);
	}

	lua_function lua_stack::get_function(size_type index) {
		return get_reference(index);
	}

	lua_userdata lua_stack::get_userdata(size_type index) {
		return get_reference(index);
	}

	lua_lightuserdata lua_stack::get_lightuserdata(size_type index) {
		if (!lua_islightuserdata(state_->native_handle(), index)) {
			CITADEL_CHECK_STACK_TYPE(state_->native_handle(), index, lua_type::lightuserdata);
		}
		return lua_touserdata(state_->native_handle(), index);
	}

	lua_thread lua_stack::get_thread(size_type index) {
		if (!lua_isthread(state_->native_handle(), index)) {
			CITADEL_CHECK_STACK_TYPE(state_->native_handle(), index, lua_type::thread);
		}

		lua_reference reference = get_reference(index);
		lua_State* thread = lua_tothread(state_->native_handle(), index);
		return lua_thread(std::move(reference), make_referenced<lua_state>(thread));
	}

	lua_value lua_stack::get(size_type index) {
		int type = ::lua_type(state_->native_handle(), index);

		switch (type) {
		case LUA_TNONE:
		case LUA_TNIL:
		default:
			return std::monostate();

		case LUA_TBOOLEAN:
			return get_boolean(index);

		case LUA_TNUMBER:
			if (lua_isinteger(state_->native_handle(), index)) {
				return get_integer(index);
			}
			return get_number(index);

		case LUA_TSTRING:
			return get_string(index);

		case LUA_TTABLE:
			return get_table(index);

		case LUA_TFUNCTION:
			return get_function(index);

		case LUA_TUSERDATA:
			return get_userdata(index);

		case LUA_TLIGHTUSERDATA:
			return get_lightuserdata(index);

		case LUA_TTHREAD:
			return get_thread(index);
		}
	}

	void lua_stack::pop_nil() {
		get_nil(top);
		lua_pop(state_->native_handle(), 1);
	}

	lua_boolean lua_stack::pop_boolean() {
		lua_boolean value = get_boolean(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_integer lua_stack::pop_integer() {
		lua_integer value = get_integer(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_number lua_stack::pop_number() {
		lua_number value = get_number(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_string lua_stack::pop_string() {
		lua_string value =  get_string(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_reference lua_stack::pop_reference() {
		lua_reference value = get_reference(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_table lua_stack::pop_table() {
		lua_table value = get_table(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_function lua_stack::pop_function() {
		lua_function value = get_function(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_userdata lua_stack::pop_userdata() {
		lua_userdata value = get_userdata(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_lightuserdata lua_stack::pop_lightuserdata() {
		lua_lightuserdata value = get_lightuserdata(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_thread lua_stack::pop_thread() {
		lua_thread value = get_thread(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_value lua_stack::pop() {
		lua_value value = get(top);
		lua_pop(state_->native_handle(), 1);
		return value;
	}

	lua_stack::size_type lua_stack::size() const {
		return lua_gettop(state_->native_handle());
	}

	lua_state& lua_stack::state() noexcept {
		return *state_;
	}
}
