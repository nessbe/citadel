// File:       texture_2d.cpp
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
#include "citadel/rendering/textures/texture_2d.hpp"

#include "citadel/drivers/opengl/opengl_texture_2d.hpp"

namespace citadel {
CITADEL_IGNORE_WARNING_PUSH();
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE);

	scope<texture_2d> texture_2d::create(rendering_api_type api, const image& image) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api_type::opengl:
			return make_scoped<opengl_texture_2d>(image);
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

CITADEL_IGNORE_WARNING_POP();

	scope<texture_2d> texture_2d::create(const image& image) {
		return create(rendering_api_type::opengl, image);
	}

	texture_2d::texture_2d(const image& image)
		: texture(image) { }
}
