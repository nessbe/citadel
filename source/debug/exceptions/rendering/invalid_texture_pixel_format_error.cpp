// File:       invalid_texture_pixel_format_error.cpp
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
#include "citadel/debug/exceptions/rendering/invalid_texture_pixel_format_error.hpp"

#include "citadel/rendering/textures/texture_format_type.hpp"

namespace citadel {
	invalid_texture_pixel_format_error::invalid_texture_pixel_format_error(unsigned int value, texture_format_type type)
		: exception(formatter::format("{0} texture format {1} is invalid", texture_format_type_to_string(type), value)) { }
}
