// File:       has_ostream_operator.hpp
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

#include <ostream>
#include <type_traits>

namespace citadel {
	template <typename, typename = void>
	struct has_ostream_operator : std::false_type { };

	template <typename T>
	struct has_ostream_operator<
		T,
		std::void_t<
			decltype(
				std::declval<std::ostream&>()
				<< std::declval<const T&>()
			)
		>
	> : std::true_type { };

	template <typename T>
	inline constexpr bool has_ostream_operator_v = has_ostream_operator<T>::value;
}
