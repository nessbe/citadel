// File:       shader_data_type.hpp
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
#include <cstddef>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/drivers/opengl.hpp"

namespace citadel {
	enum shader_data_type_enumeration {
		shader_data_type_bool = 0,
		shader_data_type_int,
		shader_data_type_ivec2,
		shader_data_type_ivec3,
		shader_data_type_ivec4,
		shader_data_type_float,
		shader_data_type_vec2,
		shader_data_type_vec3,
		shader_data_type_vec4,
		shader_data_type_mat3,
		shader_data_type_mat4,
	};

	namespace shader_data_type {
		using type = std::uint8_t;
		using enumeration = shader_data_type_enumeration;

		nodisc exported std::size_t size(enumeration value) noexcept;
		nodisc exported std::size_t component_count(enumeration value) noexcept;
		nodisc exported GLenum to_opengl(enumeration value) noexcept;
	}
}
