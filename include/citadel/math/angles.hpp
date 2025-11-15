// File:       angles.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	constexpr double pi = 3.141592653589793;
	constexpr double tau = 6.283185307179586;
	constexpr double half_pi = 1.5707963267948966;

	constexpr float full_circle = 360.0f;
	constexpr float half_circle = 180.0f;

	constexpr float degrees_to_radians = static_cast<float>(pi) / half_circle;
	constexpr float radians_to_degrees = half_circle / static_cast<float>(pi);

	nodisc api float radians(float degrees) noexcept;
	nodisc api float degrees(float radians) noexcept;
}
