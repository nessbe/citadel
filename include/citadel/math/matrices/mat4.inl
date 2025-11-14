// File:       mat4.inl
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

namespace citadel {
	template <typename T>
	basic_mat4<T> basic_mat4<T>::identity() {
		return basic_mat4<T>(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::view(const basic_vec3<T>& eye, const basic_vec3<T>& center, const basic_vec3<T>& up) {
		basic_vec3<T> forward = (center - eye).normalized();
		basic_vec3<T> right = forward.cross(up).normalized();
		basic_vec3<T> camera_up = right.cross(forward);

		return basic_mat4<T>(
			right.x,         camera_up.x,         -forward.x,       0,
			right.y,         camera_up.y,         -forward.y,       0,
			right.z,         camera_up.z,         -forward.z,       0,
			-right.dot(eye), -camera_up.dot(eye), forward.dot(eye), 1
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::ortho(T left, T right, T bottom, T top, T near, T far) {
		T x_delta = right - left;
		T y_delta = top - bottom;
		T z_delta = far - near;

		return basic_mat4<T>(
			2.0f / x_delta,            0.0f,                      0.0f,                    0.0f,
			0.0f,                      2.0f / y_delta,            0.0f,                    0.0f,
			0.0f,                      0.0f,                      -2.0f / z_delta,         0.0f,
			-(right + left) / x_delta, -(top + bottom) / y_delta, -(far + near) / z_delta, 1.0f
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::perspective(T fov, T aspect, T near, T far) {
		T tan_half_fov = std::tan(fov / T(2));

		return basic_mat4<T>(
			1 / (aspect * tan_half_fov), 0,                0,                                0,
			0,                           1 / tan_half_fov, 0,                                0,
			0,                           0,                -(far + near) / (far - near),     -1,
			0,                           0,                -(2 * far * near) / (far - near), 0
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::translated(const basic_vec3<T>& translation) {
		return basic_mat4<T>(
			1,             0,             0,             0,
			0,             1,             0,             0,
			0,             0,             1,             0,
			translation.x, translation.y, translation.z, 1
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::rotated(const basic_vec3<T>& axis, T angle) {
		basic_vec3<T> normalized_axis = axis.normalized();

		T cosinus = std::cos(angle);
		T sinus = std::sin(angle);
		T term = T(1) - cosinus;

		T x = normalized_axis.x, y = normalized_axis.y, z = normalized_axis.z;

		return basic_mat4<T>(
			term * x * x + cosinus,   term * x * y + z * sinus, term * x * z - y * sinus, 0,
			term * x * y - z * sinus, term * y * y + cosinus,   term * y * z + x * sinus, 0,
			term * x * z + y * sinus, term * y * z + x * sinus, term * z * z + cosinus,   0,
			0,                        0,                        0,                        1
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::rotated_x(T angle) {
		T cosinus = std::cos(angle);
		T sinus = std::sin(angle);

		return basic_mat4<T>(
			1, 0,       0,       0,
			0, cosinus, sinus,   0,
			0, -sinus,  cosinus, 0,
			0, 0,       0,       1
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::rotated_y(T angle) {
		T cosinus = std::cos(angle);
		T sinus = std::sin(angle);

		return basic_mat4<T>(
			cosinus, 0, -sinus,  0,
			0,       1, 0,       0,
			sinus,   0, cosinus, 0,
			0,       0, 0,       1
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::rotated_z(T angle) {
		T cosinus = std::cos(angle);
		T sinus = std::sin(angle);

		return basic_mat4<T>(
			cosinus, sinus,   0, 0,
			-sinus,  cosinus, 0, 0,
			0,       0,       1, 0,
			0,       0,       0, 1
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::scaled(const basic_vec3<T>& scale) {
		return basic_mat4<T>(
			scale.x, 0,       0,       0,
			0,       scale.y, 0,       0,
			0,       0,       scale.z, 0,
			0,       0,       0,       1
		);
	}

	template <typename T>
	basic_mat4<T>::basic_mat4(const basic_vec4<T>& x, const basic_vec4<T>& y, const basic_vec4<T>& z, const basic_vec4<T>& w)
		: x(x), y(y), z(z), w(w) { }

	template <typename T>
	basic_mat4<T>::basic_mat4(T xx, T xy, T xz, T xw, T yx, T yy, T yz, T yw, T zx, T zy, T zz, T zw, T wx, T wy, T wz, T ww)
		: x(xx, xy, xz, xw), y(yx, yy, yz, yw), z(zx, zy, zz, zw), w(wx, wy, wz, ww) { }

	template <typename T>
	T basic_mat4<T>::determinant() const {
		return
			x.x * (y.y * (z.z * w.w - z.w * w.z) - y.z * (z.y * w.w - z.w * w.y) + y.w * (z.y * w.z - z.z * w.y)) -
			x.y * (y.x * (z.z * w.w - z.w * w.z) - y.z * (z.x * w.w - z.w * w.x) + y.w * (z.x * w.z - z.z * w.x)) +
			x.z * (y.x * (z.y * w.w - z.w * w.y) - y.y * (z.x * w.w - z.w * w.x) + y.w * (z.x * w.y - z.y * w.x)) -
			x.w * (y.x * (z.y * w.z - z.z * w.y) - y.y * (z.x * w.z - z.z * w.x) + y.z * (z.x * w.y - z.y * w.x));
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::transpose() const {
		return basic_mat4<T>(
			x.x, y.x, z.x, w.x,
			x.y, y.y, z.y, w.y,
			x.z, y.z, z.z, w.z,
			x.w, y.w, z.w, w.w
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::inverse() const {
		T determinant = this->determinant();

		if (determinant == T(0)) {
			CITADEL_PANIC("Matrix is not invertible");
			return identity();
		}

		T inverted_determinant = T(1) / determinant;

		T determinant_z_w_zw_xz = z.z * w.w - z.w * w.z;
		T determinant_z_w_yz_yw = z.y * w.w - z.w * w.y;
		T determinant_z_w_yz_zw = z.y * w.z - z.z * w.y;
		T determinant_z_w_xz_ww = z.x * w.w - z.w * w.x;
		T determinant_z_w_xz_zw = z.x * w.z - z.z * w.x;
		T determinant_z_w_xy_yw = z.x * w.y - z.y * w.x;

		return basic_mat4<T>(
			y.y * determinant_z_w_zw_xz - y.z * determinant_z_w_yz_yw + y.w * determinant_z_w_yz_zw,
			-(x.y * determinant_z_w_zw_xz - x.z * determinant_z_w_yz_yw + x.w * determinant_z_w_yz_zw),
			x.y * (y.z * w.w - y.w * w.z) - x.z * (y.y * w.w - y.w * w.y) + x.w * (y.y * w.z - y.z * w.y),
			-(x.y * (y.z * z.w - y.w * z.z) - x.z * (y.y * z.w - y.w * z.y) + x.w * (y.y * z.z - y.z * z.y)),

			-(y.x * determinant_z_w_zw_xz - y.z * determinant_z_w_xz_ww + y.w * determinant_z_w_xz_zw),
			x.x * determinant_z_w_zw_xz - x.z * determinant_z_w_xz_ww + x.w * determinant_z_w_xz_zw,
			-(x.x * (y.z * w.w - y.w * w.z) - x.z * (y.x * w.w - y.w * w.x) + x.w * (y.x * w.z - y.z * w.x)),
			x.x * (y.z * z.w - y.w * z.z) - x.z * (y.x * z.w - y.w * z.x) + x.w * (y.x * z.z - y.z * z.x),

			y.x * determinant_z_w_yz_yw - y.y * determinant_z_w_xz_ww + y.w * determinant_z_w_xy_yw,
			-(x.x * determinant_z_w_yz_yw - x.y * determinant_z_w_xz_ww + x.w * determinant_z_w_xy_yw),
			x.x * (y.y * w.w - y.w * w.y) - x.y * (y.x * w.w - y.w * w.x) + x.w * (y.x * w.y - y.y * w.x),
			-(x.x * (y.y * z.w - y.w * z.y) - x.y * (y.x * z.w - y.w * z.x) + x.w * (y.x * z.y - y.y * z.x)),

			-(y.x * determinant_z_w_yz_zw - y.y * determinant_z_w_xz_zw + y.z * determinant_z_w_xy_yw),
			x.x * determinant_z_w_yz_zw - x.y * determinant_z_w_xz_zw + x.z * determinant_z_w_xy_yw,
			-(x.x * (y.y * w.z - y.z * w.y) - x.y * (y.x * w.z - y.z * w.x) + x.z * (y.x * w.y - y.y * w.x)),
			x.x * (y.y * z.z - y.z * z.y) - x.y * (y.x * z.z - y.z * z.x) + x.z * (y.x * z.y - y.y * z.x)
		) * inverted_determinant;
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::translate(const basic_vec3<T>& translation) const {
		return *this * translated(translation);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::rotate(const basic_vec3<T>& axis, T angle) const {
		return *this * rotated(axis, angle);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::rotate_x(T angle) const {
		return *this * rotated_x(angle);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::rotate_y(T angle) const {
		return *this * rotated_y(angle);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::rotate_z(T angle) const {
		return *this * rotated_z(angle);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::scale(const basic_vec3<T>& scale) const {
		return *this * scaled(scale);
	}

	template <typename T>
	T* basic_mat4<T>::data() noexcept {
		return x.data();
	}

	template <typename T>
	const T* basic_mat4<T>::data() const noexcept {
		return x.data();
	}

	template <typename T>
	const basic_vec4<T>& basic_mat4<T>::get_x() const noexcept {
		return x;
	}

	template <typename T>
	void basic_mat4<T>::set_x(const basic_vec4<T>& value) noexcept {
		x = value;
	}

	template <typename T>
	const basic_vec4<T>& basic_mat4<T>::get_y() const noexcept {
		return y;
	}

	template <typename T>
	void basic_mat4<T>::set_y(const basic_vec4<T>& value) noexcept {
		y = value;
	}

	template <typename T>
	const basic_vec4<T>& basic_mat4<T>::get_z() const noexcept {
		return z;
	}

	template <typename T>
	void basic_mat4<T>::set_z(const basic_vec4<T>& value) noexcept {
		z = value;
	}

	template <typename T>
	const basic_vec4<T>& basic_mat4<T>::get_w() const noexcept {
		return w;
	}

	template <typename T>
	void basic_mat4<T>::set_w(const basic_vec4<T>& value) noexcept {
		w = value;
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::operator+(const basic_mat4<T>& other) const {
		return basic_mat4<T>(
			x + other.x,
			y + other.y,
			z + other.z,
			w + other.w
		);
	}

	template <typename T>
	basic_mat4<T>& basic_mat4<T>::operator+=(const basic_mat4<T>& other) {
		*this = *this + other;
		return *this;
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::operator-(const basic_mat4<T>& other) const {
		return basic_mat4<T>(
			x - other.x,
			y - other.y,
			z - other.z,
			w - other.w
		);
	}

	template <typename T>
	basic_mat4<T>& basic_mat4<T>::operator-=(const basic_mat4<T>& other) {
		*this = *this - other;
		return *this;
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::operator*(const basic_mat4<T>& other) const {
		return basic_mat4<T>(
			x.x * other.x.x + y.x * other.x.y + z.x * other.x.z + w.x * other.x.w,
			x.y * other.x.x + y.y * other.x.y + z.y * other.x.z + w.y * other.x.w,
			x.z * other.x.x + y.z * other.x.y + z.z * other.x.z + w.z * other.x.w,
			x.w * other.x.x + y.w * other.x.y + z.w * other.x.z + w.w * other.x.w,

			x.x * other.y.x + y.x * other.y.y + z.x * other.y.z + w.x * other.y.w,
			x.y * other.y.x + y.y * other.y.y + z.y * other.y.z + w.y * other.y.w,
			x.z * other.y.x + y.z * other.y.y + z.z * other.y.z + w.z * other.y.w,
			x.w * other.y.x + y.w * other.y.y + z.w * other.y.z + w.w * other.y.w,

			x.x * other.z.x + y.x * other.z.y + z.x * other.z.z + w.x * other.z.w,
			x.y * other.z.x + y.y * other.z.y + z.y * other.z.z + w.y * other.z.w,
			x.z * other.z.x + y.z * other.z.y + z.z * other.z.z + w.z * other.z.w,
			x.w * other.z.x + y.w * other.z.y + z.w * other.z.z + w.w * other.z.w,

			x.x * other.w.x + y.x * other.w.y + z.x * other.w.z + w.x * other.w.w,
			x.y * other.w.x + y.y * other.w.y + z.y * other.w.z + w.y * other.w.w,
			x.z * other.w.x + y.z * other.w.y + z.z * other.w.z + w.z * other.w.w,
			x.w * other.w.x + y.w * other.w.y + z.w * other.w.z + w.w * other.w.w
		);
	}

	template <typename T>
	basic_mat4<T>& basic_mat4<T>::operator*=(const basic_mat4<T>& other) {
		*this = *this * other;
		return *this;
	}

	template <typename T>
	basic_vec4<T> basic_mat4<T>::operator*(const basic_vec4<T>& vector) const {
		return basic_vec4<T>(
			x.x * vector.x + y.x * vector.y + z.x * vector.z + w.x * vector.w,
			x.y * vector.x + y.y * vector.y + z.y * vector.z + w.y * vector.w,
			x.z * vector.x + y.z * vector.y + z.z * vector.z + w.z * vector.w,
			x.w * vector.x + y.w * vector.y + z.w * vector.z + w.w * vector.w
		);
	}

	template <typename T>
	basic_mat4<T> basic_mat4<T>::operator*(T scalar) const {
		return basic_mat4<T>(
			x * scalar,
			y * scalar,
			z * scalar,
			w * scalar
		);
	}

	template <typename T>
	basic_mat4<T>& basic_mat4<T>::operator*=(T scalar) {
		*this = *this * scalar;
		return *this;
	}
}
