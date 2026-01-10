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

namespace citadel {
	template <typename T>
	struct basic_vec2 {
	public:
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic");

	public:
		static constexpr std::size_t x_index = 0;
		static constexpr std::size_t y_index = 1;
		static constexpr std::size_t max_index = 2;

		T x, y;

	public:
		basic_vec2();
		basic_vec2(T x, T y);

		CITADEL_NODISCARD T length() const;
		CITADEL_NODISCARD basic_vec2<T> normalized() const;

		CITADEL_NODISCARD T distance(const basic_vec2<T>& other) const;

		CITADEL_NODISCARD T dot(const basic_vec2<T>& other) const;

		CITADEL_NODISCARD T* data() noexcept;
		CITADEL_NODISCARD const T* data() const noexcept;

		CITADEL_NODISCARD T get_x() const noexcept;
		void set_x(T value) noexcept;

		CITADEL_NODISCARD T get_y() const noexcept;
		void set_y(T value) noexcept;

		CITADEL_NODISCARD T& operator[](std::size_t index) noexcept;
		CITADEL_NODISCARD const T& operator[](std::size_t index) const noexcept;

		CITADEL_NODISCARD basic_vec2<T> operator+(const basic_vec2<T>& other) const;
		basic_vec2<T>& operator+=(const basic_vec2<T>& other);

		CITADEL_NODISCARD basic_vec2<T> operator-(const basic_vec2<T>& other) const;
		basic_vec2<T>& operator-=(const basic_vec2<T>& other);

		CITADEL_NODISCARD basic_vec2<T> operator*(const basic_vec2<T>& other) const;
		basic_vec2<T>& operator*=(const basic_vec2<T>& other);

		CITADEL_NODISCARD basic_vec2<T> operator*(T scalar) const;
		CITADEL_NODISCARD basic_vec2<T>& operator*=(T scalar);

		CITADEL_NODISCARD basic_vec2<T> operator/(const basic_vec2<T>& other) const;
		basic_vec2<T>& operator/=(const basic_vec2<T>& other);

		CITADEL_NODISCARD basic_vec2<T> operator/(T scalar) const;
		basic_vec2<T>& operator/=(T scalar);
	};

	using vec2 = basic_vec2<float>;
	using ivec2 = basic_vec2<int>;
	using bvec2 = basic_vec2<bool>;
}

#include "citadel/math/vectors/vec2.inl"
