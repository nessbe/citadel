// File:       stringifiable.hpp
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

#include <string>
#include <type_traits>

namespace citadel {
	template <typename T, typename Enabled = void>
	struct stringifiable;

	template <>
	struct stringifiable<std::string> {
		static inline std::string to_string(const std::string& value);
	};

	template <>
	struct stringifiable<bool> {
		static inline std::string to_string(bool value);
	};

	template <typename T>
	struct stringifiable<T, std::enable_if_t<std::is_arithmetic_v<T>>> {
		static inline std::string to_string(T value);
	};
}

#include "citadel/utils/string/stringifiable.inl"
