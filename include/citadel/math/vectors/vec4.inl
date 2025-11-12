// File:       vec4.inl
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

#include "citadel/assert.hpp"

namespace citadel {
	template <typename T>
	basic_vec4<T>::basic_vec4(T x, T y, T z, T w)
		: x(x), y(y), z(z), w(w) {
	}

	template <typename T>
	T* basic_vec4<T>::data() noexcept {
		return &x;
	}

	template <typename T>
	const T* basic_vec4<T>::data() const noexcept {
		return &x;
	}

	template <typename T>
	T basic_vec4<T>::get_x() const noexcept {
		return x;
	}

	template <typename T>
	void basic_vec4<T>::set_x(T value) noexcept {
		x = value;
	}

	template <typename T>
	T basic_vec4<T>::get_y() const noexcept {
		return y;
	}

	template <typename T>
	void basic_vec4<T>::set_y(T value) noexcept {
		y = value;
	}

	template <typename T>
	T basic_vec4<T>::get_z() const noexcept {
		return z;
	}

	template <typename T>
	void basic_vec4<T>::set_z(T value) noexcept {
		z = value;
	}

	template <typename T>
	T basic_vec4<T>::get_w() const noexcept {
		return w;
	}

	template <typename T>
	void basic_vec4<T>::set_w(T value) noexcept {
		w = value;
	}

	template <typename T>
	T& basic_vec4<T>::operator[](std::size_t index) noexcept {
		CITADEL_ASSERT(index < max_index, "Index is out of range");
		return (&x)[index];
	}

	template <typename T>
	const T& basic_vec4<T>::operator[](std::size_t index) const noexcept {
		CITADEL_ASSERT(index < max_index, "Index is out of range");
		return (&x)[index];
	}

	template <typename T>
	basic_vec4<T> basic_vec4<T>::operator+(const basic_vec4<T>& other) const {
		return basic_vec4<T>(
			x + other.x,
			y + other.y,
			z + other.z,
			w + other.w
		);
	}

	template <typename T>
	basic_vec4<T>& basic_vec4<T>::operator+=(const basic_vec4<T>& other) {
		*this = *this + other;
		return *this;
	}

	template <typename T>
	basic_vec4<T> basic_vec4<T>::operator-(const basic_vec4<T>& other) const {
		return basic_vec4<T>(
			x - other.x,
			y - other.y,
			z - other.z,
			w - other.w
		);
	}

	template <typename T>
	basic_vec4<T>& basic_vec4<T>::operator-=(const basic_vec4<T>& other) {
		*this = *this - other;
		return *this;
	}

	template <typename T>
	basic_vec4<T> basic_vec4<T>::operator*(const basic_vec4<T>& other) const {
		return basic_vec4<T>(
			x * other.x,
			y * other.y,
			z * other.z,
			w * other.w
		);
	}

	template <typename T>
	basic_vec4<T>& basic_vec4<T>::operator*=(const basic_vec4<T>& other) {
		*this = *this * other;
		return *this;
	}

	template <typename T>
	basic_vec4<T> basic_vec4<T>::operator*(T scalar) const {
		return basic_vec4<T>(
			x * scalar,
			y * scalar,
			z * scalar,
			w * scalar
		);
	}

	template <typename T>
	basic_vec4<T>& basic_vec4<T>::operator*=(T scalar) {
		*this = *this * scalar;
		return *this;
	}

	template <typename T>
	basic_vec4<T> basic_vec4<T>::operator/(const basic_vec4<T>& other) const {
		return basic_vec4<T>(
			x / other.x,
			y / other.y,
			z / other.z,
			w / other.w
		);
	}

	template <typename T>
	basic_vec4<T>& basic_vec4<T>::operator/=(const basic_vec4<T>& other) {
		*this = *this / other;
		return *this;
	}

	template <typename T>
	basic_vec4<T> basic_vec4<T>::operator/(T scalar) const {
		return basic_vec4<T>(
			x / scalar,
			y / scalar,
			z / scalar,
			w / scalar
		);
	}

	template <typename T>
	basic_vec4<T>& basic_vec4<T>::operator/=(T scalar) {
		*this = *this / scalar;
		return *this;
	}
}
