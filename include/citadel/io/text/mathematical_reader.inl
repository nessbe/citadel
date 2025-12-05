// File:       mathematical_reader.inl
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

#include "citadel/warnings.hpp"

#include "citadel/utils/string/string_convertion.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_SPECTRE)

	template <typename T>
	basic_vec2<T> mathematical_reader::read_basic_vec2(const std::string& separator) {
		basic_vec2<T> result;

		for (std::size_t i = 0; i < basic_vec2<T>::max_index; i++) {
			T value = T(0);

			std::string string_value;
			string_value.reserve(8);

			if constexpr (std::is_integral_v<T>) {
				string_value = reader_.read_integer();
			}
			else if constexpr (std::is_floating_point_v<T>) {
				string_value = reader_.read_floating_point();
			}

			if (std::optional<T> optional_value = to_arithmetic<T>(string_value)) {
				value = optional_value.value();
			}

			result[i] = value;

			reader_.read_while_matching(separator);
		}

		return result;
	}

	template <typename T>
	basic_vec3<T> mathematical_reader::read_basic_vec3(const std::string& separator) {
		basic_vec3<T> result;

		for (std::size_t i = 0; i < basic_vec3<T>::max_index; i++) {
			T value = T(0);

			std::string string_value;
			string_value.reserve(8);

			if constexpr (std::is_integral_v<T>) {
				string_value = reader_.read_integer();
			}
			else if constexpr (std::is_floating_point_v<T>) {
				string_value = reader_.read_floating_point();
			}
			
			if (std::optional<T> optional_value = to_arithmetic<T>(string_value)) {
				value = optional_value.value();
			}

			result[i] = value;

			reader_.read_while_matching(separator);
		}

		return result;
	}

CITADEL_WARNING_IGNORE_POP

}
