// File:       type_traits.hpp
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

namespace citadel {
	template <typename T>
	struct is_numeric : public std::bool_constant<
			std::is_integral_v<T> ||
			std::is_floating_point_v<T>
	> { };

	template <typename T>
	constexpr bool is_numeric_v = is_numeric<T>::value;
}
