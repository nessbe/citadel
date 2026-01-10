// File:       ansi_color_type.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
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

#include "citadel/export.hpp"

namespace citadel {
	enum class ansi_color_type : std::uint8_t {
		reset = 0,
		black = 30,
		red = 31,
		green = 32,
		yellow = 33,
		blue = 34,
		purple = 35,
		cyan = 36,
		white = 37,
	};

	CITADEL_API extern const std::uint8_t ansi_background_signature;
	CITADEL_API extern const std::uint8_t ansi_high_intensity_signature;
}
