// File:       texture_format_type.cpp
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

#include "citadel/pch.hpp"
#include "citadel/rendering/textures/texture_format_type.hpp"

namespace citadel {
	std::string texture_format_type_to_string(texture_format_type value) {
		switch (value) {
		case texture_format_type::internal:
			return "Internal";

		case texture_format_type::data:
			return "Data";

		default:
			CITADEL_UNREACHABLE("Unknown texture format type: {0}", value);
			return "Unknown";
		}
	}
}
