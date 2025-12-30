// File:       lua.hpp
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

#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>

#ifdef lua_isnone
	#undef lua_isnone
#endif
#define lua_isnone(state, index) (::lua_type(state, index) == LUA_TNONE)

#ifdef lua_isnil
	#undef lua_isnil
#endif
#define lua_isnil(state, index) (::lua_type(state, index) == LUA_TNIL)

#ifdef lua_isnoneornil
	#undef lua_isnoneornil
#endif
#define lua_isnoneornil(state, index) (::lua_type(state, index) <= 0)

#ifdef lua_isboolean
	#undef lua_isboolean
#endif
#define lua_isboolean(state, index) (::lua_type(state, index) == LUA_TBOOLEAN)

#ifdef lua_isfunction
	#undef lua_isfunction
#endif
#define lua_isfunction(state, index) (::lua_type(state, index) == LUA_TFUNCTION)

#ifdef lua_istable
	#undef lua_istable
#endif
#define lua_istable(state, index) (::lua_type(state, index) == LUA_TTABLE)

#ifdef lua_isthread
	#undef lua_isthread
#endif
#define lua_isthread(state, index) (::lua_type(state, index) == LUA_TTHREAD)

#ifdef lua_islightuserdata
	#undef lua_islightuserdata
#endif
#define lua_islightuserdata(state, index) (::lua_type(state, index) == LUA_TLIGHTUSERDATA)
