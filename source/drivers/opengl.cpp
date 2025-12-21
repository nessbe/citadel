// File:       opengl.cpp
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
#include "citadel/drivers/opengl.hpp"

namespace citadel {
	log_level opengl::debug_severity_to_log_level(GLenum value) {
		switch (value) {
		case GL_DEBUG_SEVERITY_NOTIFICATION:
			return log_level::trace;

		case GL_DEBUG_SEVERITY_LOW:
			return log_level::info;

		case GL_DEBUG_SEVERITY_MEDIUM:
			return log_level::warning;

		case GL_DEBUG_SEVERITY_HIGH:
			return log_level::error;

		default:
			CITADEL_PANIC("Unknown OpenGL debug severity");
			return log_level::debug;
		}
	}
}
