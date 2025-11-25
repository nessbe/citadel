// File:       epsilon.inl
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
	bool epsilon_equal(T x, T y) noexcept {
		return std::abs(x - y) <= epsilon<T>::value;
	}

	template <typename T>
	bool epsilon_not_equal(T x, T y) noexcept {
		return std::abs(x - y) > epsilon<T>::value;
	}
}
