// File:       shader_type.hpp
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

#include "citadel/drivers/opengl.hpp"

namespace citadel {
	enum class shader_type : std::uint8_t {
		none = 0,
		vertex,
		fragment,
	};

	nodisc exported GLenum shader_type_to_opengl(shader_type type) noexcept;
}
