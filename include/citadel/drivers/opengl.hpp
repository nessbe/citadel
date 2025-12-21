// File:       opengl.hpp
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
	namespace opengl {
		nodisc exported log_level debug_severity_to_log_level(GLenum value);
	}
}
