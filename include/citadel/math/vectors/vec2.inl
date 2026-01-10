// File:       vec2.inl
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include <cmath>

#include "citadel/debug/assert.hpp"

namespace citadel {
	template <typename T>
	basic_vec2<T>::basic_vec2()
		: x(0), y(0) { }

	template <typename T>
	basic_vec2<T>::basic_vec2(T x, T y)
		: x(x), y(y) { }

	template <typename T>
	T basic_vec2<T>::length() const {
		return std::sqrt(x * x + y * y);
	}

	template <typename T>
	basic_vec2<T> basic_vec2<T>::normalized() const {
		return (*this) / length();
	}

	template <typename T>
	T basic_vec2<T>::distance(const basic_vec2<T>& other) const {
		return (*this - other).length();
	}

	template <typename T>
	T basic_vec2<T>::dot(const basic_vec2<T>& other) const {
		return x * other.x + y * other.y;
	}

	template <typename T>
	T* basic_vec2<T>::data() noexcept {
		return &x;
	}

	template <typename T>
	const T* basic_vec2<T>::data() const noexcept {
		return &x;
	}

	template <typename T>
	T basic_vec2<T>::get_x() const noexcept {
		return x;
	}

	template <typename T>
	void basic_vec2<T>::set_x(T value) noexcept {
		x = value;
	}

	template <typename T>
	T basic_vec2<T>::get_y() const noexcept {
		return y;
	}

	template <typename T>
	void basic_vec2<T>::set_y(T value) noexcept {
		y = value;
	}

	template <typename T>
	T& basic_vec2<T>::operator[](std::size_t index) noexcept {
		CITADEL_ASSERT(index < max_index, "Index is out of range");
		return (&x)[index];
	}

	template <typename T>
	const T& basic_vec2<T>::operator[](std::size_t index) const noexcept {
		CITADEL_ASSERT(index < max_index, "Index is out of range");
		return (&x)[index];
	}

	template <typename T>
	basic_vec2<T> basic_vec2<T>::operator+(const basic_vec2<T>& other) const {
		return basic_vec2<T>(
			x + other.x,
			y + other.y
		);
	}

	template <typename T>
	basic_vec2<T>& basic_vec2<T>::operator+=(const basic_vec2<T>& other) {
		*this = *this + other;
		return *this;
	}

	template <typename T>
	basic_vec2<T> basic_vec2<T>::operator-(const basic_vec2<T>& other) const {
		return basic_vec2<T>(
			x - other.x,
			y - other.y
		);
	}

	template <typename T>
	basic_vec2<T>& basic_vec2<T>::operator-=(const basic_vec2<T>& other) {
		*this = *this - other;
		return *this;
	}

	template <typename T>
	basic_vec2<T> basic_vec2<T>::operator*(const basic_vec2<T>& other) const {
		return basic_vec2<T>(
			x * other.x,
			y * other.y
		);
	}

	template <typename T>
	basic_vec2<T>& basic_vec2<T>::operator*=(const basic_vec2<T>& other) {
		*this = *this * other;
		return *this;
	}

	template <typename T>
	basic_vec2<T> basic_vec2<T>::operator*(T scalar) const {
		return basic_vec2<T>(
			x * scalar,
			y * scalar
		);
	}

	template <typename T>
	basic_vec2<T>& basic_vec2<T>::operator*=(T scalar) {
		*this = *this * scalar;
		return *this;
	}

	template <typename T>
	basic_vec2<T> basic_vec2<T>::operator/(const basic_vec2<T>& other) const {
		return basic_vec2<T>(
			x / other.x,
			y / other.y
		);
	}

	template <typename T>
	basic_vec2<T>& basic_vec2<T>::operator/=(const basic_vec2<T>& other) {
		*this = *this / other;
		return *this;
	}

	template <typename T>
	basic_vec2<T> basic_vec2<T>::operator/(T scalar) const {
		return basic_vec2<T>(
			x / scalar,
			y / scalar
		);
	}

	template <typename T>
	basic_vec2<T>& basic_vec2<T>::operator/=(T scalar) {
		*this = *this / scalar;
		return *this;
	}
}
