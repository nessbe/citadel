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

namespace citadel {
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
	basic_mat4<T>::basic_mat4(const basic_vec4<T>& x, const basic_vec4<T>& y, const basic_vec4<T>& z, const basic_vec4<T>& w)
		: x(x), y(y), z(z), w(w) { }

	template <typename T>
	basic_mat4<T>::basic_mat4(T xx, T xy, T xz, T xw, T yx, T yy, T yz, T yw, T zx, T zy, T zz, T zw, T wx, T wy, T wz, T ww)
		: x(xx, xy, xz, xw), y(yx, yy, yz, yw), z(zx, zy, zz, zw), w(wx, wy, wz, ww) { }

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
}
