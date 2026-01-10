// File:       shader_data_type.cpp
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
#include "citadel/rendering/shaders/shader_data_type.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_UNREACHABLE_CODE)

	std::size_t shader_data_type_size(shader_data_type value) noexcept {
		switch (value) {
		case shader_data_type::type_bool:
			return sizeof(bool);

		case shader_data_type::type_int:
			return sizeof(int);

		case shader_data_type::type_ivec2:
			return sizeof(int) * 2;

		case shader_data_type::type_ivec3:
			return sizeof(int) * 3;

		case shader_data_type::type_ivec4:
			return sizeof(int) * 4;

		case shader_data_type::type_float:
			return sizeof(float);

		case shader_data_type::type_vec2:
			return sizeof(float) * 2;

		case shader_data_type::type_vec3:
			return sizeof(float) * 3;

		case shader_data_type::type_vec4:
			return sizeof(float) * 4;

		case shader_data_type::type_mat3:
			return sizeof(float) * 3 * 3;

		case shader_data_type::type_mat4:
			return sizeof(float) * 4 * 4;

		case shader_data_type::unknown:
		default:
			CITADEL_UNREACHABLE("Unknown shader data type: {0}", value);
			return 0;
		}
	}

	std::size_t shader_data_type_component_count(shader_data_type value) noexcept {
		switch (value) {
		case shader_data_type::type_bool:
			return 1;

		case shader_data_type::type_int:
			return 1;

		case shader_data_type::type_ivec2:
			return 2;

		case shader_data_type::type_ivec3:
			return 3;

		case shader_data_type::type_ivec4:
			return 4;

		case shader_data_type::type_float:
			return 1;

		case shader_data_type::type_vec2:
			return 2;

		case shader_data_type::type_vec3:
			return 3;

		case shader_data_type::type_vec4:
			return 4;

		case shader_data_type::type_mat3:
			return 3;

		case shader_data_type::type_mat4:
			return 4;

		case shader_data_type::unknown:
		default:
			CITADEL_UNREACHABLE("Unknown shader data type: {0}", value);
			return 0;
		}
	}

	GLenum shader_data_type_to_opengl(shader_data_type value) noexcept {
		switch (value) {
		case shader_data_type::type_bool:
			return GL_BOOL;

		case shader_data_type::type_int:
			return GL_INT;

		case shader_data_type::type_ivec2:
			return GL_INT;

		case shader_data_type::type_ivec3:
			return GL_INT;

		case shader_data_type::type_ivec4:
			return GL_INT;

		case shader_data_type::type_float:
			return GL_FLOAT;

		case shader_data_type::type_vec2:
			return GL_FLOAT;

		case shader_data_type::type_vec3:
			return GL_FLOAT;

		case shader_data_type::type_vec4:
			return GL_FLOAT;

		case shader_data_type::type_mat3:
			return GL_FLOAT;

		case shader_data_type::type_mat4:
			return GL_FLOAT;

		case shader_data_type::unknown:
		default:
			CITADEL_UNREACHABLE("Unknown shader data type: {0}", value);
			return 0;
		}
	}

	shader_data_type shader_data_type_from_opengl(GLenum value) noexcept {
		switch (value) {
		case GL_BOOL:
			return shader_data_type::type_bool;

		case GL_INT:
			return shader_data_type::type_int;

		case GL_INT_VEC2:
			return shader_data_type::type_ivec2;

		case GL_INT_VEC3:
			return shader_data_type::type_ivec3;

		case GL_INT_VEC4:
			return shader_data_type::type_ivec4;

		case GL_FLOAT:
			return shader_data_type::type_float;

		case GL_FLOAT_VEC2:
			return shader_data_type::type_vec2;

		case GL_FLOAT_VEC3:
			return shader_data_type::type_vec3;

		case GL_FLOAT_VEC4:
			return shader_data_type::type_vec4;

		case GL_FLOAT_MAT3:
			return shader_data_type::type_mat3;

		case GL_FLOAT_MAT4:
			return shader_data_type::type_mat4;

		case GL_SAMPLER_2D:
			return shader_data_type::type_int;

		default:
			CITADEL_UNREACHABLE("OpenGL shader data type {0} is not yet supported", value);
			return shader_data_type::unknown;
		}
	}

CITADEL_WARNING_IGNORE_POP

}
