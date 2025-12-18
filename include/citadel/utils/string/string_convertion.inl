// File:       string_convertion.inl
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

#include <charconv>

namespace citadel {
	template <typename T>
	std::optional<T> from_characters(const std::string& string) {
		if (string.empty()) {
			return std::nullopt;
		}

		T value{ };

		const char* begin = string.data();
		const char* end = begin + string.size();

		std::from_chars_result result;

		if constexpr (std::is_arithmetic_v<T>) {
			result = std::from_chars(begin, end, value);
		}
		else {
			return std::nullopt;
		}

		if (result.ec != std::errc{} || result.ptr != end) {
			return std::nullopt;
		}

		return value;
	}

	template <typename T, typename Enabled>
	std::optional<T> to_arithmetic(const std::string& string) {
		static_assert(!std::is_arithmetic_v<T>, "Arithmetic specialisation should be picked instead of primary template");
		return std::nullopt;
	}

	template <typename T>
	std::enable_if_t<std::is_arithmetic_v<T>, std::optional<T>> to_arithmetic(const std::string& string) {
		return from_characters<T>(string);
	}
}
