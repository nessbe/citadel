// File:       assert.inl
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

#include <type_traits>

#include "citadel/logging/log_macros.hpp"

#include "citadel/utils/format/formatter.hpp"

namespace citadel {
	template <typename... Arguments>
	void panic(const std::string& message, Arguments&&... arguments) {
		CITADEL_LOG_FATAL(message, std::forward<Arguments>(arguments)...);
		panic();
	}

	template <typename... Arguments>
	void assert(bool condition, const std::string& message, Arguments&&... arguments) {
		if (unlikely(!condition)) {
			CITADEL_LOG_FATAL(message, std::forward<Arguments>(arguments)...);
			panic();
		}
	}

	template <typename... Arguments>
	void soft_assert(bool condition, const std::string& message, Arguments&&... arguments) {
		if (unlikely(!condition)) {
			throw assertion_error(formatter::format(message, std::forward<Arguments>(arguments)...));
		}
	}
}
