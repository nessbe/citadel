// File:       ansi_color_mode.hpp
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

#include <cinttypes>

#include "citadel/utility.hpp"

namespace citadel {
	enum class ansi_color_mode : std::uint8_t {
		none = 0,
		background = CITADEL_BIT(0),
		high_intensity = CITADEL_BIT(1),
	};

	CITADEL_BITWISE_OPERATORS_WRAPPER(ansi_color_mode)
}
