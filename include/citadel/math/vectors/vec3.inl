// File:       vec3.inl
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

#include <cmath>

#include "citadel/assert.hpp"
#include "vec3.hpp"

namespace citadel {
	template<typename T>
	basic_vec3<T>::basic_vec3()
		: x(0), y(0), z(0) { }

	template <typename T>
	basic_vec3<T>::basic_vec3(T x, T y, T z)
		: x(x), y(y), z(z) { }

	template <typename T>
	T basic_vec3<T>::length() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	template <typename T>
	basic_vec3<T> basic_vec3<T>::normalized() const {
		return (*this) / length();
	}

	template <typename T>
	T basic_vec3<T>::distance(const basic_vec3<T>& other) const {
		return (*this - other).length();
	}

	template <typename T>
	T basic_vec3<T>::dot(const basic_vec3<T>& other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	template <typename T>
	basic_vec3<T> basic_vec3<T>::cross(const basic_vec3<T>& other) const {
		return basic_vec3<T>(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		);
	}

	template <typename T>
	T* basic_vec3<T>::data() noexcept {
		return &x;
	}

	template <typename T>
	const T* basic_vec3<T>::data() const noexcept {
		return &x;
	}

	template <typename T>
	T basic_vec3<T>::get_x() const noexcept {
		return x;
	}

	template <typename T>
	void basic_vec3<T>::set_x(T value) noexcept {
		x = value;
	}

	template <typename T>
	T basic_vec3<T>::get_y() const noexcept {
		return y;
	}

	template <typename T>
	void basic_vec3<T>::set_y(T value) noexcept {
		y = value;
	}

	template <typename T>
	T basic_vec3<T>::get_z() const noexcept {
		return z;
	}

	template <typename T>
	void basic_vec3<T>::set_z(T value) noexcept {
		z = value;
	}

	template <typename T>
	T& basic_vec3<T>::operator[](std::size_t index) noexcept {
		CITADEL_ASSERT(index < max_index, "Index is out of range");
		return (&x)[index];
	}

	template <typename T>
	const T& basic_vec3<T>::operator[](std::size_t index) const noexcept {
		CITADEL_ASSERT(index < max_index, "Index is out of range");
		return (&x)[index];
	}

	template <typename T>
	basic_vec3<T> basic_vec3<T>::operator+(const basic_vec3<T>& other) const {
		return basic_vec3<T>(
			x + other.x,
			y + other.y,
			z + other.z
		);
	}

	template <typename T>
	basic_vec3<T>& basic_vec3<T>::operator+=(const basic_vec3<T>& other) {
		*this = *this + other;
		return *this;
	}

	template <typename T>
	basic_vec3<T> basic_vec3<T>::operator-(const basic_vec3<T>& other) const {
		return basic_vec3<T>(
			x - other.x,
			y - other.y,
			z - other.z
		);
	}

	template <typename T>
	basic_vec3<T>& basic_vec3<T>::operator-=(const basic_vec3<T>& other) {
		*this = *this - other;
		return *this;
	}

	template <typename T>
	basic_vec3<T> basic_vec3<T>::operator*(const basic_vec3<T>& other) const {
		return basic_vec3<T>(
			x * other.x,
			y * other.y,
			z * other.z
		);
	}

	template <typename T>
	basic_vec3<T>& basic_vec3<T>::operator*=(const basic_vec3<T>& other) {
		*this = *this * other;
		return *this;
	}

	template <typename T>
	basic_vec3<T> basic_vec3<T>::operator*(T scalar) const {
		return basic_vec3<T>(
			x * scalar,
			y * scalar,
			z * scalar
		);
	}

	template <typename T>
	basic_vec3<T>& basic_vec3<T>::operator*=(T scalar) {
		*this = *this * scalar;
		return *this;
	}

	template <typename T>
	basic_vec3<T> basic_vec3<T>::operator/(const basic_vec3<T>& other) const {
		return basic_vec3<T>(
			x / other.x,
			y / other.y,
			z / other.z
		);
	}

	template <typename T>
	basic_vec3<T>& basic_vec3<T>::operator/=(const basic_vec3<T>& other) {
		*this = *this / other;
		return *this;
	}

	template <typename T>
	basic_vec3<T> basic_vec3<T>::operator/(T scalar) const {
		return basic_vec3<T>(
			x / scalar,
			y / scalar,
			z / scalar
		);
	}

	template <typename T>
	basic_vec3<T>& basic_vec3<T>::operator/=(T scalar) {
		*this = *this / scalar;
		return *this;
	}
}
