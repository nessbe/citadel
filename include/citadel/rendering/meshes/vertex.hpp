// File:       vertex.hpp
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

#include <type_traits>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/math/vectors/vec2.hpp"

#include "citadel/rendering/color.hpp"

namespace citadel {
	struct api vertex {
	public:
		vec2 position;
		vec3 color;

	public:
		vertex(const vec2& position, const vec3& color);

		nodisc const void* data() const noexcept;

		nodisc vec2 get_position() const noexcept;
		void set_position(const vec2& value) noexcept;

		nodisc vec3 get_color() const noexcept;
		void set_color(const vec3& value) noexcept;
	};

	static_assert(std::is_trivially_copyable_v<vertex>, "Vertex struct is not trivially copyable");
	static_assert(std::is_standard_layout_v<vertex>, "Vertex struct layout is not standard");
}
