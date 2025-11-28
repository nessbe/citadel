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
#include "citadel/rendering/vertices/vertex.hpp"

namespace citadel {
	vertex::vertex(const vec3& position, const vec3& normal, const vec2& uv)
		: position(position), normal(normal), uv(uv) { }

	void* vertex::data() noexcept {
		return &position;
	}

	const void* vertex::data() const noexcept {
		return &position;
	}

	const vec3& vertex::get_position() const noexcept {
		return position;
	}

	void vertex::set_position(const vec3& value) noexcept {
		position = value;
	}

	const vec3& vertex::get_normal() const noexcept {
		return normal;
	}

	void vertex::set_normal(const vec3& value) noexcept {
		normal = value;
	}

	const vec2& vertex::get_uv() const noexcept {
		return uv;
	}

	void vertex::set_uv(const vec2& value) noexcept {
		uv = value;
	}
}
