// File:       angles.cpp
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

#include "citadel/pch.hpp"
#include "citadel/math/angles.hpp"

namespace citadel {
	float radians(float degrees) noexcept {
		return degrees * degrees_to_radians;
	}

	float degrees(float radians) noexcept {
		return radians * radians_to_degrees;
	}
}
