// File:       assert.hpp
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

namespace citadel {
	noret exported void panic() noexcept;

	template <typename... Arguments>
	noret void panic(const std::string& message, Arguments&&... arguments);

	exported void assert(bool condition) noexcept;

	template <typename... Arguments>
	void assert(bool condition, const std::string& message, Arguments&&... arguments);

	exported void soft_assert(bool condition);

	template <typename... Arguments>
	void soft_assert(bool condition, const std::string& message, Arguments&&... arguments);
}

#ifdef CITADEL_DEBUG
	#define CITADEL_PANIC(message, ...) ::citadel::panic("Program panicked: " message, ##__VA_ARGS__)
	#define CITADEL_ASSERT(condition, message, ...) ::citadel::assert(static_cast<bool>(condition), "Assertion failed (" #condition "): " message, ##__VA_ARGS__)
#else
	#define CITADEL_PANIC(message, ...)
	#define CITADEL_ASSERT(condition, message, ...)
#endif

#define CITADEL_SOFT_ASSERT(condition, message, ...) ::citadel::soft_assert(static_cast<bool>(condition), "Soft assertion failed (" #condition "): " message, ##__VA_ARGS__)

#include "citadel/assert.inl"
