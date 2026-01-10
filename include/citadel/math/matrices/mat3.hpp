// File:       mat3.hpp
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

#include "citadel/math/vectors/vec2.hpp"
#include "citadel/math/vectors/vec3.hpp"

namespace citadel {
	template <typename T>
	struct basic_mat3 {
	public:
		static_assert(std::is_arithmetic_v<T>, "T must be numeric");

	public:
		static constexpr std::size_t x_index = 0;
		static constexpr std::size_t y_index = 1;
		static constexpr std::size_t z_index = 2;
		static constexpr std::size_t max_index = 3;

		basic_vec3<T> x, y, z;

	public:
		CITADEL_NODISCARD static basic_mat3<T> identity();

		CITADEL_NODISCARD static basic_mat3<T> translated(const basic_vec2<T>& translation);

		CITADEL_NODISCARD static basic_mat3<T> rotated(const basic_vec3<T>& axis, T angle);
		CITADEL_NODISCARD static basic_mat3<T> rotated_x(T angle);
		CITADEL_NODISCARD static basic_mat3<T> rotated_y(T angle);
		CITADEL_NODISCARD static basic_mat3<T> rotated_z(T angle);

		CITADEL_NODISCARD static basic_mat3<T> scaled(const basic_vec3<T>& scale);

		basic_mat3(T unit);
		basic_mat3();

		basic_mat3(const basic_vec3<T>& x, const basic_vec3<T>& y, const basic_vec3<T>& z);
		basic_mat3(T xx, T xy, T xz, T yx, T yy, T yz, T zx, T zy, T zz);

		CITADEL_NODISCARD T determinant() const;
		CITADEL_NODISCARD basic_mat3<T> transpose() const;
		CITADEL_NODISCARD basic_mat3<T> inverse() const;

		CITADEL_NODISCARD basic_mat3<T> translate(const basic_vec2<T>& translation) const;

		CITADEL_NODISCARD basic_mat3<T> rotate(const basic_vec3<T>& axis, T angle) const;
		CITADEL_NODISCARD basic_mat3<T> rotate_x(T angle) const;
		CITADEL_NODISCARD basic_mat3<T> rotate_y(T angle) const;
		CITADEL_NODISCARD basic_mat3<T> rotate_z(T angle) const;

		CITADEL_NODISCARD basic_mat3<T> scale(const basic_vec3<T>& scale) const;

		CITADEL_NODISCARD T* data() noexcept;
		CITADEL_NODISCARD const T* data() const noexcept;

		CITADEL_NODISCARD const basic_vec3<T>& get_x() const noexcept;
		void set_x(const basic_vec3<T>& value) noexcept;

		CITADEL_NODISCARD const basic_vec3<T>& get_y() const noexcept;
		void set_y(const basic_vec3<T>& value) noexcept;

		CITADEL_NODISCARD const basic_vec3<T>& get_z() const noexcept;
		void set_z(const basic_vec3<T>& value) noexcept;

		CITADEL_NODISCARD basic_vec3<T>& operator[](std::size_t index) noexcept;
		CITADEL_NODISCARD const basic_vec3<T>& operator[](std::size_t index) const noexcept;

		CITADEL_NODISCARD basic_mat3<T> operator+(const basic_mat3<T>& other) const;
		basic_mat3<T>& operator+=(const basic_mat3<T>& other);

		CITADEL_NODISCARD basic_mat3<T> operator-(const basic_mat3<T>& other) const;
		basic_mat3<T>& operator-=(const basic_mat3<T>& other);

		CITADEL_NODISCARD basic_mat3<T> operator*(const basic_mat3<T>& other) const;
		basic_mat3<T>& operator*=(const basic_mat3<T>& other);

		CITADEL_NODISCARD basic_vec3<T> operator*(const basic_vec3<T>& vector) const;

		CITADEL_NODISCARD basic_mat3<T> operator*(T scalar) const;
		basic_mat3<T>& operator*=(T scalar);
	};

	using mat3 = basic_mat3<float>;
	using imat3 = basic_mat3<int>;
	using bmat3 = basic_mat3<bool>;
}

#include "citadel/math/matrices/mat3.inl"
