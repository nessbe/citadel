// File:       shader_data_type.cpp
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
#include "citadel/rendering/shaders/shader_data_type.hpp"

namespace citadel {
	namespace shader_data_type {
CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE)

		std::size_t size(enumeration value) noexcept {
			switch (value) {
			case shader_data_type_bool:
				return sizeof(bool);

			case shader_data_type_int:
				return sizeof(int);

			case shader_data_type_ivec2:
				return sizeof(int) * 2;

			case shader_data_type_ivec3:
				return sizeof(int) * 3;

			case shader_data_type_ivec4:
				return sizeof(int) * 4;

			case shader_data_type_float:
				return sizeof(float);

			case shader_data_type_vec2:
				return sizeof(float) * 2;

			case shader_data_type_vec3:
				return sizeof(float) * 3;

			case shader_data_type_vec4:
				return sizeof(float) * 4;

			case shader_data_type_mat3:
				return sizeof(float) * 3 * 3;

			case shader_data_type_mat4:
				return sizeof(float) * 4 * 4;

			case shader_data_type_unknown:
			default:
				CITADEL_PANIC("Unknown shader data type");
				return 0;
			}
		}

		std::size_t component_count(enumeration value) noexcept {
			switch (value) {
			case shader_data_type_bool:
				return 1;

			case shader_data_type_int:
				return 1;

			case shader_data_type_ivec2:
				return 2;

			case shader_data_type_ivec3:
				return 3;

			case shader_data_type_ivec4:
				return 4;

			case shader_data_type_float:
				return 1;

			case shader_data_type_vec2:
				return 2;

			case shader_data_type_vec3:
				return 3;

			case shader_data_type_vec4:
				return 4;

			case shader_data_type_mat3:
				return 3;

			case shader_data_type_mat4:
				return 4;

			case shader_data_type_unknown:
			default:
				CITADEL_PANIC("Unknown shader data type");
				return 0;
			}
		}

		enumeration from_opengl(GLenum value) noexcept {
			switch (value) {
			case GL_BOOL:
				return shader_data_type_bool;

			case GL_INT:
				return shader_data_type_int;

			case GL_INT_VEC2:
				return shader_data_type_ivec2;

			case GL_INT_VEC3:
				return shader_data_type_ivec3;

			case GL_INT_VEC4:
				return shader_data_type_ivec4;

			case GL_FLOAT:
				return shader_data_type_float;

			case GL_FLOAT_VEC2:
				return shader_data_type_vec2;

			case GL_FLOAT_VEC3:
				return shader_data_type_vec3;

			case GL_FLOAT_VEC4:
				return shader_data_type_vec4;

			case GL_FLOAT_MAT3:
				return shader_data_type_mat3;

			case GL_FLOAT_MAT4:
				return shader_data_type_mat4;

			case shader_data_type_unknown:
			default:
				CITADEL_PANIC("The given OpenGL shader data type is not yet supported");
				return shader_data_type_unknown;
			}
		}

		GLenum to_opengl(enumeration value) noexcept {
			switch (value) {
			case shader_data_type_bool:
				return GL_BOOL;

			case shader_data_type_int:
				return GL_INT;

			case shader_data_type_ivec2:
				return GL_INT;

			case shader_data_type_ivec3:
				return GL_INT;

			case shader_data_type_ivec4:
				return GL_INT;

			case shader_data_type_float:
				return GL_FLOAT;

			case shader_data_type_vec2:
				return GL_FLOAT;

			case shader_data_type_vec3:
				return GL_FLOAT;

			case shader_data_type_vec4:
				return GL_FLOAT;

			case shader_data_type_mat3:
				return GL_FLOAT;

			case shader_data_type_mat4:
				return GL_FLOAT;

			case shader_data_type_unknown:
			default:
				CITADEL_PANIC("Unknown shader data type");
				return 0;
			}
		}

CITADEL_IGNORE_WARNING_POP()
	}
}
