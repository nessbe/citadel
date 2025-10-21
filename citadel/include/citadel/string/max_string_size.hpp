// File:       max_string_size.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#pragma once

#include <cstddef>
#include <limits>
#include <type_traits>

#include "citadel/attributes.hpp"

namespace citadel {
	template <typename T, typename Enable = void>
	struct max_string_size {
		static constexpr std::size_t value = 0;
	};

	template <typename T>
	struct max_string_size<T, std::enable_if_t<std::is_integral_v<T>>> {
		static constexpr bool is_signed = std::is_signed_v<T>;
		static constexpr std::size_t value = []() constexpr {
			using UT = std::make_unsigned_t<T>;

			UT max_value = std::numeric_limits<UT>::max();
			std::size_t digits = 0;

			while (max_value != 0) {
				digits++;
				max_value /= 10;
			}

			return digits + (is_signed ? 1 : 0);
		}();
	};

	template <typename T>
	struct max_string_size<T, std::enable_if_t<std::is_floating_point_v<T>>> {
		static constexpr std::size_t value = std::numeric_limits<T>::digits10 + 2;
	};

	template <>
	struct max_string_size<bool> {
		static constexpr std::size_t value = 5;
	};

	template <typename T>
	struct max_string_size<T*> {
		static constexpr std::size_t value = 2 + sizeof(void*) * 2;
	};

	template <typename T>
	inline constexpr std::size_t max_string_size_v = max_string_size<T>::value;
}
