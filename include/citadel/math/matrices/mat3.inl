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

namespace citadel {
	template <typename T>
	basic_mat3<T>::basic_mat3(const basic_vec3<T>& x, const basic_vec3<T>& y, const basic_vec3<T>& z)
		: x(x), y(y), z(z) { }

	template <typename T>
	basic_mat3<T>::basic_mat3(T xx, T xy, T xz, T yx, T yy, T yz, T zx, T zy, T zz)
		: x(xx, xy, xz), y(yx, yy, yz), z(zx, zy, zz) { }

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
}
