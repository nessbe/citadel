// File:       epsilon.hpp
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

#include <limits>
#include <type_traits>

#include "citadel/attributes.hpp"
#include "citadel/type_traits.hpp"

namespace citadel {
	template <typename T, typename Enabled = void>
	struct epsilon {
		static constexpr T value = T(0);
	};

	template <typename T>
	struct epsilon<T, std::enable_if_t<is_numeric_v<T>>> {
		static constexpr T value = std::numeric_limits<T>::epsilon();
	};

	template <typename T>
	nodisc bool epsilon_equal(T x, T y) noexcept;

	template <typename T>
	nodisc bool epsilon_not_equal(T x, T y) noexcept;
}

#include "citadel/math/epsilon.inl"
