// File:       mat3.inl
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

namespace citadel {
	template <typename T>
	basic_mat3<T> basic_mat3<T>::identity() {
		return basic_mat3<T>(
			1, 0, 0,
			0, 1, 0,
			0, 0, 1
		);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::translated(const basic_vec2<T>& translation) {
		return basic_mat3<T>(
			1,             0,             0,
			0,             1,             0,
			translation.x, translation.y, 1
		);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::rotated(const basic_vec3<T>& axis, T angle) {
		basic_vec3<T> normalized_axis = axis.normalized();

		T cosinus = std::cos(angle);
		T sinus = std::sin(angle);
		T term = T(1) - cosinus;

		T x = normalized_axis.x, y = normalized_axis.y, z = normalized_axis.z;

		return basic_mat3<T>(
			term * x * x + cosinus,
			term * x * y + sinus * z,
			term * x * z - sinus * y,

			term * x * y - sinus * z,
			term * y * y + cosinus,
			term * y * z + sinus * x,

			term * x * z + sinus * y,
			term * y * z - sinus * x,
			term * z * z + cosinus
		);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::rotated_x(T angle) {
		T cosinus = std::cos(angle);
		T sinus = std::sin(angle);

		return basic_mat3<T>(
			1, 0,       0,
			0, cosinus, sinus,
			0, -sinus,  cosinus
		);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::rotated_y(T angle) {
		T cosinus = std::cos(angle);
		T sinus = std::sin(angle);

		return basic_mat3<T>(
			cosinus, 0, sinus,
			0,       1, 0,
			sinus,   0, cosinus
		);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::rotated_z(T angle) {
		T cosinus = std::cos(angle);
		T sinus = std::sin(angle);

		return basic_mat3<T>(
			cosinus, sinus,   0,
			-sinus,  cosinus, 0,
			0,       0,       1
		);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::scaled(const basic_vec3<T>& scale) {
		return basic_mat3<T>(
			scale.x, 0,       0,
			0,       scale.y, 0,
			0,       0,       scale.z
		);
	}

	template <typename T>
	basic_mat3<T>::basic_mat3(const basic_vec3<T>& x, const basic_vec3<T>& y, const basic_vec3<T>& z)
		: x(x), y(y), z(z) { }

	template <typename T>
	basic_mat3<T>::basic_mat3(T xx, T xy, T xz, T yx, T yy, T yz, T zx, T zy, T zz)
		: x(xx, xy, xz), y(yx, yy, yz), z(zx, zy, zz) { }

	template <typename T>
	T basic_mat3<T>::determinant() const {
		return
			x.x * (y.y * z.z - y.z * z.y) -
			y.x * (x.y * z.z - x.z * z.y) +
			z.x * (x.y * y.z - x.z * y.y);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::transpose() const {
		return basic_mat3<T>(
			x.x, y.x, z.x,
			x.y, y.y, z.y,
			x.z, y.z, z.z
		);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::inverse() const {
		T determinant = this->determinant();

		if (determinant == T(0)) {
			CITADEL_PANIC("Matrix is not invertible");
			return identity();
		}

		T inverted_determinant = T(1) / determinant;

		T determinant_yz = y.y * z.z - y.z * z.y;
		T determinant_xz = x.y * z.z - x.z * z.y;
		T determinant_xy = x.y * y.z - x.z * y.y;
		T determinant_yz_x = y.x * z.z - y.z * z.x;
		T determinant_xz_x = x.x * z.z - x.z * z.x;
		T determinant_xy_x = x.x * y.z - x.z * y.x;
		T determinant_yz_y = y.x * z.y - y.y * z.x;
		T determinant_xz_y = x.x * z.y - x.y * z.x;
		T determinant_xy_y = x.x * y.y - x.y * y.x;

		return basic_mat3<T>(
			determinant_yz, -determinant_xz, determinant_xy,
			-determinant_yz_x, determinant_xz_x, -determinant_xy_x,
			determinant_yz_y, -determinant_xz_y, determinant_xy_y
		) * inverted_determinant;
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::translate(const basic_vec2<T>& translation) const {
		return *this * translated(translation);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::rotate(const basic_vec3<T>& axis, T angle) const {
		return *this * rotated(axis, angle);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::rotate_x(T angle) const {
		return *this * rotated_x(angle);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::rotate_y(T angle) const {
		return *this * rotated_y(angle);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::rotate_z(T angle) const {
		return *this * rotated_z(angle);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::scale(const basic_vec3<T>& scale) const {
		return *this * scaled(scale);
	}

	template <typename T>
	T* basic_mat3<T>::data() noexcept {
		return x.data();
	}

	template <typename T>
	const T* basic_mat3<T>::data() const noexcept {
		return x.data();
	}

	template <typename T>
	const basic_vec3<T>& basic_mat3<T>::get_x() const noexcept {
		return x;
	}

	template <typename T>
	void basic_mat3<T>::set_x(const basic_vec3<T>& value) noexcept {
		x = value;
	}

	template <typename T>
	const basic_vec3<T>& basic_mat3<T>::get_y() const noexcept {
		return y;
	}

	template <typename T>
	void basic_mat3<T>::set_y(const basic_vec3<T>& value) noexcept {
		y = value;
	}

	template <typename T>
	const basic_vec3<T>& basic_mat3<T>::get_z() const noexcept {
		return z;
	}

	template <typename T>
	void basic_mat3<T>::set_z(const basic_vec3<T>& value) noexcept {
		z = value;
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::operator+(const basic_mat3<T>& other) const {
		return basic_mat3<T>(
			x + other.x,
			y + other.y,
			z + other.z
		);
	}

	template <typename T>
	basic_mat3<T>& basic_mat3<T>::operator+=(const basic_mat3<T>& other) {
		*this = *this + other;
		return *this;
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::operator-(const basic_mat3<T>& other) const {
		return basic_mat3<T>(
			x - other.x,
			y - other.y,
			z - other.z
		);
	}

	template <typename T>
	basic_mat3<T>& basic_mat3<T>::operator-=(const basic_mat3<T>& other) {
		*this = *this - other;
		return *this;
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::operator*(const basic_mat3<T>& other) const {
		return basic_mat3<T>(
			x.x * other.x.x + y.x * other.x.y + z.x * other.x.z,
			x.y * other.x.x + y.y * other.x.y + z.y * other.x.z,
			x.z * other.x.x + y.z * other.x.y + z.z * other.x.z,

			x.x * other.y.x + y.x * other.y.y + z.x * other.y.z,
			x.y * other.y.x + y.y * other.y.y + z.y * other.y.z,
			x.z * other.y.x + y.z * other.y.y + z.z * other.y.z,

			x.x * other.z.x + y.x * other.z.y + z.x * other.z.z,
			x.y * other.z.x + y.y * other.z.y + z.y * other.z.z,
			x.z * other.z.x + y.z * other.z.y + z.z * other.z.z
		);
	}

	template <typename T>
	basic_mat3<T>& basic_mat3<T>::operator*=(const basic_mat3<T>& other) {
		*this = *this * other;
		return *this;
	}

	template <typename T>
	basic_vec3<T> basic_mat3<T>::operator*(const basic_vec3<T>& vector) const {
		return basic_vec3<T>(
			x.x * vector.x + y.x * vector.y + z.x * vector.z,
			x.y * vector.x + y.y * vector.y + z.y * vector.z,
			x.z * vector.x + y.z * vector.y + z.z * vector.z
		);
	}

	template <typename T>
	basic_mat3<T> basic_mat3<T>::operator*(T scalar) const {
		return basic_mat3<T>(
			x * scalar,
			y * scalar,
			z * scalar
		);
	}

	template <typename T>
	basic_mat3<T>& basic_mat3<T>::operator*=(T scalar) {
		*this = *this * other;
		return *this;
	}
}
