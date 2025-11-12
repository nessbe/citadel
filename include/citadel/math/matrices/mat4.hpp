// File:       mat4.hpp
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

#include "citadel/math/vectors/vec4.hpp"

namespace citadel {
	template <typename T>
	struct basic_mat4 {
	public:
		static_assert(is_numeric_v<T>, "T must be numeric");

	public:
		static constexpr std::size_t x_index = 0;
		static constexpr std::size_t y_index = 1;
		static constexpr std::size_t z_index = 2;
		static constexpr std::size_t w_index = 3;
		static constexpr std::size_t max_index = 4;

		basic_vec4<T> x, y, z, w;

	public:
		static basic_mat4<T> identity();

		static basic_mat4<T> ortho(T left, T right, T bottom, T top, T near, T far);

		basic_mat4(const basic_vec4<T>& x, const basic_vec4<T>& y, const basic_vec4<T>& z, const basic_vec4<T>& w);
		basic_mat4(T xx, T xy, T xz, T xw, T yx, T yy, T yz, T yw, T zx, T zy, T zz, T zw, T wx, T wy, T wz, T ww);

		nodisc basic_mat4<T> inverse() const;

		nodisc T* data() noexcept;
		nodisc const T* data() const noexcept;

		nodisc const basic_vec4<T>& get_x() const noexcept;
		void set_x(const basic_vec4<T>& value) noexcept;

		nodisc const basic_vec4<T>& get_y() const noexcept;
		void set_y(const basic_vec4<T>& value) noexcept;

		nodisc const basic_vec4<T>& get_z() const noexcept;
		void set_z(const basic_vec4<T>& value) noexcept;

		nodisc const basic_vec4<T>& get_w() const noexcept;
		void set_w(const basic_vec4<T>& value) noexcept;

		nodisc basic_vec4<T>& operator[](std::size_t index) noexcept;
		nodisc const basic_vec4<T>& operator[](std::size_t index) const noexcept;

		nodisc basic_mat4<T> operator+(const basic_mat4<T>& other) const;
		nodisc basic_mat4<T>& operator+=(const basic_mat4<T>& other);

		nodisc basic_mat4<T> operator-(const basic_mat4<T>& other) const;
		nodisc basic_mat4<T>& operator-=(const basic_mat4<T>& other);

		nodisc basic_mat4<T> operator*(const basic_mat4<T>& other) const;
		nodisc basic_mat4<T>& operator*=(const basic_mat4<T>& other);

		nodisc basic_vec4<T> operator*(const basic_vec4<T>& vector) const;

		nodisc basic_mat4<T> operator*(T scalar) const;
		nodisc basic_mat4<T>& operator*=(T scalar);
	};

	using mat4 = basic_mat4<float>;
	using imat4 = basic_mat4<int>;
	using bmat4 = basic_mat4<bool>;
}

#include "citadel/math/matrices/mat4.inl"
