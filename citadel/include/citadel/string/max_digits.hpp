// File:       max_digits.hpp
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

namespace citadel {
	template <typename T>
	struct max_digits {
	public:
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic");

		static constexpr std::size_t value_integral = std::is_integral_v<T> ? std::numeric_limits<T>::digits10 + 1 : 0;
		static constexpr std::size_t value_floating = std::is_integral_v<T> ? std::numeric_limits<T>::digits10 : 0;

		static constexpr std::size_t value = std::is_integral_v<T> ? value_integral : value_floating;
	};

	template <typename T>
	inline constexpr std::size_t max_digits_v = max_digits<T>::value;
}
