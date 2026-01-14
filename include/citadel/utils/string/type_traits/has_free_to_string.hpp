// File:       has_free_to_string.hpp
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

#include "citadel/utils/string/type_traits/adl_to_string.hpp"

namespace citadel {
	template <typename, typename = void>
	struct has_free_to_string : std::false_type { };

	template <typename T>
	struct has_free_to_string<
		T,
		std::void_t<
			decltype(detail::adl_to_string(
				std::declval<const T&>()
			))
		>
	> : std::bool_constant<
		std::is_convertible_v<
			decltype(detail::adl_to_string(
				std::declval<const T&>()
			)),
			std::string
		>
	> { };

	template <typename T>
	inline constexpr bool has_free_to_string_v = has_free_to_string<T>::value;
}
