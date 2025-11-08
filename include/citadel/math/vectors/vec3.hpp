// File:       vec3.hpp
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

namespace citadel {
	template <typename T>
	class basic_vec3 {
	public:
		static_assert(is_numeric_v<T>, "T must be numeric");

	public:
		static constexpr std::size_t x_index = 0;
		static constexpr std::size_t y_index = 1;
		static constexpr std::size_t z_index = 2;
		static constexpr std::size_t max_index = 3;

		T x, y, z;

	public:
		basic_vec3(T x, T y, T z);

		nodisc T get_x() const noexcept;
		void set_x(T value) noexcept;

		nodisc T get_y() const noexcept;
		void set_y(T value) noexcept;

		nodisc T get_z() const noexcept;
		void set_z(T value) noexcept;

		nodisc T& operator[](std::size_t index) noexcept;
		nodisc const T& operator[](std::size_t index) const noexcept;
	};

	using vec3 = basic_vec3<float>;
	using ivec3 = basic_vec3<int>;
	using bvec3 = basic_vec3<bool>;
}

#include "citadel/math/vectors/vec3.inl"
