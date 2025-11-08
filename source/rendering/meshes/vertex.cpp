// File:       vertex.cpp
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
#include "citadel/rendering/meshes/vertex.hpp"

namespace citadel {
	vertex::vertex(const vec2& position, const vec3& color)
		: position(position), color(color) { }

	const void* vertex::data() const noexcept {
		return static_cast<const void*>(this);
	}

	vec2 vertex::get_position() const noexcept {
		return position;
	}

	void vertex::set_position(const vec2& value) noexcept {
		position = value;
	}

	vec3 vertex::get_color() const noexcept {
		return color;
	}

	void vertex::set_color(const vec3& value) noexcept {
		color = value;
	}
}
