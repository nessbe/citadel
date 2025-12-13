// File:       log_message.hpp
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
#include <tuple>
#include <type_traits>

#include "citadel/warnings.hpp"

#include "citadel/logging/log_level.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	template <typename... Arguments>
	struct log_message {
		std::string literal;
		log_level level;
		std::tuple<std::decay_t<Arguments>...> arguments;

	public:
		log_message(const std::string& message, log_level level, Arguments&&... arguments);
	};
}

CITADEL_WARNING_IGNORE_POP

#include "citadel/logging/log_message.inl"
