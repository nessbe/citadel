// File:       texture_2d.cpp
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
#include "citadel/rendering/textures/texture_2d.hpp"

#include "citadel/drivers/opengl/opengl_texture_2d.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_UNREACHABLE_CODE)

	scope<texture_2d> texture_2d::create(rendering_api_type api, const image& image) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_UNREACHABLE("Rendering API must not be none");
			return nullptr;

		case rendering_api_type::opengl:
			return make_scoped<opengl_texture_2d>(image);

		default:
			CITADEL_UNREACHABLE("Unknown rendering API: {0}", api);
			return nullptr;
		}
	}

CITADEL_WARNING_IGNORE_POP

	scope<texture_2d> texture_2d::create(const image& image) {
		return create(rendering_api_type::opengl, image);
	}

	texture_2d::texture_2d(const image& image)
		: texture(image) { }
}
