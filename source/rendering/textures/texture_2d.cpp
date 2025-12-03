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

namespace citadel {
	scope<texture_2d> texture_2d::create(rendering_api_type api, const image& image) {
		return nullptr;
	}

	scope<texture_2d> texture_2d::create(const image& image) {
		return create(rendering_api_type::opengl, image);
	}

	texture_2d::texture_2d(const image& image)
		: texture(image) { }
}
