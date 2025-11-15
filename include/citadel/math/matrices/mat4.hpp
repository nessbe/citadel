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

#include "citadel/math/vectors/vec3.hpp"
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
		nodisc static basic_mat4<T> identity();

		nodisc static basic_mat4<T> view(const basic_vec3<T>& eye, const basic_vec3<T>& center, const basic_vec3<T>& up);
		nodisc static basic_mat4<T> ortho(T left, T right, T bottom, T top, T near, T far);
		nodisc static basic_mat4<T> perspective(T fov, T aspect, T near, T far);

		nodisc static basic_mat4<T> translated(const basic_vec3<T>& translation);

		nodisc static basic_mat4<T> rotated(const basic_vec3<T>& axis, T angle);
		nodisc static basic_mat4<T> rotated_x(T angle);
		nodisc static basic_mat4<T> rotated_y(T angle);
		nodisc static basic_mat4<T> rotated_z(T angle);

		nodisc static basic_mat4<T> scaled(const basic_vec3<T>& scale);

		basic_mat4(T unit);
		basic_mat4();

		basic_mat4(const basic_vec4<T>& x, const basic_vec4<T>& y, const basic_vec4<T>& z, const basic_vec4<T>& w);
		basic_mat4(T xx, T xy, T xz, T xw, T yx, T yy, T yz, T yw, T zx, T zy, T zz, T zw, T wx, T wy, T wz, T ww);

		nodisc T determinant() const;
		nodisc basic_mat4<T> transpose() const;
		nodisc basic_mat4<T> inverse() const;

		nodisc basic_mat4<T> translate(const basic_vec3<T>& translation) const;

		nodisc basic_mat4<T> rotate(const basic_vec3<T>& axis, T angle) const;
		nodisc basic_mat4<T> rotate_x(T angle) const;
		nodisc basic_mat4<T> rotate_y(T angle) const;
		nodisc basic_mat4<T> rotate_z(T angle) const;

		nodisc basic_mat4<T> scale(const basic_vec3<T>& scale) const;

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
