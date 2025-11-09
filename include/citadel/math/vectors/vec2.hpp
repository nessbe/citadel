// File:       vec2.hpp
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

#include <cstddef>
#include <type_traits>

#include "citadel/attributes.hpp"
#include "citadel/type_traits.hpp"

namespace citadel {
	template <typename T>
	struct basic_vec2 {
	public:
		static_assert(is_numeric_v<T>, "T must be numeric");

	public:
		static constexpr std::size_t x_index = 0;
		static constexpr std::size_t y_index = 1;
		static constexpr std::size_t max_index = 2;

		T x, y;

	public:
		basic_vec2(T x, T y);

		nodisc T* data() noexcept;
		nodisc const T* data() const noexcept;

		nodisc T get_x() const noexcept;
		void set_x(T value) noexcept;

		nodisc T get_y() const noexcept;
		void set_y(T value) noexcept;

		nodisc T& operator[](std::size_t index) noexcept;
		nodisc const T& operator[](std::size_t index) const noexcept;
	};

	using vec2 = basic_vec2<float>;
	using ivec2 = basic_vec2<int>;
	using bvec2 = basic_vec2<bool>;
}

#include "citadel/math/vectors/vec2.inl"
