// File:       shader_type.cpp
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
#include "citadel/rendering/shaders/shader_type.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_UNREACHABLE_CODE)

	GLenum shader_type_to_opengl(shader_type value) noexcept
	{
		switch (value) {
		case shader_type::none:
			CITADEL_UNREACHABLE("Shader type must not be none");
			return 0;

		case shader_type::vertex:
			return GL_VERTEX_SHADER;

		case shader_type::fragment:
			return GL_FRAGMENT_SHADER;

		default:
			CITADEL_UNREACHABLE("Shader type {0} is not yet compatible with OpenGL");
			return 0;
		}
	}

CITADEL_WARNING_IGNORE_POP

}
