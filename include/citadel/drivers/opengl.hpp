// File:       opengl.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/platforms.hpp"

#include "citadel/logging/log_level.hpp"

#if CITADEL_PLATFORM_WINDOWS
	#include "citadel/platforms/windows.hpp"
	#include <glad/glad_wgl.h>
#endif

#include <glad/glad.h>

namespace citadel {
	CITADEL_NODISCARD CITADEL_API GLint get_uniform_location(unsigned int program_id, const std::string& name);

	CITADEL_NODISCARD CITADEL_API log_level debug_severity_to_log_level(GLenum value);
}
