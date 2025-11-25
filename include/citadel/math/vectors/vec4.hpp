// File:       vec4.hpp
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
	struct basic_vec4 {
	public:
		static_assert(is_numeric_v<T>, "T must be numeric");

	public:
		static constexpr std::size_t x_index = 0;
		static constexpr std::size_t y_index = 1;
		static constexpr std::size_t z_index = 2;
		static constexpr std::size_t w_index = 3;
		static constexpr std::size_t max_index = 4;

		T x, y, z, w;

	public:
		basic_vec4();
		basic_vec4(T x, T y, T z, T w);

		nodisc T length() const;
		nodisc basic_vec4<T> normalized() const;

		nodisc T distance(const basic_vec4<T>& other) const;

		nodisc T dot(const basic_vec4<T>& other) const;

		nodisc T* data() noexcept;
		nodisc const T* data() const noexcept;

		nodisc T get_x() const noexcept;
		void set_x(T value) noexcept;

		nodisc T get_y() const noexcept;
		void set_y(T value) noexcept;

		nodisc T get_z() const noexcept;
		void set_z(T value) noexcept;

		nodisc T get_w() const noexcept;
		void set_w(T value) noexcept;

		nodisc T& operator[](std::size_t index) noexcept;
		nodisc const T& operator[](std::size_t index) const noexcept;

		nodisc basic_vec4<T> operator+(const basic_vec4<T>& other) const;
		basic_vec4<T>& operator+=(const basic_vec4<T>& other);

		nodisc basic_vec4<T> operator-(const basic_vec4<T>& other) const;
		basic_vec4<T>& operator-=(const basic_vec4<T>& other);

		nodisc basic_vec4<T> operator*(const basic_vec4<T>& other) const;
		basic_vec4<T>& operator*=(const basic_vec4<T>& other);

		nodisc basic_vec4<T> operator*(T scalar) const;
		basic_vec4<T>& operator*=(T scalar);

		nodisc basic_vec4<T> operator/(const basic_vec4<T>& other) const;
		basic_vec4<T>& operator/=(const basic_vec4<T>& other);

		nodisc basic_vec4<T> operator/(T scalar) const;
		basic_vec4<T>& operator/=(T scalar);
	};

	using vec4 = basic_vec4<float>;
	using ivec4 = basic_vec4<int>;
	using bvec4 = basic_vec4<bool>;
}

#include "citadel/math/vectors/vec4.inl"
