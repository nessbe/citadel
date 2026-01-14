// File:       is_stringifiable.hpp
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

#include "citadel/utils/string/stringifiable.hpp"

namespace citadel {
	template <typename, typename = void>
	struct is_stringifiable : std::false_type { };

	template <typename T>
	struct is_stringifiable<
		T,
		std::void_t<
			decltype(stringifiable<T>::to_string(
				std::declval<const T&>()
			))
		>
	> : std::bool_constant<
		std::is_convertible_v<
			decltype(stringifiable<T>::to_string(
				std::declval<const T&>()
			)),
			std::string
		>
	> { };

	template <typename T>
	inline constexpr bool is_stringifiable_v = is_stringifiable<T>::value;
}
