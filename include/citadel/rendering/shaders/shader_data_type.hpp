// File:       shader_data_type.hpp
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
#include <cstddef>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/drivers/opengl.hpp"

namespace citadel {
	enum class shader_data_type : std::uint8_t {
		unknown = 0,
		type_bool,
		type_int,
		type_ivec2,
		type_ivec3,
		type_ivec4,
		type_float,
		type_vec2,
		type_vec3,
		type_vec4,
		type_mat3,
		type_mat4,
	};

	CITADEL_NODISCARD CITADEL_API std::size_t shader_data_type_size(shader_data_type value) noexcept;
	CITADEL_NODISCARD CITADEL_API std::size_t shader_data_type_component_count(shader_data_type value) noexcept;

	CITADEL_NODISCARD CITADEL_API GLenum shader_data_type_to_opengl(shader_data_type value) noexcept;
	CITADEL_NODISCARD CITADEL_API shader_data_type shader_data_type_from_opengl(GLenum value) noexcept;
}
