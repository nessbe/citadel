// File:       tga_header.hpp
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

#include "citadel/packing.hpp"

namespace citadel {
#pragma pack(push, 1)

	struct tga_header {
		std::uint8_t id_length;
		std::uint8_t map_type;
		std::uint8_t image_type;

		std::uint16_t map_origin;
		std::uint16_t map_length;
		std::uint8_t map_depth;

		std::uint16_t x_origin;
		std::uint16_t y_origin;

		std::uint16_t width;
		std::uint16_t height;

		std::uint8_t pixel_depth;
		std::uint8_t descriptor;
	};

#pragma pack(pop)

	static_assert(sizeof(tga_header) == 18, "tga_header must be 18 bytes");
}
